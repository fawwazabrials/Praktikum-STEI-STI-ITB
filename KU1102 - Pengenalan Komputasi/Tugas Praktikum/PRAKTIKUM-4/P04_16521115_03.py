# NIM/Nama              : 16521115/Fawwaz Abrial Saffa
# Tanggal               : 17 November 2021
# Deskripsi             : Program ini mencari keliling suatu pulau dari sebuah peta

# Penjelasan algoritma  : bila di sebelah suatu pulau adalah pulau lain maka sisi yang bersentuhan tidak masuk kedalam perhitungan keliling
#                         namun, jika di sebelah suatu pulau adalah border peta atau laut maka sisi yang bersentuhan merupakan keliling
#                         program ini mengecek setiap sisi dari setiap index

# KAMUS
# baris, kolom, keliling : int
# peta[[0,..],..] : array of array of int

# ALGORITMA
# inisialisasi variabel dan input
baris = int(input("Masukkan nilai brs: "))
kolom = int(input("Masukkan nilai klm: "))
peta = [[0 for i in range(kolom)] for i in range(baris)]
for i in range(baris): # looping untuk mengisi matriks peta
    for j in range(kolom):
        peta[i][j] = int(input("Masukkan nilai petak baris {} kolom {}: ".format(i+1,j+1)))
keliling = 0

for i in range(baris):  # looping baris
    for j in range(kolom):  # looping kolom
        if(peta[i][j] == 1): # cek apakah pada index tersebut berupa pulau
            if(i-1<0 or peta[i-1][j]==0): keliling += 1         # cek apakah di sebelah atas pulau adalah laut atau border (out of bond). Bila iya +1 keliling
            if(i+1>=kolom or peta[i+1][j]==0): keliling += 1    # cek apakah di sebelah bawah pulau adalah laut atau border (out of bond). Bila iya +1 keliling
            if(j-1<0 or peta[i][j-1]==0): keliling += 1         # cek apakah di sebelah kiri pulau adalah laut atau border (out of bond). Bila iya +1 keliling
            if(j+1>=baris or peta[i][j+1]==0): keliling += 1    # cek apakah di sebelah kanan pulau adalah laut atau border (out of bond). Bila iya +1 keliling

        # bila di sebelah suatu pulau adalah pulau lain maka sisi yang bersentuhan tidak masuk kedalam perhitungan keliling
        # namun, jika di sebelah suatu pulau adalah border peta atau laut maka sisi yang bersentuhan merupakan keliling
        # program ini mengecek setiap sisi dari setiap index
print("Keliling pulau tersebut adalah {}.".format(keliling))