import Control.Monad
import Data.List

main = do
    n <- getLine
    xs <- liftM (map read . words) getLine
    case solve xs of
        Just x -> print x
        Nothing -> putStrLn "none"

solve :: [Int] -> Maybe Int
solve xs = let uniqs = filter (\x -> length x == 1) 
                        $ groupBy (\a b -> fst a == fst b) 
                        $ reverse $ sort $ zip xs [1..]
            in case uniqs of 
                [] -> Nothing
                otherwise -> Just $ snd (head (head uniqs))
