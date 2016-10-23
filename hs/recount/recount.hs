import Control.Monad
import Data.List
import Data.Ord

main = do
    votes <- liftM (init . lines) getContents
    let vs = sortBy (comparing (negate . length)) $ group $ sort votes
        ans = if length vs == 1 || length (vs !! 0) > length (vs !! 1)
                then vs !! 0 !! 0
                else "Runoff!"
    putStrLn ans
