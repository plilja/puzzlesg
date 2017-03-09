import Control.Monad
import Text.Printf

main = do
    inp <- liftM words getLine
    case inp of
        ["0", "0", "0", "0"] -> return ()
        [s0, s1, r0, r1] -> do
            let possP1Ranks = possRanks s0 s1
                possP2Ranks = possRanks r0 r1
                p1Wins = [1 | p1 <- possP1Ranks, p2 <- possP2Ranks, p1 > p2]
                (a, b) = reduceFraction (length p1Wins) ((length possP1Ranks) * (length possP2Ranks))
            case b of
                1 -> print a
                otherwise -> printf "%d/%d\n" a b
            main
            
possRanks :: String -> String -> [Int]
possRanks "*" "*" = [rank a b | a <- [1..6], b <- [1..6]]
possRanks "*" b = [rank a (read b) | a <- [1..6]]
possRanks a "*" = possRanks "*" a
possRanks a b = [rank (read a) (read b)]

rank :: Int -> Int -> Int
rank d1 d2 
    | d1 == 1 && d2 == 2 = 1000
    | d1 == 2 && d2 == 1 = 1000
    | d1 == d2 = 100 + d1
    | otherwise = 10 * (max d1 d2) + (min d1 d2)

reduceFraction :: Int -> Int -> (Int, Int)
reduceFraction a b = let g = gcd a b
                      in (a `div` g, b `div` g)
