import Control.Monad
import qualified Data.ByteString.Char8 as BS
import Data.Maybe

main = do
    xs <- liftM (map readInt . tail . BS.words) BS.getContents
    let as = solve xs
    print $ length as
    BS.putStrLn $ BS.pack $ unwords $ map show as

readInt :: BS.ByteString -> Int
readInt = fst . fromJust . BS.readInt

solve :: [Int] -> [Int]
solve xs = go (tail xs) [head xs]
    where
        go [] as = reverse as
        go (x:xs) as@(a:_)
            | x > a = go xs (x:as)
            | otherwise = go xs as
