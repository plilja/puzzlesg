import Control.Monad
import Text.Printf
import Data.List

main = do
    (n, g) <- pair
    xs <- replicateM n pair
    let as = map (solve g) (init (tails xs))
    mapM (\a -> printf "%.6f\n" a) as

pair :: Read a => Read b => IO (a, b)
pair = do
    [a, b] <- liftM words getLine
    return (read a, read b)
    
solve :: Double -> [(Double, Double)] -> Double
solve g xs = f g xs 0 
    where
        f g [] v = v
        f g ((d, theta):xs) v = let a = g * cos (degreesToRadians theta)
                                    vEnd = sqrt (v^2 + 2 * a * d) 
                                 in f g xs vEnd

degreesToRadians r = 2 * pi * r / 360
