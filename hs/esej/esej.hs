import Control.Monad
import qualified Data.ByteString.Char8 as BS

main = do [a, b] <- liftM (map read . words) getLine
          BS.putStrLn $ BS.pack $ essay a b

essay a b = unwords $ take numWords vocabulary
    where
        numWords = max a ((b + 1) `div` 2)

vocabulary = wordsOfLen 4

wordsOfLen 0 = [""]
wordsOfLen len = [c:w | w <- wordsOfLen (len - 1), c <- letters]

letters = ['a'..'z']
