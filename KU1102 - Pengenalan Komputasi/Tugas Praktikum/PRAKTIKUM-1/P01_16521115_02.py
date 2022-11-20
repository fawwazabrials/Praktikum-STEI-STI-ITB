# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 6 Oktober 2021
# Deskripsi : Program ini menentukan kelas dan harga tiker pesawat Tuan Kil.

# KAMUS
# harga, kursi : int
# posisi, jenis : string

# INPUT nomor kursi dan posisi yang diinginkan.
kursi = int(input("Tentukan Nomor Kursi: "))
posisi = input("Tentukan Posisi Kursi: ")

if(1<=kursi<=20 or 51<=kursi<=60):      # Cek apakah kursi merupakan kursi Hot Seat.
    jenis = "Hot Seat"
    if(posisi=='A' or posisi=='F'):     # Cek apakah posisi kursi A atau F.
        harga = 1600
    elif(posisi=='B' or posisi=='E'):   # Cek apakah posisi kursi B atau E.
        harga = 1550
    elif(posisi=='C' or posisi=='D'):   # Cek apakah posisi kursi C atau D.
        harga = 1500

elif(21<=kursi<=50 or 61<=kursi<=100):  # Cek apakah kursi merupakan kursi Regular.
    jenis = "Regular"
    if(posisi=='A' or posisi=='F'):     # Cek apakah posisi kursi A atau F.
        harga = 1000
    elif(posisi=='B' or posisi=='E'):   # Cek apakah posisi kursi B atau E.
        harga = 950
    elif(posisi=='C' or posisi=='D'):   # Cek apakah posisi kursi C atau D.
        harga = 900

# OUTPUT berupa jenis kursi yang dipilih Tuan Kil beserta harga untuk kursi tersebut.
print("Tuan Kil memilih kursi", jenis, "dengan harga", harga*1000, end=".")