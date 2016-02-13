import Control.Monad

main = do t <- readLn
          replicateM_ t $ do
              [n, x, y, w, h] <- fmap (map read . words) getLine
              let m = sylvester n x y w h
              forM_ m (putStrLn . unwords . map show)
              putStrLn ""

sylvester :: Integer -> Integer -> Integer -> Integer -> Integer -> [[Integer]]
sylvester n x y w h = [[point n x' y' | x' <- [x..x+w-1]] | y' <- [y..y+h-1]]

point 1 _ _ = 1
point n x y = let nextN = n `div` 2
                  nextX = if x < nextN then x else x - nextN
                  nextY = if y < nextN then y else y - nextN
                  sign = if x /= nextX && y /= nextY then -1 else 1
               in sign * point nextN nextX nextY
