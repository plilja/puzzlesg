import Control.Monad
import Text.Printf
import Data.List
import Data.Maybe

main = do
    p <- readLn
    replicateM p $ do
        [k, tmp] <- liftM words getLine
        let ns = init tmp
            check = last tmp
            as = solve ns check
        printf "%s %s\n" k as


solve :: String -> Char -> String
solve ns check = let valueNs = map (getValue . getDigit) ns
                  in if (getValue check) == computeCheck valueNs
                     then show (toDecimal valueNs)
                     else "Invalid"

computeCheck :: [Integer] -> Integer
computeCheck [d1, d2, d3, d4, d5, d6, d7, d8] 
    = (2*d1 + 4*d2 + 5*d3 + 7*d4 + 8*d5 + 10*d6 + 11*d7 + 13*d8) `mod` 27

toDecimal :: [Integer] -> Integer
toDecimal xs = go (reverse xs) 1
    where 
        go [] _ = 0
        go (x:xs) i = x*i + go xs (27*i)

getDigit 'B' = '8'
getDigit 'G' = 'C'
getDigit 'I' = '1'
getDigit 'O' = '0'
getDigit 'Q' = '0'
getDigit 'S' = '5'
getDigit 'U' = 'V'
getDigit 'Y' = 'V'
getDigit 'Z' = '2'
getDigit x = x

getValue x = toInteger $ fromJust $ elemIndex x "0123456789ACDEFHJKLMNPRTVWX"
