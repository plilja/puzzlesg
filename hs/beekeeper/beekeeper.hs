import Control.Monad
import Data.List

main = do
    n <- readLn
    if n == 0
        then return ()
        else do
            xs <- replicateM n getLine
            putStrLn $ solve xs
            main

solve :: [String] -> String
solve xs = let rs = map (negate . rank) xs
            in snd $ head $ sort $ zip rs xs
    where
        rank [] = 0
        rank (x:[]) = 0
        rank (x1:x2:xs) | x1 == x2 && x1 `elem` vowels = 1 + rank (x2:xs)
                        | otherwise = rank (x2:xs)

vowels = "aeiouy"
