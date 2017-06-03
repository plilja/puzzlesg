import Control.Monad
import Text.Printf
import Data.List

main = do
    c <- readLn :: IO Int
    forM_ [1..c] $ \i -> do
        xs <- liftM (map read . tail . words) getLine
        printf "Case #%d: %d\n" i (solve xs)

solve :: [Integer] -> Integer
solve xs = let diffs = [abs (a - b) | (a:ys) <- tails xs, b <- ys]
               t = foldl gcd (head diffs) (tail diffs)
            in (- head xs) `mod` t
