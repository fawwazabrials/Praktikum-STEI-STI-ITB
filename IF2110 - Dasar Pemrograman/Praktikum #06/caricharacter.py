# Fawwaz Abrial Saffa / 16521115

# PROGRAM Tabungan
# { program yang digunakan untuk membaca sebuah integer positif N. Nilai N harus divalidasi sampai didapatkan nilai N yang benar, 
#   yaitu 0 < N <= 100. Jika masukan N salah, tuliskan pesan “Masukan salah. Ulangi!”. Setelah didapatkan nilai N yang benar, 
#   program meminta masukan N buah character.
#   Selanjutnya, program menerima masukan sebuah character, misalnya CC, dan menghasilkan:
#   o Jika CC = ‘S’ atau CC = ‘s’ (kependekan dari “small”), tuliskan urutan pertama ditemukannya character huruf 
#     kecil dan tuliskan hurufnya. Jika tidak ada character huruf kecil, tuliskan “Tidak ada huruf kecil”.
#   o Jika CC = ‘L’ atau CC = ‘l’ (el, kependekan dari “large”), tuliskan urutan pertama ditemukannya character 
#     huruf besar dan tuliskan hurufnya. Jika tidak ada character huruf besar, tuliskan “Tidak ada huruf besar”.
#   o Jika CC = ‘X’ atau CC = ‘x’, tuliskan urutan pertama ditemukannya character selain huruf dan tuliskan 
#     character-nya. Jika tidak ada character selain huruf, tuliskan “Semua huruf”.
#   o Jika CC selain selain {‘S’,’s’,’L’,’l’,’X’,’x’} tuliskan: “Tidak diproses”. }

# KAMUS
# to be written:))

# ALGORITMA
N = int(input())
while (not (0<N<=100)):
    print("Masukan salah. Ulangi!")
    N = int(input())

karakter = ['a' for i in range(N)]
for i in range(N):
    karakter[i] = input()

CC = input()
if(CC=='s' or CC=='S' or CC=='l' or CC=='L' or CC=='x' or CC=='X'):
    found = False
    index = 0
    if(CC=='s' or CC=='S'):
        for i in range(N):
            if(97 <= ord(karakter[i]) <= 122):
                found = True
                index = i + 1
                break
        if(found):
                print(index, karakter[index-1])
        else:
                print("Tidak ada huruf kecil")
    elif(CC=='l' or CC=='L'):
        for i in range(N):
            if(65 <= ord(karakter[i]) <= 90):
                found = True
                index = i + 1
                break
        if(found):
                print(index, karakter[index-1])
        else:
                print("Tidak ada huruf besar")
    else:   # x atau X
        for i in range(N):
            if((not (97 <= ord(karakter[i]) <= 122)) and (not (65 <= ord(karakter[i]) <= 90))):
                found = True
                index = i + 1
                break
        if(found):
            print(index, karakter[index-1])
        else:
            print("Semua huruf")
else:
    print("Tidak diproses")