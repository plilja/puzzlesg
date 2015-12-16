import Data.Char
import Text.Printf
import Data.List

getWord :: IO String
getWord = do x <- getChar
             if isSpace x 
                 then return [] 
                 else do xs <- getWord
                         return (x:xs)

getInt :: IO Int
getInt = do x <- getWord
            return (read x :: Int)

getWords :: Int -> IO [String]
getWords 0 = return []
getWords n = do x <- getWord
                xs <- getWords (n - 1)
                return (x:xs)

everySecond :: [a] -> [a]
everySecond [] = []
everySecond (x:[]) = [x]
everySecond (x1:x2:xs) = x1:everySecond xs

cmp :: String -> String -> Ordering
cmp a b | lenA < lenB = LT
        | lenA == lenB = EQ
        | otherwise = GT
        where
           lenA = length a
           lenB = length b

solve :: [String] -> [String]
solve xs = 
      let sorted = sortBy cmp xs
          beginning = everySecond sorted
          ending = reverse (everySecond (tail sorted))
      in beginning ++ ending


run :: Int -> IO ()
run caseNr = do i <- getInt
                case i of
                    0 -> return ()
                    _ -> do words <- getWords i
                            let sorted = solve words
                            printf "SET %d\n" $ (caseNr)
                            mapM (\s -> printf "%s\n" $ s) sorted
                            run (caseNr + 1)

main = do run 1
