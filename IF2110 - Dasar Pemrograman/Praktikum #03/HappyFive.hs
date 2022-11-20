module HappyFive where

konso e l = [e] ++ l
konsoDot l e = l ++ [e]
isEmpty l = null l
isOneElmt l = (length l) == 1

-- HappyFive        happyFive(l)
-- DEFINISI DAN SPESIFIKASI
happyFive :: [Int] -> [Int]
{-  happyFive memfilter list yang mana hanya dipilih angka-angka
    kelipatan 5 dan angka yang mengandung 5.-}

isFiveInside :: Int -> Bool
{-  isFiveInside memberitahu apakah sebuah integer merupakan kelipatan
    lima atau memiliki angka 5.-}

-- REALISASI
isFiveInside x =
    if mod x 5 == 0 then True
    else if div x 10 == 5 then True
    else False

happyFive l =
    if isEmpty l then []
    else if isFiveInside (head l) then konso (head l) (happyFive (tail l))
    else happyFive (tail l)