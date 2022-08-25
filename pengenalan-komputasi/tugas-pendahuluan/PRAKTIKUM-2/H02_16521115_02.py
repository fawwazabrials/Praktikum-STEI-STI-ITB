# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 16 Oktober 2021
# Deskripsi : Program yang menerima bilangan N dan menuliskan bilangan 10^x terkecil yang lebih dari N.

# KAMUS
# n, base : int

# ALGORITMA
n = int(input("Masukkan N: "))
base = 0
while n/10 > 0:
    n = n//10
    base += 1
print(10**base)
