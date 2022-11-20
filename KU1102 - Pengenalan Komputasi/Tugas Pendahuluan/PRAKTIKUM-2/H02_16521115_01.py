# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 16 Oktober 2021
# Deskripsi : Program yang menerima bilangan N dan menuliskan 1 sampai N dalam satu baris.

# KAMUS
# N : int

# ALGORITMA
N = int(input("Masukkan N: "))
for i in range(N):
    if i+1==N:
        print(i+1)
    else:
        print(i+1, end=" ")