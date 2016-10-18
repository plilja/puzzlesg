import Control.Monad
import Data.Maybe
import Data.List
import Text.Printf

main = do
    t <- readLn
    solve 1 t

solve :: Int -> Int -> IO ()
solve _ 0 = return ()
solve i t = do
    [num, source, target] <- liftM words getLine
    let ans = enc (dec num source 0) target
    printf "Case #%d: %s\n" i ans
    solve (i + 1) (t - 1)

dec :: String -> String -> Integer -> Integer
dec [] _ acc = acc
dec (x:xs) lang acc = let n = toInteger $ length lang
                          i = toInteger $ fromJust $ elemIndex x lang
                          newAcc = acc * n + i
                       in dec xs lang newAcc

enc :: Integer -> String -> String
enc 0 lang = [head lang]
enc x lang = f x lang
    where 
        f 0 lang = []
        f x lang = let n = toInteger $ length lang
                      in (f (x `div` n) lang) ++ [lang !! (fromIntegral (x `mod` n))]
