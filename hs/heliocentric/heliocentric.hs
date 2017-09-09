import Control.Monad
import Text.Printf

main = do
    xs <- liftM (map (map read) . map words . lines) getContents
    let as = map (\[e, m] -> solve e m) xs
    mapM (\i -> printf "Case %d: %d\n" (i + 1) (as !! i)) [0..length as - 1]

solve :: Integer -> Integer -> Integer
solve e m = go e m 0
    where
        go e m acc | (e == 0 && m == 0) = acc
                   | otherwise = go ((e + 1) `mod` 365) ((m + 1) `mod` 687) (acc + 1)
