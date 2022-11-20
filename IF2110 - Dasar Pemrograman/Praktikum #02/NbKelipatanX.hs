module NbKelipatanX where
-- NbKelipatanX - nbKelipatanX (a, b, x) 
-- Definisi dan Spesifikasi 
nbKelipatanX :: Int -> Int -> Int -> Int
      -- nbKelipatanX menerima 3 buah input, a, b, dan x
      -- a dan b adalah batas bawah dan atas dan inklusif, x
      -- merupakan kelipatan yang ingin dicari. Fungsi ini
      -- looping semua angka-angka dalam batas tersebut dan
      -- mengeluarkan berapa banyak kelipatan x yang ditemukan.
nbKelipatanX a b x 
    | (a==b) && ((mod a x)==0) = 1
    | (a==b) && ((mod a x)/=0) = 0
    | otherwise =
        if (((mod a x)==0)) then 1 + nbKelipatanX (a+1) b x
        else nbKelipatanX (a+1) b x

-- Aplikasi
-- nbKelipatanX 1 1 1
-- nbKelipatanX 1 10 2
-- nbKelipatanX 5 14 3