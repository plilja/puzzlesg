main = do
    inputs <- fmap (map (map read) . map words . lines) getContents
    let answers = map solve inputs
    mapM_ print answers

solve :: [Int] -> Int
solve xs = head $ filter (\x -> x == (sum xs) - x) xs
