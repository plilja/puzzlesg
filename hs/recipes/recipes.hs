import Control.Monad
import Text.Printf

data Ingredient = Ingredient {name :: String, amount ::Double, percentage :: Double}
type Recipe = [Ingredient]

main = do t <- (readLn :: IO Int)
          forM_ [1..t] $ \i -> do
              [r, p, d] <- fmap (map read . words) getLine
              recipeBef <- readRecipe r
              let recipeAft = convert recipeBef p d
              printf "Recipe # %d\n" i
              forM_ recipeAft (\ing -> printf "%s %.1f\n" (name ing) (amount ing))
              putStrLn "----------------------------------------"

readRecipe :: Int -> IO Recipe
readRecipe r = do asStrings <- replicateM r (fmap words getLine)
                  return (map (\[a, b, c] -> Ingredient a (read b) (read c)) asStrings)

convert :: Recipe -> Int -> Int -> Recipe
convert rs p d = let fact = (fromIntegral d) / (fromIntegral p)
                     main = head $ filter (\i -> 100 == percentage i) rs
                     mainW = fact * (amount main)
                  in map (\i -> withChangedAmount i (mainW * (percentage i) / 100)) rs

withChangedAmount ing amount = Ingredient (name ing) amount (percentage ing)
