import Control.Monad

type Paintdrop = (Double, Double, Double, String)

eps = 1e-9

main = do
    c <- readLn
    replicateM_ c $ do
        n <- readLn
        ps <- replicateM n paintDrop
        m <- readLn
        replicateM m $ do
            [x, y] <- liftM (map read . words) getLine
            let c = color x y (reverse ps)
            putStrLn c

paintDrop :: IO Paintdrop
paintDrop = do
    [x', y', v', col] <- liftM words getLine
    let x = read x'
        y = read y'
        v = read v'
        r = sqrt $ v / pi
    return ((x, y, r, col))

color :: Double -> Double -> [Paintdrop] -> String 
color x y [] = "white" 
color x y ((px, py, pr, pcol):ps) 
    | (px - x)^2 + (py - y)^2 < pr^2 + eps = pcol
    | otherwise = color x y ps
