import Control.Monad
import Data.List
import Text.Printf

data WinType = Majority | Minority
type Winner = (Int, WinType)

main = do t <- readLn
          replicateM_ t $ do
              n <- readLn
              votes <- replicateM n (readLn :: IO Int)
              case solve votes of
                Just (y, Majority) -> printf "majority winner %d\n" y
                Just (y, Minority) -> printf "minority winner %d\n" y
                _ -> putStrLn "no winner"


solve :: [Int] -> Maybe Winner
solve xs = let halfVotes = (sum xs) `div` 2
               votes = sort $ zip xs [1..]
               topTwo = take 2 $ reverse $ sort votes
            in case topTwo of
                 [(x, y)] -> Just (y, Majority)
                 ((x1, y1):(x2, y2):_) -> if x1 == x2
                                             then Nothing
                                             else if x1 > halfVotes then Just (y1, Majority) else Just (y1, Minority)
