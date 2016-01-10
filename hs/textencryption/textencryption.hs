import Control.Applicative
import Data.List
import Data.Ord
import Data.Char
import qualified Data.ByteString.Lazy.Char8 as L
import Data.Maybe

solve :: Int -> String -> String
solve n text = let textClean = map toUpper $ filter (not . isSpace) text
                   textLen = length textClean
                   (_, _, lettersAndPos) = foldl (\(i, j, acc) c -> if i + n < textLen then (i+n, j, (c,i):acc) else (j, j+1, (c,i):acc)) (0, 1, []) textClean
                in map fst $ sortBy (comparing snd) lettersAndPos

pairs [] = []
pairs [x] = []
pairs (x1:x2:xs) = (x1,x2):pairs xs

readInt' = fst . fromJust . L.readInt

main = do inp <- pairs . L.lines <$> L.getContents
          let ans = map (\(n, text) -> solve (readInt' n) (L.unpack text)) inp
          mapM_ (\x -> L.putStrLn (L.pack x)) ans
