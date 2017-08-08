import Control.Monad

main = do
    [h, w, n] <- ints
    xs <- ints
    if solve h w xs
    then putStrLn "YES"
    else putStrLn "NO"

ints :: IO [Int]
ints = liftM (map read . words) getLine

solve h w xs = go h w xs
    where
        go 0 _ _ = True
        go remH 0 ys = go (remH - 1) w ys
        go _ _ [] = False
        go remH remW (y:ys)
            | y <= remW = go remH (remW - y) ys
            | otherwise = False
