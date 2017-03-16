import qualified Data.Time as D
import qualified Data.List as L
import qualified Data.Text as T
import qualified Data.Maybe as M

main = do
    xs <- getLine
    case solve xs of
        Just d -> putStrLn $ D.showGregorian d
        otherwise -> putStrLn $ xs ++ " is illegal"

solve :: String -> Maybe D.Day
solve xs = let ys = map read $ splitOn "/" xs
               validDates = M.catMaybes $ concat $ map toDates $ L.permutations ys
               validDatesInRange = filter (\d -> (d >= earliest) && (d <= latest)) validDates
            in M.listToMaybe $ take 1 $ L.sort validDatesInRange

toDates hs = let a = D.fromGregorianValid (toInteger (hs !! 0)) (hs !! 1) (hs !! 2)
                 b = D.fromGregorianValid (toInteger (2000 + hs !! 0)) (hs !! 1) (hs !! 2)
              in [a, b]

splitOn pattern str = map T.unpack $ T.splitOn (T.pack pattern) $ T.pack str

earliest = D.fromGregorian 2000 1 1

latest = D.fromGregorian 2999 12 31
