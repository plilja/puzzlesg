import Control.Monad

main = do
    inp <- liftM (map read . words) getLine
    case inp of
        [0, 0, 0, 0] -> return ()
        [s0, s1, r0, r1] -> do
            let p1Score = rank s0 s1
                p2Score = rank r0 r1
            case signum (p1Score - p2Score) of
                -1 -> putStrLn "Player 2 wins."
                0 -> putStrLn "Tie."
                otherwise -> putStrLn "Player 1 wins."
            main
            
rank :: Int -> Int -> Int
rank d1 d2 
    | d1 == 1 && d2 == 2 = 1000
    | d1 == 2 && d2 == 1 = 1000
    | d1 == d2 = 100 + d1
    | otherwise = 10 * (max d1 d2) + (min d1 d2)
