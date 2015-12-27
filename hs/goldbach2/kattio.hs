module Kattio where 

import Data.Char
import System.IO

getWord :: IO String
getWord = do done <- isEOF
             case done of
                  True -> return ""
                  _ -> do x <- getChar
                          if isSpace x 
                             then return [] 
                             else do xs <- getWord
                                     return (x:xs)


getIntOp :: IO [Int]
getIntOp = do x <- getWord
              if null x 
                 then return []
                 else return [(read x :: Int)]

getInt :: IO Int
getInt = do x <- getIntOp
            return (x !! 0)


getInts :: Int -> IO [Int]
getInts 0 = return []
getInts n = do x <- getInt
               xs <- getInts (n - 1)
               return (x:xs)
               
