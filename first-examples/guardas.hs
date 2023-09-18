module Guardas where

elementAt :: [a] -> Int -> a                    -- define a list of something (a): (type define)

elementAt [] _ = error "index out of bound"     -- on empty list, throw an error message
elementAt (x:xs) 0 = x                          -- start on
elementAt (x:xs) n
    | n < 0 = error "index out of bound"        -- 'guarda' definition: define what to do on a given condition
    | otherwise = elementAt xs (n-1)            -- recursive call

 
{- try: ghci guardas.hs
> elementAt [6, 3, 8, 4, 2, 9, 0] 1
> elementAt [6, 3, 8, 4, 2, 9, 0] 4
> elementAt [6, 3, 8, 4, 2, 9, 0] 7
> elementAt [6, 3, 8, 4, 2, 9, 0] (-1)
-}