import Control.Monad
import Text.Printf
import Data.List
import Data.Ord

main = do
    n <- readLn
    input <- replicateM n readInpLine
    printf "%.4f\n" $ solve input

readInpLine :: IO Double
readInpLine = do
    [_, x] <- liftM words getLine
    return (read x)

solve :: [Double] -> Double
solve xs = sum $ zipWith (*) (sortBy (comparing negate) xs) [1..]
