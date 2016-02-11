import Data.Char
import Data.List

main = do xs <- fmap (lines . map toLower) getContents
          let ans = map (\x -> "problem" `contains` x) xs
          mapM_ putStrLn $ map output ans

output True = "yes"
output False = "no"

contains needle haystack = any (\xs -> needle == take (length needle) xs) (tails haystack)
