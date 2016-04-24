import Data.List

main = do interact run

run = unlines . map (solve . read) . lines

solve :: Integer -> String
solve x | perfectness x == 0 = show x ++ " perfect"
        | perfectness x <= 2 = show x ++ " almost perfect"
        | otherwise = show x ++ " not perfect"

perfectness x = abs $ (x -) $ sum $ allFactors x

allFactors n = nub $ sort $ filter (<n) $ combine p n
    where p = nub $ sort $ primeFactors n
          combine [] n = [1]
          combine (x:xs) n = let ys = combine xs n
                                 r = takeWhile (\x -> rem n x == 0) $ map (x^) $ [1..]
                              in concat [[y, i*y] | y <- ys, i <- r]

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
