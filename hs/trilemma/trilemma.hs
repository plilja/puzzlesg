import Control.Monad
import Text.Printf
import Data.List 

type Point = (Double, Double)

main = do
    n <- readLn :: IO Int
    forM_ [1..n] $ \i -> do
        [x1, y1, x2, y2, x3, y3] <- liftM (map read . words) getLine
        if isTriangle (x1, y1) (x2, y2) (x3, y3)
        then do
            let a = lenClassify (x1, y1) (x2, y2) (x3, y3)
                b = angleClassify (x1, y1) (x2, y2) (x3, y3)
            printf "Case #%i: %s %s triangle\n" i a b
        else do
            printf "Case #%i: not a triangle\n" i

isTriangle :: Point -> Point -> Point -> Bool
isTriangle a b c = (0 < len a b) &&
                   (0 < len b c) &&
                   (0 < len c a) &&
                   (0 /= cross a b c) && 
                   (0 /= cross b c a) && 
                   (0 /= cross c a b) 

lenClassify :: Point -> Point -> Point -> String
lenClassify a b c = f $ length $ nub $ sort [sqLen a b, sqLen b c, sqLen c a]
    where
        sqLen (x1, y1) (x2, y2) = (x1 - x2)^2 + (y1 - y2)^2
        f 1 = "equilateral"
        f 2 = "isosceles"
        f 3 = "scalene"

angleClassify :: Point -> Point -> Point -> String
angleClassify a b c = f [angle a b c, angle b c a, angle c a b]
    where
        f xs | any (isEq 90.0) xs = "right"
             | any (90 <) xs = "obtuse"
             | otherwise = "acute"

len (x1, y1) (x2, y2) = sqrt $ (x1 - x2)^2 + (y1 - y2)^2

angle p1 p2 p3 = let a = len p1 p2 
                     b = len p2 p3
                     c = len p1 p3
                in 360 * (acos $ (a^2 + b^2 - c^2) / (2*a*b)) / (2 * pi)

cross (x1, y1) (x2, y2) (x3, y3) = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)

isEq x y = abs(x - y) < 1e-8
