import Control.Monad

main = do
    xs <- liftM (tail . lines) getContents
    mapM putStrLn (map solve xs)

solve :: String -> String
solve xs | (take 11 xs) == "simon says " = drop 11 xs
         | otherwise = ""
