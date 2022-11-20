# Fawwaz Abrial Saffa / 16521115

# Program GambarSegitiga
# Input: N : integer
# Output: Jika N > 0 dan ganjil, gambar segitiga sesuai dengan N
#         Jika tidak, tampilkan pesan kesalahan: 

# KAMUS
# Variabel
#    N : int

def GambarSegitiga(N):
# I.S. N > 0 dan N ganjil
# F.S. Gambar segitiga dengan tinggi sebesar N sesuai spesifikasi soal
# Lengkapilah kamus lokal dan algoritma prosedur di bawah ini
    for i in range(N, 1, -2):
        print(' '*(i-1) + '*'*(N-i+1))
    print(N*'*')
    for i in range(3, N+1, 2):
        print(' '*(i-1) + '*'*(N-i+1))

def IsValid(N):
# menghasilkan true jika N positif dan ganjil, false jika tidak
# Lengkapilah kamus lokal dan algoritma fungsi di bawah ini
    return N > 0 and N % 2 == 1

# ALGORITMA PROGRAM UTAMA
N = int(input())
if (IsValid(N)):
    GambarSegitiga(N) 
else: # N tidak positif atau N tidak ganjil
    print("Masukan tidak valid")