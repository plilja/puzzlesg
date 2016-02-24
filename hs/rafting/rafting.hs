import Control.Monad
import Text.Printf

type Point = (Double, Double)
type Line = (Point, Point)

inf = 10000.0

main = do
    t <- readLn
    replicateM_ t $ do
        ni <- readLn
        inner <- replicateM ni readPoint
        no <- readLn
        outer <- replicateM no readPoint
        let r = solve inner outer
        printf "%.8f\n" r

readPoint :: IO Point
readPoint = do [x, y] <- fmap (map read . words) getLine
               return (x, y)

solve :: [Point] -> [Point] -> Double
solve inner outer = solve' inner (outer ++ [head outer])

solve' :: [Point] -> [Point] -> Double
solve' [] outer = inf
solve' (p:inner) outer = let segments = zip outer (tail outer)
                             d = minimum $ map (dist p) segments
                             r = d / 2
                          in min r (solve' inner outer)

dist :: Point -> Line -> Double
dist p (a, b) = let proj = project p (a, b)
                    norm = (sub proj p)
                 in sqrt $ dot norm norm

project :: Point -> Line -> Point
project p (a, b)
    | a == b = a
    | otherwise = let ap = sub p a
                      ab = sub b a
                      abSq = dot ab ab
                      t = (dot ap ab) / abSq
                   in if t < 0.0
                         then a
                         else if t > 1.0
                         then b
                         else add a (mulC ab t)

dot (x1, y1) (x2, y2) = x1*x2 + y1*y2
sub (x1, y1) (x2, y2) = (x1 - x2, y1 - y2)
add x (x2, y2) = sub x (-x2, -y2)
mulC (x, y) c = (c*x, c*y)
