# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 27 Oktober 2021
# Deskripsi : Menghitung banyak ember x dan ember y yang 
#             diperlukan untuk mengisi kolam z

# KAMUS
# x, y, z, z_mutable, banyak_x, banyak_y, found : int
# found : bool {False bila tidak ditemukan konfigurasi, True bila ditemukan}

# input
x = int(input("Masukkan x: "))
y = int(input("Masukkan y: "))
z = int(input("Masukkan z: "))

# inisialisasi variabel
found = False
banyak_x = 0
banyak_y = 0
i = 1

while(not(found) and i <= z//x):
    # looping selama x*k (bilangan bulat) dapat mengurangi z
    banyak_x = i
    z_mutable = z   # menyimpan z di variabel lain supaya z awal tidak berubah
    z_mutable -= banyak_x*x            # pengurangan nilai x
    banyak_y = z_mutable//y     # mencari nilai y*k maksimum yang dapat mengurangi z yang tersisa
    z_mutable -= banyak_y * y   # pengurangan nilai y maksimum
    if(z_mutable == 0):     # cek apakah konfigurasi menyebabkan z abis
        found = True
    i+=1
if(found):  # bila ditemukan konfigurasi ember
    print("{} kali ember x, {} kali ember y".format(banyak_x, banyak_y))
else:   # bila tidak ada konfigurasi yang valid
    print("Tidak mungkin")
