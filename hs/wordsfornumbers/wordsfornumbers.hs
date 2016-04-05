import Data.Char

main = do interact solve

solve :: String -> String
solve xs = let ls = lines xs
               ss = map solveLine ls
            in unlines $ zipWith capitalize ss ls

capitalize:: String -> String -> String
capitalize [] _ = []
capitalize (x:xs) (y:ys) | y `elem` ['0'..'9'] = toUpper x:xs
                         | otherwise = x:xs

solveLine:: String -> String
solveLine xs = solveLine' xs []

solveLine':: String -> String -> String
solveLine' [] acc = solveWord $ reverse acc
solveLine' (x:xs) acc
    | x == ' ' = solveWord (reverse acc) ++ " " ++ solveLine' xs []
    | x == '.' = solveWord (reverse acc) ++ "." ++ solveLine' xs []
    | otherwise = solveLine' xs (x:acc)

solveWord:: String -> String
solveWord ws | isNum ws = asWords (read ws)
             | otherwise = ws

isNum:: String -> Bool
isNum ws = any (`elem` ['0'..'9']) ws

asWords::Int -> String
asWords x | x < 20 = lessThanTwenty x
          | x `mod` 10 == 0 = tens (x `div` 10)
          | otherwise = tens (x `div` 10) ++ "-" ++ lessThanTwenty (x `mod` 10)


lessThanTwenty 0 = "zero"
lessThanTwenty 1 = "one"
lessThanTwenty 2 = "two"
lessThanTwenty 3 = "three"
lessThanTwenty 4 = "four"
lessThanTwenty 5 = "five"
lessThanTwenty 6 = "six"
lessThanTwenty 7 = "seven"
lessThanTwenty 8 = "eight"
lessThanTwenty 9 = "nine"
lessThanTwenty 10 = "ten"
lessThanTwenty 11 = "eleven"
lessThanTwenty 12 = "twelve"
lessThanTwenty 13 = "thirteen"
lessThanTwenty 14 = "fourteen"
lessThanTwenty 15 = "fifteen"
lessThanTwenty 16 = "sixteen"
lessThanTwenty 17 = "seventeen"
lessThanTwenty 18 = "eighteen"
lessThanTwenty 19 = "nineteen"

tens 2 = "twenty"
tens 3 = "thirty"
tens 4 = "forty"
tens 5 = "fifty"
tens 6 = "sixty"
tens 7 = "seventy"
tens 8 = "eighty"
tens 9 = "ninety"

