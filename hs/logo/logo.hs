import Control.Monad

type Command = (String, Double)

main = do
    t <- readLn
    replicateM_ t $ do
        n <- readLn
        commands <- replicateM n readCommand
        print $ solve commands (0, 0) (0, 0) 0

readCommand :: IO Command
readCommand = fmap (f . words) getLine
    where
        f [a, b] = (a, read b)

solve :: [Command] -> (Double, Double) -> (Double, Double) -> Double -> Integer
solve [] (xStart, yStart) (xEnd, yEnd) _ = round $ sqrt $ (xStart - xEnd)^2 + (yStart - yEnd)^2
solve (("fd", d):cs) (xStart, yStart) (xCurr, yCurr) angle = solve cs (xStart, yStart) (xCurr + d*cos (radians angle), yCurr + d*sin (radians angle)) angle
solve (("lt", d):cs) (xStart, yStart) (xCurr, yCurr) angle = solve cs (xStart, yStart) (xCurr, yCurr) (angle + d)
solve (("rt", d):cs) (xStart, yStart) (xCurr, yCurr) angle = solve cs (xStart, yStart) (xCurr, yCurr) (angle - d)
solve (("bk", d):cs) (xStart, yStart) (xCurr, yCurr) angle = solve (("fd", -d):cs) (xStart, yStart) (xCurr, yCurr) angle

radians a = 2 * pi * a / 360
