import Control.Monad
import Data.List
import Text.Printf

main = do
    [_, code, guess] <- liftM words getLine
    let r = count (==True) $ zipWith (==) code guess
        s = calcSameColor code guess - r
    printf "%d %d\n" r s

count :: (a -> Bool) -> [a] -> Int
count p = length . filter p

calcSameColor :: String -> String -> Int
calcSameColor xs ys = go (sort xs) (sort ys)
   where
       go [] _ = 0
       go _ [] = 0
       go (x:xs) (y:ys) | x < y = go xs (y:ys)
                        | x == y = 1 + go xs ys
                        | otherwise = go (x:xs) ys
