import Kattio
import Control.Monad

findNewDirection :: Char -> Int -> Int -> (Int, Int)
findNewDirection c dx dy 
        | c == '/' = (-dy, -dx)
        | c == '\\' = (dy, dx)
        | otherwise = (dx, dy)


findExit :: Int -> Int -> Int -> Int -> [String] -> (Int, Int)
findExit x y dx dy room
        | c == 'x' = (x, y)
        | otherwise = findExit (x + newDx) (y + newDy) newDx newDy room
    where
        c = room !! y !! x
        (newDx, newDy) = findNewDirection c dx dy


solve :: Int -> Int -> [String] -> [String]
solve w l room = let (entranceX, entranceY) = head [(x, y) | x <- [0..w-1], y <- [0..l-1], '*' == room !! y !! x]
                     dx | entranceX == 0 = 1
                        | entranceX == w - 1 = -1
                        | otherwise = 0
                     dy | entranceY == 0 = 1
                        | entranceY == l - 1 = -1
                        | otherwise = 0
                     (exX, exY) = findExit entranceX entranceY dx dy room
                 in [room !! i | i <- [0..exY-1]] ++
                    [[room !! exY !! i | i <- [0..exX-1]] ++ ['&'] ++ [room !! exY !! i | i <- [exX+1..w-1]]] ++
                    [room !! i | i <- [exY+1..l-1]]
                 


run :: Int -> IO ()
run n = do [w, l] <- sequence [getInt, getInt]
           when (w /= 0 && l /= 0) $ do
              room <- getLinesN l
              let roomWithExit = solve w l room
              putStrLn $ "HOUSE " ++ show n
              mapM_ putStrLn roomWithExit
              run (n + 1)

main = run 1


