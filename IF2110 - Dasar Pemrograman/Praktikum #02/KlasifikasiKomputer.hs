module KlasifikasiKomputer where
-- KlasifikasiKomputer - klasifikasi(c, g, h) 
-- Definisi dan Spesifikasi 
klasifikasi :: Int -> Int -> Int -> Int
      -- klasifikasi mengklasifikasikan komputer kedalam 5 kategori
      -- berdasarkan CPU, GPU dan Harddisknya.
      -- Kelompok 5 : CPU > 7 && GPU > 7 && Harddisk > 7
      -- Kelompok 4 : CPU <= 7 || GPU <= 7 || Harddisk <= 7
      -- Kelompok 3 : CPU <= 7 && GPU <= 7 && Harddisk <= 7
      -- Kelompok 2 : CPU < 5 || GPU < 5
      -- Kelompok 1 : CPU < 2 || GPU < 2 || Harddisk < 2

-- Realisasi
klasifikasi c g h
    | (c<2 || g<2 || h<2) = 1
    | (c<5 || g<5) = 2
    | (c<=7 && g<=7 && h<=7) = 3
    | (c<=7 || g<=7 || h<=7) = 4
    | otherwise = 5
-- Contoh aplikasi
-- klasifikasi 8 9 4
-- klasifikasi 4 10 2
-- klasifikasi 4 10 2