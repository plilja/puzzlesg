import Control.Monad
import Data.List

main = do
    run 0

run i = do
    n <- readLn
    if n == 0
       then return ()
       else do if i > 0
                  then putStrLn ""
                  else return ()
               runcase n
               run (i + 1)

runcase :: Int -> IO ()
runcase n = do
    tmp <- replicateM n getLine
    let longest = maximum (n:(map length tmp))
        tmp2 = map (rpad longest) tmp
        figure = take longest (tmp2 ++ repeat [])
        ans = rtrimEmpty $ map rtrim $ map reverse $ map (map replaceChar) $ transpose figure
    mapM_ putStrLn ans

replaceChar '|' = '-'
replaceChar '-' = '|'
replaceChar c = c

rpad n [] = replicate n ' '
rpad n (c:cs) = c:rpad (n - 1) cs

rtrim = reverse . dropWhile (==' ') . reverse

rtrimEmpty = reverse . dropWhile null . reverse
