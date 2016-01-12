import qualified Data.ByteString.Lazy.Char8 as L
import Control.Applicative
import Data.Maybe
import qualified Data.List as DL

groupInThrees :: [Int] -> [[Int]]
groupInThrees xs = let (hs, ts) = splitAt 3 xs
                    in if null ts
                          then if length hs == 3 then [hs] else []
                          else hs:groupInThrees ts

solve :: Int -> [Int] -> Int
solve n xs = let xsSorted = reverse $ DL.sort xs
              in sum $ map minimum $ groupInThrees xsSorted

readInt' = fst . fromJust . L.readInt

main = do (n:xs) <- map readInt' . L.words <$> L.getContents
          let ans = solve n xs
          print ans
