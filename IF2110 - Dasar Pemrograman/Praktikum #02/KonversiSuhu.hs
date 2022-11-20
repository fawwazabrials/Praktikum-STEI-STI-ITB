module KonversiSuhu where
-- KonversiSuhu - konversiSuhu(T, K) 
-- Definisi dan Spesifikasi 
konversiSuhu :: Float -> Char -> Float
      -- KonversiSuhu mengonversi suhu T yang diketahui
      -- dalam besaran celcius menjadi nilai T di besaran
      -- suhu K
-- Realisasi
konversiSuhu t k
    | (k == 'R') = t/5 * 4
    | (k == 'K') = t + 273.15
    | (k == 'F') = (t/5*9)+32
    | otherwise = 0
-- Contoh aplikasi
-- konversiSuhu 25 'R'
-- konversiSuhu 37 'F'
-- konversiSuhu (-30) 'K'