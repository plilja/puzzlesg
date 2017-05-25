import Control.Monad

main = do
    [x, y, z] <- liftM (map read . words) getLine
    mapM putStrLn $ solve x y z

solve :: Int -> Int -> Int -> [String]
solve x y z = 
    let xs = cycle $ (replicate (x - 1) "") ++ ["Fizz"]
        ys = cycle $ (replicate (y - 1) "") ++ ["Buzz"]
        zs = map show [1..z]
        combined = zipWith coalesce (zipWith (++) xs ys) zs
     in combined

coalesce a b 
    | null a = b
    | otherwise = a
