import Control.Monad
import Data.List

eps = 0.0000001

main = do
    ns <- getDoubles
    case ns of
      [0, 0, 0] -> return ()
      [nx, ny, w] -> do ls <- getDoubles
                        ss <- getDoubles
                        if solve nx ny w ls ss
                           then putStrLn "YES"
                           else putStrLn "NO"
                        main

getDoubles :: IO [Double]
getDoubles = liftM (map read . words) getLine

solve :: Double -> Double -> Double -> [Double] -> [Double] -> Bool
solve nx ny w ls ss = coversInterval (0, 75) ls w &&
                      coversInterval (0, 100) ss w

coversInterval :: (Double, Double) -> [Double] -> Double -> Bool
coversInterval (start, end) xs h = let cuts = sort $ map (\x -> (x - h/2, x + h/2)) xs
                                       firstGap = foldl (\acc (x, y) -> if x - eps < acc then max y acc else acc) start cuts
                                    in firstGap + eps > end

