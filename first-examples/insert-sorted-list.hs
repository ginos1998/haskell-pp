-- definir una funcion insert que va de un elemento y una lista ordenada 
-- a una lista ordenada que incluye ese elemento
-- ejemplo: 2 [1,6,8] -> Rtdo: [1,2,6,8]

module InsertSortedList where

    insert :: Int -> [Int] -> [Int]
    insert n [] = [n]
    insert n (x:xs) | x < n = x : insert n xs
                    | otherwise = n : x : xs

-- 
  
    isort :: [Int] -> [Int]
    isort [] = []
    isort (x:xs) = insert x (isort xs) 