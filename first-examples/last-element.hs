module LastElement where

    myLast :: [a] -> a 
    myLast [] = error "couldn't get last element: empty list"
    myLast [x] = x
    myLast (_:xs) = myLast xs

{- try: ghci last-element.hs
ghci> myLast [2,5,3,6,3,2,6,8]
ghci> myLast ['a','b','z','q']
ghci> myLast ['a','b','z', 1]
ghci> myLast [1.. 10]
ghci> myLast (take 5 [10..])
-}

---- Last -1 -------------------------------------------------------------------------------------------
    beforeLast :: [a] -> a 
    beforeLast [] = error "couldn't get the element: empty list"
    beforeLast [_] = error "couldn't get the element: list size 1"
    beforeLast [x,_] = x 
    beforeLast (_:xs) = beforeLast xs

{- try ghci last-element.hs
ghci> beforeLast [1..10]
ghci> beforeLast [1, 3, 2, 8, 5]
ghci> beforeLast ['a','b','z','q']
-}