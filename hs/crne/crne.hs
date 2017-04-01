main = do
    n <- readLn
    print $ solve n

solve :: Integer -> Integer
solve n = let a = ceiling $ fromInteger n / 2
              b = floor $ fromInteger n / 2
           in (a + 1) * (b + 1)
