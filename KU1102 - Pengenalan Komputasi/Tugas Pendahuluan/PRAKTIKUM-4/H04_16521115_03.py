# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 14 November 2021
# Deskripsi : Program ini mensimulasikan segitiga pascal dalam sebuah matriks dengan dimensi NxN

# KAMUS
# N : int
# pascal[N x N] : array of array of int

# ALGORITMA
# inisialisasi dan input
N = int(input("Masukkan N: "))
pascal = [[1 for i in range(N)] for i in range(N)]

for i in range(1, N):
    # looping baris (dimulai dari 1 karena bilangan pojok kiri atas harus bernilai 1)
    for j in range(1, N):
        # looping kolom (dimulai dari 1 karena bilangan pojok kiri atas harus bernilai 1)

        pascal[i][j] = pascal[i-1][j] + pascal[i][j-1] # menghitung nilai bilangan dengan menjumlahkan bilangan di kirinya dan bilangan di atasnya

# printing output
for i in range(N):
    # looping baris
    for j in range(N-1):
        # looping kolom
        print(pascal[i][j], end=' ')
    print(pascal[i][N-1])