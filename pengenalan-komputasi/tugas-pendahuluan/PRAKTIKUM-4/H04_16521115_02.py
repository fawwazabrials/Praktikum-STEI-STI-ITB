# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 14 November 2021
# Deskripsi : Program ini membaca matriks dengan dimensi N x M kemudian mengeluarkan isi dari matriks tersebut dalam bentuk matriks

# KAMUS
# positif, M, N : int
# A[M x N] : array of array of int

# ALGORITMA
# initialisasi dan input variabel
M = int(input("Masukkan M: "))
N = int(input("Masukkan N: "))
A = [[0 for i in range(N)] for i in range(M)]

positif = 0 # digunakan untuk menyimpan banyaknya bilangan yang positif (x>0)
for i in range(M):
    # looping baris
    for j in range(N):
        # looping kolom
        A[i][j] = int(input("Masukkan nilai A[{}][{}]: ".format(i+1, j+1)))
        if(A[i][j] > 0): # if statement apakah bilangan yang diinputkan positif
            positif += 1 # bila positif tambahkan 1 ke dalam variabel 'positif'

print("Ada", positif, "bilangan positif di matriks.")
# printing dengan format matriks
for i in range(M):
    # looping baris
    for j in range(N-1):
        # looping kolom
        print(A[i][j], end = ' ')
    print(A[i][N-1])