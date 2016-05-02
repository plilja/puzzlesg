import Control.Monad
import Text.Printf

main = do
    [a, b] <- liftM (map read . words) getLine
    if a == 0 && b == 0
       then return ()
       else run a b

run a b = do
    let collA = (1:) $ reverse $ takeWhile (/=1) $ collatz a
        collB = (1:) $ reverse $ takeWhile (/=1) $ collatz b
        common = takeWhile (==True) $ zipWith (==) collA collB
        aSteps = (length collA) - (length common)
        bSteps = (length collB) - (length common)
        meeting = head $ drop aSteps (reverse collA)
    printf "%d needs %d steps, %d needs %d steps, they meet at %d\n" a aSteps b bSteps meeting
    main

collatz :: Int -> [Int]
collatz x | odd x = x:collatz (3*x + 1)
          | otherwise = x:collatz (x `div` 2)
