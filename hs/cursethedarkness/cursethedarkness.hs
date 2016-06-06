import Control.Monad

main = do
    t <- readLn
    replicateM_ t $ do
        book <- point
        n <- readLn
        points <- replicateM n point
        if solve book points
           then putStrLn "light a candle"
           else putStrLn "curse the darkness"

point :: IO (Double, Double)
point = do
    [x, y] <- fmap (map read . words) getLine
    return (x, y)

solve _ [] = False
solve (x, y) ((x', y'):ps) = let d = sqrt ((x - x')^2 + (y - y')^2)
                              in if d <= 8 + eps
                                    then True
                                    else solve (x, y) ps

eps = 1e-12
