import Control.Monad
import Data.List
import Text.Printf

main = do
    t <- readLn
    replicateM_ t $ do
        n <- readLn
        customers <- replicateM n (liftM (map read . tail . words) getLine)
        printf "%.10f\n" $ solve n customers

solve :: Int -> [[Integer]] -> Double
solve n cs = let timePerCustomer = map sum cs
                 waitingTimes = scanl (+) 0 $ sort timePerCustomer
              in (fromInteger (sum waitingTimes)) / (fromIntegral n)
