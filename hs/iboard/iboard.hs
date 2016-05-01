import Data.Char
import Data.Bits

main = interact run

run = unlines . map solve . lines

solve :: String -> String
solve xs = go False False $ concat $ toBin xs
    where
        go False False [] = "free"
        go _ _ [] = "trapped"
        go zero one (True:bs) = go zero (not one) bs
        go zero one (False:bs) = go (not zero) one bs

toBin = map decToBin . map ord

decToBin x = map (\i -> testBit x i) [0..6]
