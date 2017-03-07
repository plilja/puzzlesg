import Control.Monad

main = do
    inp <- readCase
    if null inp
        then return ()
        else do
            if isHonest inp [1..10]
                then putStrLn "Stan may be honest"
                else putStrLn "Stan is dishonest"
            main

readCase :: IO [(Int, String)]
readCase = do
    n <- readLn
    case n of
        0 -> return []
        _ -> do
            ans <- getLine
            case ans of
                "right on" -> return [(n, ans)]
                _ -> do
                    rest <- readCase
                    return ((n, ans):rest)


isHonest :: [(Int, String)] -> [Int] -> Bool
isHonest ((guess, "right on"):[]) poss = guess `elem` poss
isHonest ((guess, "too high"):xs) poss = isHonest xs (filter (< guess) poss)
isHonest ((guess, "too low"):xs) poss = isHonest xs (filter (> guess) poss)
