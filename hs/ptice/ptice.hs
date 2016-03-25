import Data.List

main = do
    getLine
    as <- getLine
    let (r, p) = solve as
    print r
    mapM_ putStrLn p

solve :: [Char] -> (Int, [String])
solve as = let results = reverse $ sort
                          [(result as (cycle ['A', 'B', 'C']), "Adrian"),
                           (result as (cycle ['B', 'A', 'B', 'C']), "Bruno"),
                           (result as (cycle ['C', 'C', 'A', 'A', 'B', 'B']), "Goran")]
               winners = head $ groupOn fst results
            in (fst (head winners), sort $ map snd winners)

result as bs = length $ filter (==True) $ zipWith (==) as bs

groupOn f xs = groupBy (\a1 a2 -> (f a1) == (f a2)) xs
