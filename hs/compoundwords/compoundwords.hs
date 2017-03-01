import Control.Monad
import Data.List

main = do
    inp <- liftM words getContents
    mapM_ putStrLn $ solve inp

solve :: [String] -> [String]
solve xs = let withIdx = zip xs [1..]
            in nub $ sort $ [a ++ b | (a, aIdx) <- withIdx, (b, bIdx) <- withIdx, aIdx /= bIdx] 
