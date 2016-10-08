import Control.Monad
import Data.List

main = do
    xs <- liftM lines getContents
    let as = map solve xs
    mapM_ print as

solve :: String -> Integer
solve xs = let num = factorial $ toInteger $ length xs
               lengths = map toInteger $ map length $ group $ sort xs
               den = product $ map factorial $ lengths
            in num `div` den

factorial :: Integer -> Integer
factorial n = product [1..n]
