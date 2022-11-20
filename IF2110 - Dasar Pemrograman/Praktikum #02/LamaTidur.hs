module LamaTidur where
-- LamaTidur - lamaTidur (c, g, h) 
-- Definisi dan Spesifikasi 
lamaTidur :: Int -> Int -> Int -> (Bool, Int, Int, Int)
      -- lamaTidur menghitung berapa lama panitia Arkavidia
      -- tidur jika mereka bangun di jam 5 pagi, output berupa
      -- pernyataan boleean apakah mereka mendapatkan 6 jam tidur,
      -- lama jam, menit dan detik tidur.
toSecond :: Int -> Int -> Int -> Int
      -- toSecond mengkonversi jam dalam format jj:mm:dd
      -- ke detik

-- Realisasi
toSecond j m d = j*3600 + m*60 + d
lamaTidur j m d =
    let 
        waktuTidur = 
            if j < 5 then (toSecond 5 0 0) - (toSecond j m d)
            else (toSecond 24 0 0) - (toSecond j m d) + (toSecond 5 0 0)
        jam = div waktuTidur 3600
        menit = div (waktuTidur - jam * 3600) 60
        detik = waktuTidur - toSecond jam menit 0
    in (waktuTidur >= 6 * 3600, jam, menit, detik)



-- Contoh aplikasi
-- lamaTidur 1 0 0
