import Control.Monad

main = do
    getLine --ignore
    ps <- liftM (map (read :: String -> Integer) . lines) getContents
    print $ solve ps

solve [] = 0
solve (x:xs) = (x `div` 10)^(x `mod` 10) + solve xs
