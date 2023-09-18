-- Get an element given the specific position. Example, list [1..10] 3

module ElementOnIndex where

elementAt :: [a] -> Int -> a
elementAt [] _ = error "Index out of bounds"
elementAt (x:xs) 1 = x
elementAt (x:xs) n
  | n < 1 = error "Index out of bounds"
  | otherwise = elementAt xs (n - 1)



    