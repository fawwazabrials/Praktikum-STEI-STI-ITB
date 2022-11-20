# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 31 Oktober 2021
# Deskripsi : Program ini membalik input yang sudah dimasukan.

# KAMUS
# arr[0..N] : list of int
# N : int

# ALGORITMA
N = int(input("Masukkan N: "))
arr = [0 for i in range(N)]

for i in range(N):
    arr[i] = int(input())

print("Hasil dibalik:")
for i in range(N-1, -1, -1):
    print(arr[i])
