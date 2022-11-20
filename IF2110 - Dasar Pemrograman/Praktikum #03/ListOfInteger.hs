module ListOfInteger where
-- DEFINISI DAN SPESIFIKASI LIST
{- type List of Int: [ ] atau [e o List] atau [List o e]  
   Definisi type List of Int
   Basis: List of Int kosong adalah list of Int 
   Rekurens: 
   List tidak kosong dibuat dengan menambahkan sebuah elemen bertype Int di awal 
   sebuah list atau
   dibuat dengan menambahkan sebuah elemen bertype Int di akhir sebuah list -}

-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
konso :: Int -> [Int] -> [Int]
{- konso e li menghasilkan sebuah list of integer dari e (sebuah integer) dan li 
   (list of integer), dengan e sebagai elemen pertama: e o li -> li' -}
-- REALISASI
konso e li = [e] ++ li

konsDot :: [Int] -> Int -> [Int]
{- konsDot li e menghasilkan sebuah list of integer dari li (list of integer) dan 
   e (sebuah integer), dengan e sebagai elemen terakhir: li o e -> li' -}
-- REALISASI
konsDot li e = li ++ [e]

-- DEFINISI DAN SPESIFIKASI SELEKTOR
-- head :: [Int] -> Int
-- head l menghasilkan elemen pertama list l, l tidak kosong

-- tail :: [Int] -> [Int]
-- tail l menghasilkan list tanpa elemen pertama list l, l tidak kosong

-- last :: [Int] -> Int
-- last l menghasilkan elemen terakhir list l, l tidak kosong

-- init :: [Int] -> [Int]
-- init l menghasilkan list tanpa elemen terakhir list l, l tidak kosong

-- DEFINISI DAN SPESIFIKASI PREDIKAT
isEmpty :: [Int] -> Bool
-- isEmpty l  true jika list of integer l kosong
-- REALISASI
isEmpty l = null l

isOneElmt :: [Int] -> Bool
-- isOneElmt l true jika list of integer l hanya mempunyai satu elemen
-- REALISASI
isOneElmt l = (length l) == 1 


-- DEFINISI DAN SPESIFIKASI
nbElmt :: [Int] -> Int
    {- nbElmt yang menerima masukan sebuah list of integer 
    (mungkin kosong) dan menghasilkan banyaknya elemen dalam 
    list (0 jika list kosong) secara rekursif -}
-- REALISASI
nbElmt l =
    if isEmpty l then 0
    else 1 + nbElmt (tail l)



-- DEFINISI DAN SPESIFIKASI
setDiff  :: [Int] -> [Int] -> [Int]
{-  setDiff menerima masukan dua buah list of integer (l1 dan l2) 
    dengan elemen unik dan terurut membesar dan mengembalikan sebuah 
    list of integer yang elemennya adalah semua elemen l1 yang tidak ada 
    di l2. -}

isIn :: [Int] -> Int -> Bool
{-  setDiff menerima masukan list dan sebuah integer, kemudian
    memberitahu apakah integer berada di dalam list tersebut -}

-- REALISASI
isIn l x =
    if isEmpty l then False
    else if (head l) == x then True
    else isIn (tail l) x

setDiff l1 l2 =
    if isEmpty l1 then l1
    else if isEmpty l2 then l1
    else if (not) (isIn l2 (head l1)) then konso (head l1) (setDiff (tail l1) l2)
    else setDiff (tail l1) l2