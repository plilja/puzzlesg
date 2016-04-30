import Control.Monad
import Data.Maybe

main = do n <- readLn
          let t1 = solve n
              t2 = fmap unlines t1
              as = fromMaybe "impossible\n" t2
          putStr as

solve :: Int -> Maybe [String]
solve n = listToMaybe $ go 3 n []
    where
        go :: Int -> Int -> [String] -> [[String]]
        go y 0 acc = [acc]
        go 0 x acc = []
        go i n acc = let ps = filter (\(a, b) -> b<=n) $
                                     zip (zipWith (\a b -> (a ++ " " ++ show b)) (repeat "single") [1..20]) [1..20] ++
                                     zip (zipWith (\a b -> (a ++ " " ++ show b)) (repeat "double") [1..20]) [2,4..40] ++
                                     zip (zipWith (\a b -> (a ++ " " ++ show b)) (repeat "triple") [1..20]) [3,6..60]
                         in concat $ map (\(a, b) -> go (i - 1) (n - b) (a:acc)) ps

