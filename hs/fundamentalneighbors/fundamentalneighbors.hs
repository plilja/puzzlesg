import Control.Monad
import qualified Data.ByteString.Char8 as BS
import Data.Maybe
import qualified Data.List as L

m = 46341 -- m ** 2 > 2**31

main = do
    inp <- liftM (map readInt . BS.lines) BS.getContents
    let primes = sieve m
        ans = map (\i -> (i, neighbour primes i)) inp
        output = unlines $ map (\(a, b) -> show a ++ " " ++ show b) ans
    BS.putStr (BS.pack output)

readInt :: BS.ByteString -> Int
readInt bs = fst $ fromJust $ BS.readInt bs

sieve n = 2:(sieve' [x | x <- [3,5..n]])

sieve' [] = []
sieve' (p:ns) = p:(sieve' [n | n <- ns, rem n p /= 0])

neighbour primes x = product $ map (\(a, b) -> b^a) $ primeFactorsMult primes x

primeFactorsMult :: [Int] -> Int -> [(Int, Int)]
primeFactorsMult primes n = let primeCandidates = takeWhile (<= (intSqrt n)) primes
                                primeFactors' = filter (\i -> rem n i == 0) primeCandidates
                                primeFactors = if primeFactors' == [] then [n] else primeFactors'
                             in map (\p -> (p, power n p)) primeFactors

power :: Int -> Int -> Int
power n p | n < p = 0
          | rem n p /= 0 = 0
          | otherwise = 1 + power (n `div` p) p

intSqrt :: Int -> Int
intSqrt n = floor $ sqrt $ fromIntegral n
