# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 14 November 2021
# Deskripsi : Program yang menentukan nilai fungsi f(x) = x^2 - 2x + 5 untuk semua bilangan bulat dalam [A, B]

# KAMUS
# A, B : int

# ALGORITMA
def f(x):   # fungsi untuk mencari nilai dari x^2 - 2x + 5 dengan x diberikan sebagai parameter
    return x**2 - 2*x + 5

A = int(input("Masukkan A: "))
B = int(input("Masukkan B: "))
for i in range(A, B+1):
    # looping untuk mencari nilai f(x) setiap bilangan bulat dalam range A sampai B (inklusif)
    print("f({}) = {}".format(i, f(i)))
