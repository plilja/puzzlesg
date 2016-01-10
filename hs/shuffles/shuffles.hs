import Data.Maybe
import Data.Array.ST
import Data.Array.Unboxed
import qualified Data.ByteString.Lazy.Char8 as L
import Control.Applicative

createIdxLookup :: [Int] -> UArray Int Int
createIdxLookup xs = runSTUArray $ do
    let n = length xs
    arr <- newArray (0, n) 0
    mapM_ (\(x, idx) -> writeArray arr x idx) $ zip xs [1..]
    return arr


countSeq :: [Int] -> UArray Int Int -> Int -> Int
countSeq [] _ acc = acc + 1
countSeq (x:xs) idxLookup acc = let preIdx = idxLookup ! (x - 1)
                                    idx = idxLookup ! x
                                in if preIdx < idx
                                      then countSeq xs idxLookup acc
                                      else countSeq xs idxLookup (acc + 1)

solve :: [Int] -> Int
solve xs = let idxLookup = createIdxLookup xs
               numSeq = countSeq xs idxLookup 0
            in ceiling $ logBase 2 (fromIntegral numSeq)


main = do (_:inp) <- map (\x -> fst (fromJust (L.readInt x))) . L.words <$> L.getContents
          let r = solve inp
          putStrLn $ show r
