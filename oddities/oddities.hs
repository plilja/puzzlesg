import Data.Char
import Text.Printf

getWord :: IO [Char]
getWord = do x <- getChar
             if isSpace x 
                 then return [] 
                 else do xs <- getWord
                         return (x:xs)

getInt :: IO Int
getInt = do x <- getWord
            return (read x :: Int)

solve n = do if n == 0
             then return ()
             else do i <- getInt
                     if odd i 
                     then printf "%d is odd\n" $ i
                     else printf "%d is even\n" $ i
                     solve (n - 1)

main = do i <- getInt
          solve i
