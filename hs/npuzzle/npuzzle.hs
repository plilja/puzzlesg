import Control.Monad
import Data.Char

main = do puzzle <- replicateM 4 getLine
          print $ solve puzzle 0 0

solve :: [String] -> Int -> Int -> Int
solve [] _ _ = 0
solve ([]:xss) x y = solve xss (x-4) (y+1)
solve (('.':xs):xss) x y = solve (xs:xss) (x+1) y
solve ((v:xs):xss) x y = let p = ord v - ord 'A'
                             targetX = p `mod` 4
                             targetY = p `div` 4
                          in abs (targetX - x) + abs (targetY - y) + solve (xs:xss) (x+1) y
