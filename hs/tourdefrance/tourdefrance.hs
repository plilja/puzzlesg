import Text.Printf
import Kattio
import Data.List

pairs xs = zip xs (tail xs)

spread :: [Int] -> [Int] -> Float
spread fs rs = let driveRatios = [(fromIntegral y)/(fromIntegral x) | x <- fs, y <- rs]
                   sortedRatios = sort driveRatios
                   spreads = map (\ t -> (snd t)/(fst t)) (pairs sortedRatios)
               in maximum spreads

main = do f <- getInt
          case f of
              0 -> return ()
              _ -> do r <- getInt 
                      front <- getInts f
                      rear <- getInts r
                      let ans = spread front rear
                      printf "%.2f\n" ans
                      main


