main = do
    n <- readLn
    m <- readLn
    let (a, b) = solve n m
    putStrLn a
    putStrLn b

solve :: Integer -> Integer -> (String, String)
solve n m = (f n m, f m n)
    where
        f n m = let ns = show n
                    ms = show m
                    t = max (length ns) (length ms)
                    ns' = leftPad ns t
                    ms' = leftPad ms t
                    a = collide ns' ms' []
                 in if a == ""
                       then "YODA"
                       else a

leftPad xs n = reverse $ take n $ (reverse xs) ++ (repeat '0')

collide [] [] [] = []
collide [] [] acc = show $ (read :: String -> Integer) (reverse acc) -- compress consecutive zeros
collide (x:xs) (y:ys) acc | x >= y = collide xs ys (x:acc)
                          | otherwise = collide xs ys acc

