import Control.Monad

main = do
    xs <- liftM lines getContents
    let as = map toPigLatin xs
    mapM_ putStrLn as

toPigLatin = unwords . map f . words
    where
        f [] = []
        f xs@(x:_) | isVowel x = xs ++ "yay"
                 | otherwise = dropWhile (not . isVowel) xs ++ takeUntil isVowel xs ++ "ay"

isVowel :: Char -> Bool
isVowel c = c `elem` ['a', 'e', 'u', 'i', 'o', 'y']

takeUntil :: (a -> Bool) -> [a] -> [a]
takeUntil p [] = []
takeUntil p (x:xs)
    | p x = []
    | otherwise = x:takeUntil p xs
