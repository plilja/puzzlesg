import Control.Monad

main = do
    [n, k] <- liftM (map read . words) getLine
    if 2^k >= n
        then putStrLn "Your wish is granted!"
        else putStrLn "You will become a flying monkey!"
