import Control.Monad
import qualified Data.ByteString.Char8 as BS
import Data.Maybe

main = do
    (t:inp) <- liftM toInts BS.getContents
    let ans = run t inp
    mapM_ (\(a, b) -> putStrLn (show a ++ " " ++ show b)) ans

toInts :: BS.ByteString -> [Int]
toInts bs = map fst $ map (\w -> fromJust (BS.readInt w)) $ BS.words bs

run :: Int -> [Int] -> [(Int, Int)]
run 0 _ = []
run t inp = let ([l, n], inp') = splitAt 2 inp
                (ants, inp'') = splitAt n inp'
                ans = solve n l ants
             in ans:run (t - 1) inp''

solve n l ants = (findMin l ants, findMax l ants)

findMin l ants = maximum $ map (\a -> min a (l - a)) ants

findMax l ants = max (l - first) last
    where first = minimum ants
          last = maximum ants
