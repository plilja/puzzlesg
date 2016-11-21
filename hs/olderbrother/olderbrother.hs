import Control.Monad

main = do
    q <- readLn
    if solve q
        then putStrLn "yes"
        else putStrLn "no"

solve :: Integer -> Bool
solve q = f q 1
    where
        f q i = let r = round $ (fromInteger q) ** (1 / (fromInteger i))
                    isSolution = ((r^i) == q) && isPrime r
                in isSolution || (r > 1 && f q (i + 1))

isPrime :: Integer -> Bool
isPrime 1 = False
isPrime n = let lim = floor $ sqrt (fromInteger n)
             in not $ any (\i -> n `mod` i == 0) [2..lim]
