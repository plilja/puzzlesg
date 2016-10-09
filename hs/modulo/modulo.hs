import Control.Monad
import Data.List

main = do
    xs <- liftM (map read . lines) getContents
    print $ solve xs

solve :: [Int] -> Int
solve = length . nub . sort . map ((flip mod) 42)
