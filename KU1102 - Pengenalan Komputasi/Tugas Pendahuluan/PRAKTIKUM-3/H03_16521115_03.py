# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 31 Oktober 2021
# Deskripsi : Program ini mengecek apakah sebuah kata adalah palindrom.

# KAMUS
# len : int
# kata, reverse : string

# ALGORITMA
# input variabel yang diberikan
len = int(input("Masukkan panjang string: "))
kata = input("Masukkan string: ")

reverse = ""    # membuat string kosong sebagai penyimpanan kata yang sudah dibalik
for i in range(len-1, -1, -1):
    # looping untuk membalikkan kata dan disimpan dalam 'reverse'
    reverse += kata[i]
if(kata == reverse):    # cek apabila kata sama dengan kata yang sudah dibalik (reverse)
    print(kata, "adalah palindrom")
else:
    print(kata, "bukan palindrom")