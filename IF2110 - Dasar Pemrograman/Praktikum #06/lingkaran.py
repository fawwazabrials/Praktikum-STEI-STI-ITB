# Fawwaz Abrial Saffa / 16521115

# PROGRAM Lingkaran
# { Program menghitung luas dari sebuah lingkaran dengan input jari-jari yang mana nilainya harus >0. Jika tidak, diberikan pesan error "Jari-jari harus > 0" }

# KAMUS
# r : float

# ALGORITMA
r = float(input())
if(r > 0):
    print("%.2f" %(r*r*3.1415))
else:
    print("Jari-jari harus > 0")