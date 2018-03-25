main = interact solve

solve xs = let ws = words xs
               numWords = fromIntegral $ length ws
               numOstgotska = fromIntegral $ length $ filter ae ws
               proportion = numOstgotska / numWords
            in if proportion > 0.4 - 1e-9
                then "dae ae ju traeligt va\n"
                else "haer talar vi rikssvenska\n"
                

ae [] = False
ae (x:[]) = False
ae ('a':'e':_) = True
ae (_:xs) = ae xs
