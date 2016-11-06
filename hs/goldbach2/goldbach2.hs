import Text.Printf
import Data.List
import Control.Monad
import qualified Data.Set as Set                  

sieve' [] = []
sieve' (p:ns) = p:(sieve' [n | n <- ns, rem n p /= 0])

sieve n = Set.fromList (2:(sieve' [x | x <- [2..n], odd x]))

sieve32000 = sieve 32000

solutions n = [(x, n - x) | x <- Set.toList sieve32000, x <= n `div` 2, Set.member (n - x) sieve32000]


solve :: IO ()
solve = do n <- readLn :: IO Int
           let sols = solutions n
           let numSols = length sols
           printf "%d has %d representation(s)\n" n numSols
           mapM_ (\t -> printf "%d+%d\n" (fst t) (snd t)) sols
           putStrLn ""

main = do cases <- readLn :: IO Int
          mapM (\x -> solve) [1..cases]
