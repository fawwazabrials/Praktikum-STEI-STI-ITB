# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 6 Oktober 2021
# Deskripsi : Menghitung besar pajak penghasilan yang harus dibayarkan oleh Tuan Ric

# KAMUS
# penghasilan, pajak : int

# INPUT penghasilan milik Tuan Ric
penghasilan = int(input("Masukkan penghasilan Tuan Ric: "))


if(penghasilan < 50000000):                     # Jika penghasilan kurang dari Rp50.000.000,00 maka pajak 5%
    pajak = penghasilan * 5 / 100
elif(50000000 <= penghasilan < 249999999):      # Jika penghasilan pada rentang Rp50.000.000,00 - Rp249.999.999,00 maka pajak 15%
    pajak = penghasilan * 15 / 100
elif(250000000 <= penghasilan < 499999999):     # Jika penghasilan pada rentang Rp250.000.000,00 - Rp499.999.999,00 maka pajak 25%
    pajak = penghasilan * 25 / 100
else:                                           # Jika penghasilan lebih dari dari Rp499.999.999,00 maka pajak 30%
    pajak = penghasilan * 30 / 100    

# OUTPUT berupa pajak yang harus dibayarkan Tuan Ric
print("Pajak yang harus dibayar Tuan Ric sebesar", pajak, "rupiah.")


