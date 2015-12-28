import Kattio
import Text.Printf

main = do a <- getInteger
          let side = sqrt (fromIntegral a :: Double)
          let r = 4 * side
          printf "%.6f\n" r
