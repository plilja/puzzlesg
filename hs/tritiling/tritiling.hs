import Control.Monad

main = do
    xs <- liftM (map read . init . words) getContents
    mapM_ print $ map solve xs

solve :: Integer -> Integer
solve x | x < 0 = 0
        | x == 0 = 1
        | otherwise = 3 * solve (x - 2) + (sum $ map (\y -> 2 * solve (x - y)) $ takeWhile (<=x) [4,6..])
