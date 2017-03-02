import Control.Monad

main = do
    xs <- liftM (map read . lines) getContents
    mapM_ print $ map solve xs

solve :: Int -> Int
solve 1 = 1
solve x = 2 * x - 2 
