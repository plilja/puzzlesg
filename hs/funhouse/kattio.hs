module Kattio where 

import Data.Char
import System.IO

getUntil :: (Char -> Bool) -> IO [String]
getUntil predicate = do done <- isEOF
                        case done of
                             True -> return []
                             _ -> do c <- getChar
                                     if predicate c
                                        then return [[]]
                                        else do xss <- getUntil predicate
                                                return [(c:xs) | xs <- xss]


getWordOp :: IO [String]
getWordOp = getUntil isSpace


getWord :: IO String
getWord = do x <- getWordOp
             return (x !! 0)


getIntOp :: IO [Int]
getIntOp = do xs <- getWordOp
              return (map (\x -> read x :: Int) xs)

getInt :: IO Int
getInt = do x <- getIntOp
            return (x !! 0)


getInts :: Int -> IO [Int]
getInts 0 = return []
getInts n = do x <- getInt
               xs <- getInts (n - 1)
               return (x:xs)
               

getLineOp :: IO [String]
getLineOp = getUntil (\ c -> c == '\n')


getLines :: IO [String]
getLines = do x <- getLineOp
              xs <- mapM (\ x' -> getLines) x
              return (x ++ (concat xs))


getLinesN :: Int -> IO [String]
getLinesN 0 = return []
getLinesN n = do [line] <- getLineOp
                 xs <- getLinesN (n - 1)
                 return (line:xs)
