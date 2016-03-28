import Control.Monad
import Data.Maybe

main = do
    [m, n] <- getNumbers
    [u, l, r, d] <- getNumbers
    crossword <- liftM lines getContents
    let emptyPadding = replicate n Nothing
        withUpperAndLowerPadding = replicate u emptyPadding ++
                                   map (map Just) crossword ++
                                   replicate d emptyPadding
        withFullPadding = map (\x -> replicate l Nothing ++ x) $
                          map (\x -> x ++ replicate r Nothing) withUpperAndLowerPadding
        row1 = take (n + l + r) $ cycle "#."
        row2 = take (n + l + r) $ cycle ".#"
        grid = take (m + u + d) $ cycle [row1, row2]
        crosswordOnGrid = combine withFullPadding grid

    mapM putStrLn crosswordOnGrid

getNumbers :: IO [Int]
getNumbers = liftM (map read . words) getLine

combine :: [[Maybe a]] -> [[a]] -> [[a]]
combine xs ys = map (\(a, b) -> zipWith (\x y -> maybe y id x) a b) $ zip xs ys
