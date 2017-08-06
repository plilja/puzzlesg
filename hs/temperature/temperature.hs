import Control.Monad
import Text.Printf

main = do
    [x, y] <- liftM (map (read :: (String -> Double)) . words) getLine
    case (x, y) of
        (0, 1) -> putStrLn "ALL GOOD"
        (_, 1) -> putStrLn "IMPOSSIBLE"
        otherwise -> do
            let ans = -x / (y - 1)
            printf "%.9f\n" ans
