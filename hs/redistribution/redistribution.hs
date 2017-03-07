import Control.Monad
import Data.List

main = do
    n <- readLn
    rooms <- liftM (map read . words) getLine
    let largestRoom = maximum rooms
    if sum rooms - largestRoom >= largestRoom
        then putStrLn $ intercalate " " $ map (show . snd) $ reverse $ sort $ zip rooms [1..n]
        else putStrLn "impossible"
