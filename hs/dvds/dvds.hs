import Control.Monad
import qualified Data.ByteString.Lazy.Char8 as L
import Data.Maybe

main = do
    (_:ls) <- liftM L.lines L.getContents
    let inp = map snd $ pairs ls
        ans = map (solve . toInts) inp
    mapM print ans

toInts xs = map (\x -> fst (fromJust (L.readInt x))) $ L.words xs

pairs [] = []
pairs (x:y:xs) = (x, y):pairs xs

solve :: [Int] -> Int
solve xs = let n = length xs
            in go xs n 1
    where
        go xs y x | null xs = y
                  | head xs == x = go (tail xs) (y - 1) (x + 1)
                  | otherwise = go (tail xs) y x
