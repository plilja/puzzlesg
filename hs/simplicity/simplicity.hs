import Data.List
import Data.Ord

main = do
    xs <- getLine
    print $ solve xs

solve :: String -> Int
solve = sum 
        . map length 
        . drop 2 
        . sortBy (comparing (negate . length)) 
        . group 
        . sort
