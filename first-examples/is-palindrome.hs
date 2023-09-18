module IsPalindrome where

    palindrome :: Eq a => [a] -> Bool
    palindrome [] = True
    palindrome [x] = True
    palindrome (x:xs) 
        | x == last xs = palindrome(init xs)
        | otherwise = False
