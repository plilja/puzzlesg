import Control.Monad

main = do
    prices <- liftM (tail . map read . words) getContents
    print $ solve initialMoney 0 prices

initialMoney = 100

solve :: Integer -> Integer -> [Integer] -> Integer
solve money shares [p] = money + p * shares
solve money shares (p1:p2:ps)
    | p1 < p2 = let newShares = min 100000 (shares + money `div` p1)
                 in solve (money - p1 * (newShares - shares)) newShares (p2:ps)
    | otherwise = solve (money + p1 * shares) 0 (p2:ps)

