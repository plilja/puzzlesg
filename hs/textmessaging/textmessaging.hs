import Control.Monad
import Data.List
import Text.Printf

main = do
    t <- readLn
    forM_ [1..t] $ \i -> do
        runOne i

runOne :: Int -> IO ()
runOne i = do
    [p, k, l] <- ints
    freq <- ints
    printf "Case #%d: %d\n" i (solve p k freq)

ints :: IO [Int]
ints = liftM (map read . words) getLine

solve :: Int -> Int -> [Int] -> Int
solve p k fs = let fsRev = reverse $ sort fs
                  in f p k 0 fsRev 0
                where
                    f :: Int -> Int -> Int -> [Int] -> Int -> Int
                    f p k i [] acc = acc
                    f p k i (x:xs) acc = f p k (i + 1) xs (acc + x*(1 + (i `div` k))) 
