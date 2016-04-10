import Control.Monad
import qualified Data.ByteString.Char8 as BS
import Data.Maybe
import qualified Data.List as L

main = do
    inp <- liftM (map readInt . BS.lines) BS.getContents
    let ans = map (\i -> (i, neighbour i)) inp
    mapM (\(a, b) -> BS.putStrLn (BS.pack (show a ++ " " ++ show b))) ans

readInt :: BS.ByteString -> Integer
readInt bs = toInteger $ fst $ fromJust $ BS.readInt bs

neighbour x = product $ map (\(a, b) -> b^a) $ primeFactorsMult x

primeFactorsMult :: Integer -> [(Integer, Integer)]
primeFactorsMult = map (\xs -> (head xs, toInteger (length xs))) . L.group . primeFactors

intSqrt :: Integer -> Integer
intSqrt n = floor $ sqrt $ fromIntegral n

primeFactors' :: Integer -> Integer -> Integer -> [Integer]
primeFactors' s lim 1 = []
primeFactors' s lim n
    | s > lim = [n]
    | rem n s == 0 = let r = n `div` s
                    in s:primeFactors' s (intSqrt r) (r)
    | otherwise = primeFactors' (s+1) lim n

primeFactors :: Integer -> [Integer]
primeFactors n = primeFactors' 2 (floor (sqrt (fromIntegral n))) n
