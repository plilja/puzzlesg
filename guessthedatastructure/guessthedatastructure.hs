import Text.Printf
import Kattio
import Data.List

solve' :: [(Int, Int)] -> ([[Int]], [[Int]], [[Int]]) -> String
solve' _ ([], [], []) = "impossible"
solve' [] ([x], [], []) = "stack"
solve' [] ([], [x], []) = "priority queue"
solve' [] ([], [], [x]) = "queue"
solve' [] _ = "not sure"
solve' ((1, b):is) (xs, ys, zs) = let xs' = [b:hs | hs <- xs]
                                      ys' = [reverse (sort (b:hs)) | hs <- ys]
                                      zs' = [hs ++ [b] | hs <- zs]
                                  in solve' is (xs', ys', zs')
solve' ((2, b):is) (xs, ys, zs) = let xs' = [tail hs | hs <- xs, hs /= [], hs !! 0 == b]
                                      ys' = [tail hs | hs <- ys, hs /= [], hs !! 0 == b]
                                      zs' = [tail hs | hs <- zs, hs /= [], hs !! 0 == b]
                                  in solve' is (xs', ys', zs')

                              
solve :: [(Int, Int)] -> String
solve xs = solve' xs ([[]], [[]], [[]])

toPair' :: [Int] -> (Int, Int)
toPair' xs = (xs !! 0, xs !! 1) 

main = do i <- getIntOp
          case i of
              [] -> return ()
              _ -> do input <- mapM (\ x -> getInts 2) [1..(i !! 0)]
                      let inputPairs = map toPair' input
                      let ans = solve inputPairs
                      printf "%s\n" ans
                      main



