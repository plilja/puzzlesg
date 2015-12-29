import Kattio
import GHC.Exts

solve' :: [(Int, Int)] -> Int
solve' [] = 0
solve' ((a,b):xs) = 1 + (solve' $ dropWhile (\(c,d) -> c <= b) xs)

solve :: [(Int, Int)] -> Int
solve minions = solve' $ sortWith snd minions

getPair = do a <- getInt
             b <- getInt
             return (a,b)

main = do n <- getInt
          minions <- sequence $ [getPair | x <- [1..n]]
          let r = solve minions
          print r
       
