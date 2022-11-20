# Fawwaz Abrial Saffa / 16521115

# PROGRAM Tabungan
# { Program menerima input N yaitu jumlah tabungan dan kemudian diberikan N buah input yaitu nilai uang yang ditabung. Output adalah total dari seluruh nilai tabungan }

# KAMUS
# N, tab, jumlah : int

# ALGORITMA
N = int(input())
jumlah = 0

for i in range(N):
    tab = int(input())
    jumlah += tab
print(jumlah)