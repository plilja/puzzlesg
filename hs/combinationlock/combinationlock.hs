import Control.Monad

main = do
    xs <- liftM (map read . words) getLine
    case xs of
        [0, 0, 0, 0] -> return ()
        [pos, a, b, c] -> do
            print $ solve pos a b c
            main

solve :: Int -> Int -> Int -> Int -> Int
solve pos a b c = 360 * 3 + go pos [a, b, c] (-1)
    where
        go _ [] _ = 0
        go pos (x:xs) delta 
            | pos == x = go pos xs (-delta)
            | otherwise = 9 + go ((pos + delta) `mod` 40) (x:xs) delta

    
