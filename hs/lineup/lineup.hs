import Control.Monad
import Data.List

main = do
    n <- readLn
    xs <- replicateM n getLine
    putStrLn $ solve xs

solve :: [String] -> String
solve xs 
    | sort xs == xs = "INCREASING"
    | reverse (sort xs) == xs = "DECREASING"
    | otherwise = "NEITHER"

