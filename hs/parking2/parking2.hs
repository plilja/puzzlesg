import Control.Applicative

solve xs = 2 * (maximum xs - minimum xs)

divide [] = []
divide (x:xs) = let (positions, xs') = splitAt x xs
                 in positions:divide xs'

main = do (_:numbers) <- map (\x -> read x :: Int) . words <$> getContents
          let inp = divide numbers
          let answers = map solve inp
          mapM_ print answers

