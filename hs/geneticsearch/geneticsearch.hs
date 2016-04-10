import Control.Monad
import Text.Printf
import Data.List

main = do
    ls <- liftM (init . lines) getContents
    let as = map (uncurry (flip solve)) (map pairs ls)
    mapM_ (\(a, b, c) -> printf "%d %d %d\n" a b c) as

pairs :: String -> (String, String)
pairs xs = let [a, b] = words xs
            in (a, b)

solve :: String -> String -> (Int, Int, Int)
solve ys xs = (type1 ys xs, type2 ys xs, type3 ys xs)

type1 ys xs = numMatches ys xs

type2 ys xs = sum $ map (numMatches ys) $ deleteOne xs

type3 ys xs = sum $ map (numMatches ys) $ insertOne xs

numMatches ys xs = length $ filter (startsWith xs) $ tails ys

startsWith [] _ = True
startsWith _ [] = False
startsWith (x:xs) (y:ys) | x == y = startsWith xs ys
                         | otherwise = False

deleteOne ys = nub $ sort $ [take (n-1) ys ++ drop n ys | n <- [1..length ys]]

insertOne ys = nub $ sort $ [take n ys ++ a ++ drop n ys | n <- [0..length ys], a <- ["A", "G", "C", "T"]]
