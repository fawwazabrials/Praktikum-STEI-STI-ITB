# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 2 Oktober 2021
# Deskripsi : Program yang menentukan apakah sebuah bilangan adalah bilangan positif, negatif, atau nol.

x = int(input("Masukkan X: "))

if x < 0:
    print("X adalah bilangan positif genap")
elif x == 0:
    print("X adalah bilangan nol")
else:
    if x%2==0:
        print("X adalah bilangan positif genap")
    else:
        print("X adalah bilangan positif ganjil")