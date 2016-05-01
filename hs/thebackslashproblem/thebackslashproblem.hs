main = interact run

run = unlines . map solve . pairs . lines

pairs [] = []
pairs (a:b:xs) = (a,b):pairs xs

solve (a, xs) = let n = read a
                 in go n xs
    where
        go 0 xs = xs
        go n xs = go (n - 1) (escape xs)

escape [] = []
escape (c:xs) | c `elem` special = '\\':c:escape xs
              | otherwise = c:escape xs

special = ['!'..'*'] ++ ['[', ']'] ++ ['\\']
