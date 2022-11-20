N = -1
while (N <= 0 or N > 100): 
    N=int(input())
    if (N <= 0 or N > 100):
        print("Masukan salah. Ulangi!")
bilangan = [0 for i in range(N)]
for i in range(N):
    bilangan[i] = int(input())


X = int(input())

found = False
loc = 0
bil = 0
if X == 0:
    for i in range(N):
        if(bilangan[i] == 0):
            found = True
            loc = i+1
            bil = bilangan [i]
            break
    if(found):
        print(loc)
    else: print("Tidak ada 0")
elif X == -1:
    for i in range(N):
        if(bilangan[i] < 0):
            found = True
            loc = i+1
            bil = bilangan [i]
            break
    if(found):
        print(loc, bil)
    else: print("Tidak ada negatif")
elif X == 1:
    for i in range(N):
        if(bilangan[i] > 0):
            found = True
            loc = i+1
            bil = bilangan [i]
            break
    if(found):
        print(loc, bil)
    else: print("Tidak ada positif")
else:
    print("Tidak diproses")