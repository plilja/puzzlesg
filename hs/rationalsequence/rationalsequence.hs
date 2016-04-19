import Control.Monad
import Data.List.Split
import Text.Printf

main = do
    t <- (readLn :: IO Int)
    forM_ [1..t] $ \i -> do
        [_, inp] <- liftM words getLine
        let [p, q] = map read $ splitOn "/" inp
            (p2, q2) = solve p q
        printf "%d %d/%d\n" i p2 q2

solve :: Integer -> Integer -> (Integer, Integer)
solve p q = let d = if p < q then 0 else p `div` q
                t = (p - d * q, q)
                (a, b) = goRight $ parent t
             in (a, b + d * q)

goRight (p, q) = (p + q, q)

parent (1, 1) = (1, 1)
parent (p, q) | p > q = (p - q, q)
              | otherwise = (p, q - p)
