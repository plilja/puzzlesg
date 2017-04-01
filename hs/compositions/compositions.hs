import Control.Monad
import Text.Printf
import Data.Array.ST
import Data.Array.Unboxed

main = do
    p <- readLn
    replicateM p $ do
        [c, n, m, k] <- liftM (map read . words) getLine
        printf "%d %d\n" c $ solve n m k

solve :: Int -> Int -> Int -> Int
solve n m k = (go n m k) ! n
    where
        go :: Int -> Int -> Int -> UArray Int Int
        go n m k = runSTUArray $ do
            arr <- newArray (0, n) 0
            writeArray arr 0 1
            forM_ [1..n] $ \i -> do
                let elements = filter (misses m k) [1..i]
                forM_ elements $ \j -> do
                    a <- readArray arr i
                    b <- readArray arr (i - j)
                    writeArray arr i (a + b)
            return arr

        misses :: Int -> Int -> Int -> Bool
        misses m k j = (j - m) `mod` k /= 0
