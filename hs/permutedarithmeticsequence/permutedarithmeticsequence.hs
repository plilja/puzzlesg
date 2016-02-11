import Data.List
import Control.Monad

main = do t <- readLn
          replicateM_ t $ do
            (_:xs) <- fmap (map read . words) getLine
            putStrLn $ solve xs

solve :: [Int] -> String
solve xs | isArithmeticSeq xs = "arithmetic"
         | isArithmeticSeq (sort xs) = "permuted arithmetic"
         | otherwise = "non-arithmetic"

isArithmeticSeq xs = let diffs = nub $ zipWith (-) xs (tail xs)
                      in length diffs == 1
