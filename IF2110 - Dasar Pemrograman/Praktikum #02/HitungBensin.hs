module HitungBensin where
-- HitungBensin - hitungBensin (a, b) 
-- Definisi dan Spesifikasi
hitungBensin :: Int -> Int -> Int
    -- hitungBensin menghitung jumlah bensin yang diperlukan
    -- dalam perjalanan setiap mobil untuk setiap jarak dari range
    -- a sampai b
harga :: Int -> Int
    -- menghitung harga bensin dengan pergerakan jika 
    -- genap x/2 dan ganjil (3x-1)

-- REALISASI
harga x
  | x == 1 = 0
  | mod x 2 == 0 = 1 + harga (div x 2)
  | otherwise = 1 + harga (x*3 + 1)


hitungBensin a b
  | a == b = harga a
  | otherwise = harga b + hitungBensin a (b-1)