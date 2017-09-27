import Control.Monad
import Text.Printf

main = do
    p <- readLn
    replicateM_ p $ do
        [k, n] <- liftM (map read . words) getLine
        let s1 = solve 1 1 n
            s2 = solve 1 2 n
            s3 = solve 2 2 n
        printf "%d %d %d %d\n" k s1 s2 s3

solve :: Integer -> Integer -> Integer -> Integer
solve start d n | even n = (n `div` 2) * (2 * start + d * (n - 1))
                | otherwise = start + solve (start + d) d (n - 1)
