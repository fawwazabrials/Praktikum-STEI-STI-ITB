module AlternateSort where

konso e l = [e] ++ l
konsoDot l e = l ++ [e]
isEmpty l = null l
isOneElmt l = (length l) == 1

getSmallest :: [Int] -> Int
sortList :: [Int] -> [Int]
nbElmt :: [Int] -> Int
    {- nbElmt yang menerima masukan sebuah list of integer 
    (mungkin kosong) dan menghasilkan banyaknya elemen dalam 
    list (0 jika list kosong) secara rekursif -}
algorithm :: [Int] -> Int -> [Int]
-- REALISASI
delElement x l =
    if (head l) == x then (tail l)
    else konso (head l) (delElement (x) (tail l))

nbElmt l =
    if isEmpty l then 0
    else 1 + nbElmt (tail l)

getSmallest l =
    if (isEmpty l) then 9999999999999
    else div ((head l) + (getSmallest (tail l)) - abs((head l) - (getSmallest (tail l)))) 2

sortList l =
    if isEmpty l then []
    else konso (getSmallest l) (sortList (delElement (getSmallest l) l))

alternateSort l =
    algorithm l 0

algorithm l x =
    let panjang = nbElmt l
        sorted = sortList l
    in
        if isEmpty l then l
        else if mod x 2==0 then konso (head sorted) (algorithm (tail sorted) (x+1))
        else konso (last sorted) (algorithm (init sorted) (x+1))