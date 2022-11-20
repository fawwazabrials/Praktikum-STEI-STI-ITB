# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 16 Oktober 2021
# Deskripsi : Program yang menerima bilangan X dan apakah X adalah bilangan prima.

# KAMUS
# x : int
# prima : bool

x = int(input("Masukkan X: "))
if(x < 2): 
    prima = False
else:
    prima = True
    for i in range(2,x):
        if x % i == 0:
            prima = False
            break

if prima:
    print(x, "adalah bilangan prima")
else:
    print(x, "bukan bilangan prima")
