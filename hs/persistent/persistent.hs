import Control.Monad
import Data.Char 

main = do
    n <- readLn
    if n == -1
        then return ()
        else do
            putStrLn $ solve n
            main

solve :: Integer -> String
solve n | n < 10 = show $ 10 + n
        | otherwise = f n 9 ""
    where
        f n 1 acc | n == 1 = acc
                  | otherwise = "There is no such number."
        f n i acc | n `mod` i == 0 = f (n `div` i) i ((chr (ord '0' + (fromInteger i))):acc)
                  | otherwise = f n (i - 1) acc
