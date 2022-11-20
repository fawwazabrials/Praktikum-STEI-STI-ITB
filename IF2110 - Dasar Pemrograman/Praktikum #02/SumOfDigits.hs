module SumOfDigits  where
-- SumOfDigits  - klasifSumOfDigits(x) 
-- Definisi dan Spesifikasi 
sumOfDigits :: Int -> Int
      -- SumOfDigits menghitung jumlah dari semua digit dalam integer

-- Realisasi
sumOfDigits x =
    if (x) <= 9 then x
    else (mod x 10) + sumOfDigits( div x 10 )
-- Contoh aplikasi
-- sumOfDigits 123
-- sumOfDigits 234
-- sumOfDigits 1234