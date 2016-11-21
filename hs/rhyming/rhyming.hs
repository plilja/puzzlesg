import Control.Monad

main = do
    common <- getLine
    e <- readLn
    endings <- liftM (map words) $ replicateM e getLine
    p <- readLn
    replicateM_ p $ do
        phrase <- liftM words getLine
        if rhymes (last phrase) common endings
            then putStrLn "YES"
            else putStrLn "NO"

rhymes :: String -> String -> [[String]] -> Bool
rhymes a b endings = f (reverse a) (reverse b) (map (map reverse) endings)
    where
        f a b [] = False
        f a b (es:ess) = (in_ a es && in_ b es) || f a b ess
        in_ s (es) = or (map (\e -> (take (length e)) s == e) es)
