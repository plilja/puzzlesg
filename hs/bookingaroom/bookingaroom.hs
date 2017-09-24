import Control.Monad
import Data.List

main = do
    [r, n] <- liftM (map read . words) getLine
    booked <- replicateM n readLn
    if length booked == r
        then putStrLn "too late"
        else print $ head $ [1..r] `except` booked

except :: [Int] -> [Int] -> [Int]
except rooms [] = rooms
except rooms (b:booked) = except (delete b rooms) booked
