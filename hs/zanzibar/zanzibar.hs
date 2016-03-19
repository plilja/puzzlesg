import Control.Monad

main = do t <- readLn
          replicateM_ t $ do
              xs <- fmap (map read . init . words) getLine
              print $ solve xs

solve :: [Integer] -> Integer
solve xs = let yearDiffs = zip xs (tail xs)
               importsPerYear = map (\(a, b) -> max 0 (b - 2*a)) yearDiffs
            in sum importsPerYear
