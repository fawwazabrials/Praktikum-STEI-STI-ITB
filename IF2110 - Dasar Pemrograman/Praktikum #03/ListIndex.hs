module ListIndex where

konso e l = [e] ++ l
konsoDot l e = l ++ [e]
isEmpty l = null l
isOneElmt l = (length l) == 1

-- listIndex       listIndex(l, f)
-- DEFINISI DAN SPESIFIKASI
listIndex :: [Int] -> (Int->Char) -> [Char]
{-  listIndex akan menghasilkan sebuah list of character yang 
    melambangkan nilai-nilai indeks dari suatu list nilai integer. -}

-- REALISASI
listIndex l f =
    if isEmpty l then []
    else konso (f (head l)) (listIndex (tail l) f)