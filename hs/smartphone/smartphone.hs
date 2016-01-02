diff :: String -> String -> Int
diff [] s = length s
diff s [] = length s
diff (t:ts) (x:xs)
     | t == x = diff ts xs
     | otherwise = 2 + length ts + length xs

run [] = return ()
run (target:written:s1:s2:s3:xs) = do let y = diff target written
                                          ys = map (\xs -> 1 + diff target xs) [s1, s2, s3]
                                          ans = minimum (y:ys)
                                      putStrLn $ show ans
                                      run xs

main = do c <- getContents
          let (h:ls) = lines c
          run ls
