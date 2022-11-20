# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 17 November 2021
# Deskripsi : Program ini mencari berapa banyak permutasi dari sebuah kata

# KAMUS
# sudah[a, b, ...] : array of char
# kata : string
# len, bawah, idx, banyak, bawah : int

# ALGORITMA
def faktorial(x):
    # fungsi untuk mencari nilai faktorial
    f = 1
    for i in range(1, x+1):
        f *= i
    return f

# inisialisi dan input
len = int(input("Masukkan panjang string: "))
kata = input("Masukkan string: ")
bawah = 1 # untuk menghitung nilai penyebut dari rumus permutasi
idx = 0 # untuk index dari array sudah (dipakai karena jika tidak dipakai hanya array indeks 0 yang bisa diubah)
sudah = ['' for i in range(len)] # array untuk menyimpan huruf yang sudah muncul sebelumnya

for i in range(len):
    # looping string
    cari = kata[i] # variabel untuk mencari huruf dalam kata
    if (cari in sudah):
        # cek apakah huruf tersebut sebelumnya sudah muncul
        cari = '' # jika sudah ubah ke huruf yang tidak mungkin muncul

    banyak = 0 # mencari banyaknya kemunculan huruf dalam string
    for j in range(i, len):
        # looping dari huruf yang dicari sampai akhir string
        if(kata[j] == cari):
            banyak += 1 # bila ketemu tambah di variabel banyak

    bawah *= faktorial(banyak) # update nilai dari penyebut rumus
    sudah[idx] = cari # update huruf yang barusan dicari dimasukan ke array huruf yang sudah pernah muncul
    idx+=1 # update index

# print output dari rumus
print(faktorial(len)/bawah)

