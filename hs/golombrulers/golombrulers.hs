import qualified Data.Map as M

analyze :: [Int] -> ([Int], [Int])
analyze xs = let combs = [(x, y) | x <- xs, y <- xs, x < y]
                 m' = M.fromList $ zip [1..(maximum xs)] (repeat 0)
                 m = foldl (\acc -> \(x, y) -> M.insertWith (\a -> \b -> a + b) (y - x) 1 acc) m' combs
                 duplicate = map fst $ filter (\(x, y) -> y > 1) (M.assocs m)
                 missing = map fst $ filter (\(x, y) -> y == 0) (M.assocs m)
             in (duplicate, missing)


printList :: [Int] -> IO ()
printList [x] = putStrLn $ show x
printList (x:xs) = do putStr $ (show x) ++ " "
                      printList xs

solve :: [Int] -> IO ()
solve input = do let r = analyze input
                 case r of
                    ((x:xs), _) -> putStrLn "not a ruler"
                    ([], []) -> putStrLn "perfect"
                    ([], xs) -> do putStr "missing "
                                   printList xs

main = do contents <- getContents
          let input' = map words $ lines contents
          let input = map (\xs -> map (\x -> read x :: Int) xs) input'
          mapM solve input

