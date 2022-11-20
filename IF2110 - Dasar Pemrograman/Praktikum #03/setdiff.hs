konso e l = [e] ++ l
konsoDot l e = l ++ [e]
isEmpty l = null l
isOneElmt l = (length l) == 1

setDiff  :: [Int] -> [Int] -> [Int]
{-  setDiff menerima masukan dua buah list of integer (l1 dan l2) 
    dengan elemen unik dan terurut membesar dan mengembalikan sebuah 
    list of integer yang elemennya adalah semua elemen l1 yang tidak ada 
    di l2. -}

isIn :: [Int] -> Int -> Bool
{-  setDiff menerima masukan list dan sebuah integer, kemudian
    memberitahu apakah integer berada di dalam list tersebut -}

isIn l x =
    if isEmpty then False
    else if (head l) == x then True
    else isIn (tail l)

setDiff l1 l2 =
    if isEmpty l1 then l1
    else if isEmpty l2 then l2
    else if isIn l2 (head l1) then konso (head l1) (setDiff (tail l1) l2)
    else setDiff (tail l1) l2