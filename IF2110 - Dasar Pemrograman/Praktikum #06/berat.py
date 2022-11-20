# Fawwaz Abrial Saffa / 16521115

# PROGRAM Berat
# { Program menerima input sebanyak mungkin sampai diterima input -999. Kemudian dituliskan jumlah input valid yang diterima beserta 
#   nilai berat yang <= 50 dan >= 100 juga rata-rata berat. Input valid adalah input yang berada di dalam range [30, 200] inklusif }

# KAMUS
# berat, count, sum, less50, more100 : int
# mean : float

# ALGORITMA
count = 0
sum = 0
less50 = 0
more100 = 0

berat = int(input())
while berat != -999:
    if berat >= 30 and berat <= 200:
        count += 1
        sum += berat
        if berat <= 50:
            less50 += 1
        elif berat >= 100:
            more100 += 1
    berat = int(input())
if count == 0:
    print("Data kosong")
else:
    print(count)
    print(less50)
    print(more100)
    print(round(sum/count))

