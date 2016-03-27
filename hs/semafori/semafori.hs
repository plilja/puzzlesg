import Control.Monad
import Data.List

type Light = (Int, Int, Int)

main = do
    [n, l] <- fmap (map read . words) getLine
    lights <- replicateM n (fmap (toLight . map read . words) getLine)
    print $ solve 0 0 l lights

toLight :: [Int] -> Light
toLight [d, r, g] = (d, r, g)

solve :: Int -> Int -> Int -> [Light] -> Int
solve x t l [] = t + l - x
solve x t l ((d, r, g):lights) = let t' = t + d - x
                                     gt = closestGreen t' r g
                                  in solve (d + 1) (gt + 1) l lights

closestGreen t r g = let c = t `mod` (r + g)
                      in if c < r
                            then t + (r-c)
                            else t
