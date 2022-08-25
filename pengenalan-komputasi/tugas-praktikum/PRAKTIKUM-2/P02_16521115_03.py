# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 27 Oktober 2021
# Deskripsi : Mencari nilai kali maksimum dari semua penjumlahan N

# KAMUS
# N, maxi, maxi_local, now : int

# input
N = int(input("Masukkan bilangan N: "))
maxi = -999999999999

# LOOPING UNTUK CEK SEMUA KEMUNGKINAN PENJUMLAHAN (diutamakan bilangan yang berulang)
for i in range(1, N+1):
    now = N//i  # mencari nilai maksimum i yang dapat membagi N

    for j in range(1, now+1):
        # looping dari 1 sampai nilai maksimum i yang dapat membagi N
        maxi_local = i**j * (N-(i*j))   # nilai penjumlahan : i, i, ..., i(sebanyak j kali), dan sisa penjumlahan tersebut. Kemudian dikalikan semua
        if(maxi_local > maxi): 
            maxi = maxi_local   # apabila nilai maksimum dari perulangan j melebihi nilai maksimum yang sudah disimpan, di-update

print("\nNilai maksimumnya adalah", maxi)
# ditambahin \n karena di soal spasinya berjarak 2 kali
            