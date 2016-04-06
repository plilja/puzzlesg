import Control.Monad
import qualified Data.Map as M
import Data.Map ((!))
import Data.List.Split
import Data.List

main = do
    inp <- liftM (init . lines) getContents
    let output = solve inp M.empty
    mapM_ putStrLn output

solve :: [String] -> M.Map String Int -> [String]
solve [] vars = []
solve (x:xs) vars | '=' `elem` x = let [var, val] = splitOn " = " x
                                  in solve xs (M.insert var (read val) vars)
                  | otherwise = formatLine (words x) vars 0 []:solve xs vars

formatLine :: [String] -> M.Map String Int -> Int -> [String] -> String
formatLine [] vars initialSum acc
    | initialSum == 0 = unwords $ reverse $ intersperse "+" acc
    | null acc = show initialSum
    | otherwise = unwords $ (show initialSum):"+":(reverse $ intersperse "+" acc)
formatLine (x:xs) vars initialSum acc
    | isNum x = formatLine xs vars (initialSum + read x) acc
    | x == "+" = formatLine xs vars initialSum acc
    | M.member x vars = formatLine xs vars (initialSum + vars ! x) acc
    | otherwise = formatLine xs vars initialSum (x:acc)

isNum:: String -> Bool
isNum ws = any (`elem` ['0'..'9']) ws

