suhu = int(input())

if suhu < 0:
    print("PADAT")
elif suhu == 0:
    print("ANTARA PADAT-CAIR")
elif suhu == 100:
    print("ANTARA CAIR-GAS")
elif 0 < suhu < 100:
    print("CAIR")
else:
    print("GAS")