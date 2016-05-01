import qualified Data.ByteString.Char8 as BS
import Control.Monad
import Data.Maybe

main = do
    is <- integers
    mapM_ BS.putStrLn $ map (BS.pack . show) $ run is

integers :: IO [Integer]
integers = liftM (map parseInteger . BS.words) BS.getContents

parseInteger = fst . fromJust . BS.readInteger

run :: [Integer] -> [Integer]
run [] = []
run (n:k:q:is) = let (qs, is') = splitAt (fromInteger (2*q)) is
                     ans = map (solve n k) (pairs qs)
                  in ans ++ run is'

pairs [] = []
pairs (a:b:xs) = (a,b):pairs xs

solve n k (from, to) | to > from = 1 + solve n k (from, parent n k to)
                     | to == from = 0
                     | otherwise = 1 + solve n k (parent n k from, to)

parent n k x = let (lev, m) = level k x
                   aft = m - x
                   prevM = m - k^(lev-1)
                in prevM - (aft `div` k)

level k x = go k x 1 1
   where
       go k x l m | x <= m = (l, m)
                  | otherwise = go k x (l+1) (m + k^l)

