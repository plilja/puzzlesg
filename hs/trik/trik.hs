import Data.Maybe
import Data.List

main = interact solve

solve xs = let r = fromJust $ elemIndex True $ foldl swap [True, False, False] xs
            in (show (r + 1)) ++ "\n"

swap [a, b, c] 'A' = [b, a, c]
swap [a, b, c] 'B' = [a, c, b]
swap [a, b, c] 'C' = [c, b, a]
swap xs _ = xs
