module OffsetList where

konso e l = [e] ++ l
konsoDot l e = l ++ [e]
isEmpty l = null l
isOneElmt l = (length l) == 1

-- OffsetList       offsetList(l, f)
-- DEFINISI DAN SPESIFIKASI
offsetList :: [Int] -> (Int->Int) -> [Int]
{-  offsetList yang menerima masukan sebuah list of integer yang 
    melakukan “offset” atau perubahan nilai terhadap elemen list 
    sesuai dengan aturan tertentu (yang ditentukan oleh sebuah fungsi 
    offset) dan menghasilkan list baru dengan elemen hasil offset. -}

-- REALISASI
offsetList l f =
    if isEmpty l then []
    else konso (f (head l)) (offsetList (tail l) f)
