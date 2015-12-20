import Text.Printf
import Kattio
import Data.List
import qualified Data.Set as Set                  

sieve' [] = []
sieve' (p:ns) = p:(sieve' [n | n <- ns, rem n p /= 0])

sieve n = Set.fromList (2:(sieve' [x | x <- [2..n], odd x]))

solutions n = [(x, n - x) | x <- Set.toList (sieve 32000), x <= n `div` 2, Set.member (n - x) (sieve 32000)]

solve :: IO ()
solve = do n <- getInt
           let sols = solutions n
           let numSols = length sols
           printf "%d has %d representation(s)\n" n numSols
           mapM (\ t -> printf "%d+%d\n" (fst t) (snd t)) sols
           printf "\n"

main = do cases <- getInt
          mapM (\x -> solve) [1..cases]


