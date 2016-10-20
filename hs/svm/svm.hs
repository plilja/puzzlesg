import Control.Monad
import Text.Printf
import Data.Either
import qualified Data.Text as T
import qualified Data.Text.IO as T
import qualified Data.Text.Read as T

main = do
    n <- getLine -- Ignore
    xs <- liftM (map readDouble . T.words) T.getLine
    qs <- liftM (map (map readDouble) . map T.words . T.lines) T.getContents
    let ws = init xs
        b = last xs
        as = map (svm ws b) qs
    mapM_ (printf "%.5f\n") as

readDouble :: T.Text -> Double
readDouble ts = either (\a -> 0.0) (\a -> fst a) $ T.double ts

svm :: [Double] -> Double -> [Double] -> Double
svm ws b xs = let dotProduct = sum $ zipWith (*) ws xs 
                  len = sqrt $ sum $ zipWith (*) ws ws
               in (dotProduct + b) / len
