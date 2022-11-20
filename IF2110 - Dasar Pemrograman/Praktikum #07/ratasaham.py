# Program RataRataSaham
# Spesifikasi : ....
import tulisdata

# KAMUS
# namafile: string

def baca_data(namafile):
    f = open(namafile, 'r')
    baris = f.readlines()

    saham = []
    for i in range(0, len(baris), 3):
        if baris[i] == "99999999":
            break

        IdPemilik = baris[i].rstrip()
        IdPT = baris[i+1].rstrip()
        Nilai = int(baris[i+2].rstrip())

        dataSaham = (IdPemilik, IdPT, Nilai)
        saham.append(dataSaham)
    return saham

def sort(arr):
    for i in range(1, len(arr)):
        cek = arr[i]
        j = i-1
        while(j >= 0 and cek < arr[j]):
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = cek

# ALGORITMA PROGRAM UTAMA
namafile = input()
tulisdata.TulisDataSaham(namafile)

saham = baca_data(namafile)
if(len(saham) == 0):
    print("File kosong")
else:
    sort(saham)

    current_id = saham[0][0]
    jumlah = 0
    count = 0
    for i in saham:
        if i[0] != current_id:
            print("{}={:.2f}".format(current_id, round(jumlah/count, 2)))
            current_id = i[0]
            jumlah = 0
            count = 0
        jumlah += i[2]
        count += 1
    print("{}={:.2f}".format(current_id, round(jumlah/count, 2)))
