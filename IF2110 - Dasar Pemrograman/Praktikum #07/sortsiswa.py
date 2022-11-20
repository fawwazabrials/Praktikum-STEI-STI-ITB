# Program SortSiswa
# Spesifikasi : ....
import tulisdata

# KAMUS
# namafile: string

def sort(arr):
    for i in range(1, len(arr)):
        cek = arr[i]
        j = i-1
        while(j >= 0 and cek[0] < arr[j][0]):
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = cek

def baca_data(namafile):
    f = open(namafile, 'r')
    baris = f.readlines()

    siswa = []
    for i in range(0, len(baris), 3):
        if baris[i] == "99999999":
            break

        NoInduk = baris[i].rstrip()
        KodeKursus = baris[i+1].rstrip()
        Nilai = int(baris[i+2].rstrip())

        dataSiswa = (NoInduk, KodeKursus, Nilai)
        siswa.append(dataSiswa)
    return siswa

# ALGORITMA PROGRAM UTAMA
namafile = input()
tulisdata.TulisDataSiswa(namafile)

siswa = baca_data(namafile)
if(len(siswa) == 0):
    print("File kosong")
else:
    sort(siswa)

    for i in siswa:
        print("{},{},{}".format(i[0],i[1],i[2]))