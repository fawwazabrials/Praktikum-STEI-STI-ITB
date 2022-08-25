# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 3 November 2021
# Deskripsi : Problem 2 - Program ini mensimulasikan sebuah barisan lampu yang kondisi awalnya semua mati. Ketika sebuah tombol N dipencet maka lampu N akan berubah kondisinya dari nyala menjadi mati atau mati menjadi nyala. Dan dua lampu yang berada di sebelah kanan dan sebelah kiri lampu juga akan berubah kondisi. Output akhir akan menunjukan kondisi akhir lampu-lampu setelah pencetan.

# KAMUS
# N, kali, pencet : int
# lampu[1...N] : array of int

# ALGORITMA
# input variabel
N = int(input("Masukkan banyak lampu: "))
kali = int(input("Masukkan berapa kali Tuan Kil menekan tombol: "))

# initialisasi array untuk lampu-lampu (di-set menjadi 0 karena kondisi awal mati semua)
lampu = [0 for i in range(N)]

for i in range(kali):
    # looping untuk berapa kali pemencetan tombol
    pencet = int(input("Tombol yang ditekan ke {}: ".format(i+1))) - 1  # input tombol yang dipencet dan dikurang 1 karena array lampu dimulai dari index 0
    lampu[pencet] = (lampu[pencet]+1)%2 # ubah kondisi lampu menjadi sebaliknya. Digunakan modulo disini karena kondisi 
                                        # lampu merupakan bilangan biner dan juga untuk menhindari penggunaan if-else yang banyak

    if(pencet - 1 >= 0): # cek apakah pencet-1 (lampu di sebelah kiri) out of bound. Jika tidak ubah kondisi lampu tersebut
        lampu[pencet-1] = (lampu[pencet-1]+1)%2
    if(pencet + 1 < N): # cek apakah pencet+1 (lampu di sebelah kanan) out of bound. Jika tidak ubah kondisi lampu tersebut
        lampu[pencet+1] = (lampu[pencet+1]+1)%2

# print output sesuai dengan soal
print("Keadaan akhir rangkaian lampu adalah", end=" ")
for i in lampu:
    # looping untuk semua lampu di dalam array lampu
    print(i, end="")
print(".")

