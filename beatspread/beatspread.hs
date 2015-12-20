import Text.Printf
import Kattio
import Data.List

-- [1  1]  = [a]
-- [1 -1] = [b]
calcScores :: Int -> Int -> Maybe (Int, Int)
calcScores a b = let a' = fromIntegral a
                     b' = fromIntegral b
                     c  = round ((b' - a') / (-2 :: Double))
                     d  = a - c
                 in if c >= 0 && d >= 0 && c + d == a && d - c == b
                    then Just (d, c)
                    else Nothing

solve :: IO ()
solve = do a <- getInt
           b <- getInt
           let scores = calcScores a b
           case scores of
               Nothing -> printf "impossible\n"
               Just (a, b) -> do printf "%d %d\n" a b

main = do f <- getInt
          mapM (\ x -> solve) [1..f]


