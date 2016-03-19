main = do
    getLine
    xs <- getLine
    ys <- getLine
    t <- readLn
    putStrLn $ solve t xs ys

solve :: Int -> String -> String -> String
solve t xs ys = let initial = (reverse xs) ++ ys
                 in foldl (\acc i -> swap xs ys acc) initial [1..t]

swap :: String -> String -> String -> String
swap xs ys [] = []
swap xs ys [a] = [a]
swap xs ys (a1:a2:as) | a1 `elem` xs && a2 `elem` ys = a2:a1:swap xs ys as
                      | otherwise = a1:swap xs ys (a2:as)
