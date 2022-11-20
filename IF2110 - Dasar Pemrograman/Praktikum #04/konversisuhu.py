awal = float(input())
kode = input()

if kode=='R':
    akhir = awal * 4 / 5
elif kode=='F':
    akhir = (awal * 9 / 5) + 32
else:
    akhir = awal + 273.15

print('{:.2f}'.format(akhir))