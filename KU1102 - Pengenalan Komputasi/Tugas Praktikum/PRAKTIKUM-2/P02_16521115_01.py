# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 27 Oktober 2021
# Deskripsi : Menghitung banyak langkah untuk mengubah N menjadi 1 dengan
#             aturan genap : N/2 dan ganjil : N-1

# KAMUS
# N, langkah = int

# input
N = int(input("Masukkan bilangan N: "))

langkah = 0
while(N > 1):
    if(N % 2 == 0): 
        N /= 2      # bila genap N dibagi 2
    else:
        N -= 1      # bila ganjil N dikurang 1
    langkah += 1    

print("Banyak langkah yang diperlukan adalah {}.".format(langkah))
