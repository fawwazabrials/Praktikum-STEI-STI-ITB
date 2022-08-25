# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 17 November 2021
# Deskripsi : Program ini menghitung volume dari sebuah rumah yang terdiri dari kubus dan limas

# KAMUS
# s, t : int

# ALGORITMA
def kubus(s):
    # fungsi untuk mencari volume dari kubus yang menerima parameter s: sisi kubus
    return s**3

def limas(s, t):
    # fungsi untuk mencari volume dari limas persegi yang menerima parameter s: sisi persegi dan t: tinggi limas
    return 1/3 * s**2 * t

# inisialisasi variabel dan input
s = int(input("Masukkan panjang sisi kubus: "))
t = int(input("Masukkan tinggi limas: "))

# printing output dan menjumlahkan volume kubus dan limas untuk mendapatkan volume rumah
print("Volume rumah yang terbentuk adalah", kubus(s)+limas(s,t), "meter kubik.")