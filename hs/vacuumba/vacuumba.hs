import Kattio
import Text.Printf

type Point = (Double, Double)
type Angle = Double
type Dist = Double

radians degrees = 2 * degrees * pi / 360

determineFinalDest :: [(Angle, Dist)] -> Angle -> Point -> Point
determineFinalDest [] a p = p
determineFinalDest ((a', d):xs) a (x,y) = let newAngle = a + a'
                                              dx = d * (cos $ radians newAngle)
                                              dy = d * (sin $ radians newAngle)
                                          in determineFinalDest xs newAngle (x+dx, y+dy)

pairs :: [Double] -> [(Double, Double)]
pairs [] = []
pairs (x:y:xs) = (x,y):pairs xs

solve n = do m <- getInt
             inp <- sequence $ [getDouble | x <- [1..2*m]]
             let (x, y) = determineFinalDest (pairs inp) 90 (0,0)
             printf "%.6f %.6f\n" x y


main = do cases <- getInt
          mapM_ solve [1..cases]
