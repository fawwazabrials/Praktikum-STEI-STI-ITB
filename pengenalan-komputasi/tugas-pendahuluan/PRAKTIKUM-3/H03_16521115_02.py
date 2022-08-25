# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 31 Oktober 2021
# Deskripsi : Program ini memeriksa apakah array B merupakan anagram dari array A. 
            # Anagram didefinisikan apabila elemen-elemen array B dapat ditukar-tukar 
            # sehingga menghasilkan array A dan sebaliknya.

# KAMUS
# freqA[0..9], freqB[0..9] : list of int
# A, B, masuk : int

# ALGORITMA
A = int(input("Masukkan banyaknya elemen A: "))
freqA = [0 for i in range(10)]  # inisialisasi array untuk frekuensi elemen-elemen array A
for i in range(A):
    # looping untuk membuat tabel frekuensi elemen-elemen di array A
    masuk = int(input("Masukkan elemen A ke-{}: ".format(A+1)))
    freqA[masuk] += 1

B = int(input("Masukkan banyaknya elemen B: "))
freqB = [0 for i in range(10)] # inisialisasi array untuk frekuensi elemen-elemen array B
for i in range(B):
    # looping untuk membuat tabel frekuensi elemen-elemen di array B
    masuk = int(input("Masukkan elemen B ke-{}: ".format(A+1)))
    freqB[masuk] += 1

# cek apabila jumlah elemen dari kedua array sama atau tidak

if(A != B): # jika berbeda maka otomatis array B bukanlah anagram array A
    print("B bukan anagram dari A")

else:   # jika jumlah elemen sama

    # cek apabila tabel frekuensi A dan B sama
    if(freqA == freqB):     # jika sama maka mereka adalah anagram
        print("B adalah anagram dari A")
    else:   # jika berbeda mereka bukanlah anagram
        print("B bukan anagram dari A")