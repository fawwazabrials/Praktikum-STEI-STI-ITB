# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 2 Oktober 2021
# Deskripsi : Program ini menerima input 2 variabel yang kemudian dioperasikan sesuka user

a = int(input("Masukkan angka pertama: "))
b = int(input("Masukkan angka kedua: "))
operan = input("Masukkan operator: ")

if operan=='+':
    print(a,'+',b,'=',a+b)
elif operan=='-':
    print(a,'-',b,'=',a-b)
elif operan=='*':
    print(a,'*',b,'=',a*b)
elif operan=='%':
    print(a,'%',b,'=',a%b)
elif operan=='/':
    print(a,'/',b,'=',a//b)