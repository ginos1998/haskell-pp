module RevertList where

    list :: [a] -> [a] 
    list [] = []
    list [x] = [x] 
    list (x:xs) = (list xs) ++ [x] 