import Control.Monad
import Data.List

main = interact (solve "")

solve acc xs 
    | sort (take 3 xs) == "BLR" = solve ('C':acc) (drop 3 xs)
    | head xs == 'R' = solve ('S':acc) (tail xs)
    | head xs == 'B' = solve ('K':acc) (tail xs)
    | head xs == 'L' = solve ('H':acc) (tail xs)
    | otherwise = reverse ('\n':acc)
