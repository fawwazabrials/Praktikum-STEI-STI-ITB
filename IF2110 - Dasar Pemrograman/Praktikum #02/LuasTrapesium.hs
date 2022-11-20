module LuasTrapesium where
-- LuasTrapesium - luasTrapesium(t, s1, s2) 
-- Definisi dan Spesifikasi 
luasTrapesium :: Float -> Float -> Float -> Float
      -- LuasTrapesium menghitung luas sebuah trapesium
      -- dengan input kedua sisi (s1 dan s2) juga tinggi
      -- trapesium
-- Realisasi
luasTrapesium t s1 s2 = 
    if (t>0 && s1>0 && s2>0 && s1/=s2) then
        (t*(s1+s2))/2 
    else 0
-- Contoh aplikasi
-- luasTrapesium 2 4 3