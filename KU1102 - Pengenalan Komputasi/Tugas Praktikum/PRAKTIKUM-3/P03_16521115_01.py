# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 3 November 2021
# Deskripsi : Problem 1 - Diberikan string panjang N, program ini mencari banyaknya vokal dan konsonan di dalam kalimat

# KAMUS
# N : int
# kalimat : string

# ALGORITMA
# input variabel
N = int(input("Masukkan N: "))
kalimat = input("Masukkan string: ")

# inisialisasi variabel untuk cek berapa banyak konsonan dan vokal
vokal = 0
konsonan = 0

for huruf in kalimat:
    # looping huruf-huruf yang berada dalam string kalimat

    if(huruf != " "):   # jika huruf dalam string bukan spasi
        if  (huruf == 'a' or huruf == 'i' or huruf == 'u'     # cek untuk semua huruf vokal
                or huruf == 'e' or huruf == 'o'):
            vokal += 1  # jumlah kemunculan vokal bertambah 1

        else:   # jika tidak masuk huruf vokal maka masuk ke huruf konsonan
            konsonan += 1   # jumlah kemunculan konsonan bertambah 1

# print output
print("Terdapat {} huruf vokal dan {} huruf konsonan.".format(vokal, konsonan))