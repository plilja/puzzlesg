import Data.List

main = run 1

run i = do
    xs <- getLine
    case xs of
        "END" -> return ()
        _ -> do
            if even_ xs
                then putStrLn $ show i ++ " EVEN"
                else putStrLn $ show i ++ " NOT EVEN"
            run (i + 1)

even_ :: String -> Bool
even_ xs = 
    let idxs = elemIndices '*' xs
     in (<=1) $ length $ nub $ zipWith (-) idxs (tail idxs)
