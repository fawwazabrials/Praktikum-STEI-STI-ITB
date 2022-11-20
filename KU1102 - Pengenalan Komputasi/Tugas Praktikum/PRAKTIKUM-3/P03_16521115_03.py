# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 3 November 2021
# Deskripsi : Problem 3 - Program ini mencari berapa banyak kemunculan string 1 dalam string 2

# KAMUS
# len1, len2, banyak : int
# s1, s2, slice : string

# ALGORITMA
# input variabel
len1 = int(input("Masukkan panjang string 1: "))
s1 = input("Masukkan string 1: ")
len2 = int(input("Masukkan panjang string 2: "))
s2 = input("Masukkan string 2: ")

# inisialisasi variabel untuk menyimpan jumlah kemunculan string 1 didalam string 2
banyak = 0

for i in range(len2 - len1 + 1):
    # looping untuk string 2 sebanyak (len2-len1-1) karakter supaya string 2 bisa di slicing sepanjang len1. Terdapat -1 karena index string dimulai dari 0

    slice = ""    # inisialisasi string baru untuk slicing string 2
    for j in range(len1):
        # looping sebanyak len1
        slice += s2[i+j]  # menambahkan karakter-karakter string 2 kedalam compare dengan panjang len1 (dengan kata singkat ini algoritma slicing)

    if(slice == s1):  # jika string slicing sama dengan string 1 maka string 1 muncul di dalam string 2
        banyak += 1

# print output
print("String 1 muncul sebanyak", banyak, "kali.")