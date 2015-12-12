import Data.Char
import Text.Printf
import Data.Set

getWord :: IO [Char]
getWord = do x <- getChar
             if isSpace x 
                 then return [] 
                 else do xs <- getWord
                         return (x:xs)

getInt :: IO Int
getInt = do x <- getWord
            return (read x :: Int)


getWords :: Int -> IO [[Char]]
getWords 0 = return []
getWords n = do x <- getWord
                xs <- getWords (n - 1)
                return (x:xs)


run :: Int -> IO ()
run 0 = return ()
run t = do n <- getInt
           cities <- getWords n
           let cities_set = fromList cities
           let n = size cities_set
           print n
           run (t - 1)


main = do t <- getInt
          run t


