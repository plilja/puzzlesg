import Control.Applicative
import Data.Maybe

solve :: Int -> Int -> Maybe Int
solve h v = let radians = 2 * pi * (fromIntegral v) / 360
                verticalVelocity = sin radians
            in if verticalVelocity < 0
                  then Just $ floor $ -(fromIntegral h) / verticalVelocity
                  else Nothing

main = do (h:v:[]) <- map read . words <$> getContents
          let r = solve h v
          case r of
            Just x -> print x
            _ -> putStrLn "safe"
