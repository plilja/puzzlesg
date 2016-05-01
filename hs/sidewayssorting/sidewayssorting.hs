import Control.Monad
import Data.List
import Data.Char
import Data.Ord

main = main' False

main' newLine = do
    [r, c] <- liftM (map read . words) getLine
    if r == 0 && c == 0
       then return()
       else do if newLine
                   then putStrLn ""
                   else return ()
               run r c

run :: Int -> Int -> IO ()
run r c = do
    xs1 <- replicateM r getLine
    let xs2 = transpose xs1
        xs3 = sortBy (comparing (map toLower)) xs2
        ans = transpose xs3
    mapM_ putStrLn ans
    main' True
