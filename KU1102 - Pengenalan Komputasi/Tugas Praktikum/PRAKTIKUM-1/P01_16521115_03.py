# NIM/Nama  : 16521115/Fawwaz Abrial Saffa
# Tanggal   : 6 Oktober 2021
# Deskripsi : Program ini menentukan apakah data Tuan Dip tentang banyak kaki yang menginjak lantai benar.

# KAMUS
# cek : bool
# lantai, tua, anak, orang : int

# INPUT berupa jumlah kaki pada lantai, jumlah orang tua, dan jumlah anak.
lantai = int(input("Banyak kaki yang menginjak lantai: "))
tua = int(input("Banyak orang tua: "))
anak = int(input("Banyak anak: "))


if(lantai % 2 == 0):            # Jumlah kaki yang menapak di lantai harus genap.
    orang = lantai/2                # Menghitung jumlah orang yang ada pada lantai
    orang -= tua                    # Karena orang tua selalu menapakan kaki pada lantai, kurangi jumlah orang sebanyak orang tua
    if(orang >= 0):                 # Cek apabila jumlah orang tua tidak melebihi jumlah orang yang seharusnya ada di lantai 
        anak -= orang                   # Kurangi jumlah anak yang menapakan kaki di tanah
        if(anak >= 0):                  # Cek apakah ada sisa anak
            if(anak <= tua*2):              # Cek apakah semua anak yang tersisa bisa digendong
                cek = True
            else:                           # Terdapat sisa anak yang tidak bisa dingendong
                cek = False
        else:                           # Kurang anak untuk mencapai jumlah kaki yang diinginkan
            cek = False
    else:                           # Terlalu banyak orang tua sehingga jumlah kaki lebih dari input
        cek = False
else:                           # Jumlah kaki yang ganjil tidak mungkin terjadi.
    cek=False


# OUTPUT data Tuan Dip Benar atau Salah.
if cek:
    print("Data Tuan Dip mungkin benar.")  
else:
    print("Data Tuan Dip tidak mungkin benar.")