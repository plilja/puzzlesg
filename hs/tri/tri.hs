import Data.Char
import Text.Printf

getWord :: IO [Char]
getWord = do x <- getChar
             if isSpace x 
                 then return [] 
                 else do xs <- getWord
                         return (x:xs)

getInt :: IO Int
getInt = do x <- getWord
            return (read x :: Int)


data Op = Add | Mul | Div | Sub | Eqs deriving (Show, Eq)

data Expr = Expr Int Op Int Op Int deriving Show

applyOp :: Int -> Op -> Int -> Int
applyOp x Add y = x + y
applyOp x Sub y = x - y
applyOp x Mul y = x * y
applyOp x Div 0 = 1000
applyOp x Div y = x `div` y


eval :: Expr -> Bool
eval (Expr x op y Eqs z) = applyOp x op y == z
eval (Expr x Eqs y op z) = x == applyOp y op z
eval (Expr _ _ _ _ _) = False

choices :: [[Op]]
choices = let ops = [Add, Mul, Div, Sub, Eqs]
          in [[x1, x2] | x1 <- ops, x2 <- ops, (x1 == Eqs || x2 == Eqs) && x1 /= x2]

toC :: Op -> Char
toC Add = '+'
toC Eqs = '='
toC Div = '/'
toC Mul = '*'
toC Sub = '-'

toChars :: Expr -> (Char, Char)
toChars (Expr _ op1 _ op2 _) = (toC op1, toC op2)

solve :: Int -> Int -> Int -> (Char, Char)
solve a b c = let choices' = choices 
                  expressions = map (\choice -> Expr a (choice !! 0) b (choice !! 1) c) choices'
                  allSolutions = filter (\expr -> eval expr == True) expressions
                  firstSol = head allSolutions
              in toChars firstSol


main = do a <- getInt
          b <- getInt
          c <- getInt
          let ans = solve a b c
          printf "%d%c%d%c%d\n" a (fst ans) b (snd ans) c
