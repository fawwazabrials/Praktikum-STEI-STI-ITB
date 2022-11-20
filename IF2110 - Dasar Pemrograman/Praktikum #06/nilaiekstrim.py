# Fawwaz Abrial Saffa / 16521115

# PROGRAM NilaiEkstrim
# { Program menerima N buah nilai dan x, kemudian output akan mengeluarkan apakah x merupakan nilai minimum/maksimum/tidak ada dari N input sebelumnya }

# KAMUS
# found : bool                      # Apakah X ada didalam array?
# maxi, mini : int                  # Counter nilai maks dan min
# nilai : array[0 ... N] of int     # Array penyimpan nilai yang didapat
# x : int                           # Nilai yang akan dicari

# ALGORITMA
mini = 9999999999
maxi = -9999999999

N = int(input())
nilai = [0 for i in range(N)]
for i in range(N):
    nilai[i] = int(input())
    if(nilai[i] > maxi): maxi=nilai[i]
    if(nilai[i] < mini): mini=nilai[i]

x = int(input())
found = False
for i in nilai:
    if i==x: 
        found=True
        break
if found:
    if(x == maxi): print("maksimum")
    if(x == mini): print("minimum")
    if(x != maxi and x != mini): print("N#A")
else: print(x, "tidak ada")
