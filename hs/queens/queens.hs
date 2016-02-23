import Control.Monad
import qualified Data.Set as S

main = do n <- readLn
          qs <- replicateM n $ fmap (toPair . map read . words) getLine
          if solve n qs
             then putStrLn "CORRECT"
             else putStrLn "INCORRECT"

toPair [a, b] = (a, b)

solve :: Int -> [(Int, Int)] -> Bool
solve n qs = hasNColumns n qs &&
             hasNRows n qs &&
             hasNLeftDiag n qs &&
             hasNRightDiag n qs

hasNColumns n qs = hasN n qs columns
hasNRows n qs = hasN n qs rows
hasNLeftDiag n qs = hasN n qs leftDiags
hasNRightDiag n qs = hasN n qs rightDiags

hasN n qs f = (==n) $ S.size $ S.fromList $ f qs

columns = map fst
rows = map snd
leftDiags = map (\(a, b) -> (a - min a b, b - min a b))
rightDiags = map (\(a, b) -> (a - min a (7 - b), b + min a (7 - b)))
