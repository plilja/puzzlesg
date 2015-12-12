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


readPairs :: Int -> IO [(Int, Int)]
readPairs 0 = return []
readPairs x = do x1 <- getInt
                 x2 <- getInt
                 xs <- readPairs (x - 1)
                 return ((x1,x2):xs)

solve :: [(Int, Int)] -> Int -> Int
solve [] _ = 0
solve ((x, y):xs) acc = (y - acc)*x + solve xs y


run = do i <- getInt
         case i of
             -1 -> return ()
             x -> do vals <- readPairs x
                     let r = solve vals 0
                     printf "%d miles\n" r
                     run

main = do run


