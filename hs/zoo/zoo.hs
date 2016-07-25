import Control.Monad
import Data.List
import Data.Char

main = run 1

run i = do
    n <- readLn :: IO Int
    if n == 0
        then return ()
        else do
            animals <- replicateM n (liftM (last . words) getLine)
            let sorted = sort $ map (map toLower) animals
                grouped = group sorted
            putStrLn $ "List " ++ show i ++ ":"
            mapM_ (\xs -> putStrLn (head xs ++ " | " ++ show (length xs))) grouped
            run (i + 1)
