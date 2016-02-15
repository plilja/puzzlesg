import Data.List
import Data.Ord

main = do xs <- fmap (map words . lines) getContents
          let sorted = sortBy (comparing reverse) xs
              firstNames = map (!! 0) sorted
              ans = map (firstNameOrFull firstNames) sorted
          mapM_ putStrLn $ ans

firstNameOrFull firstNames name
    | count firstNames (name !! 0) == 1 = name !! 0
    | otherwise = unwords name

count xs x = length $ filter (==x) xs

