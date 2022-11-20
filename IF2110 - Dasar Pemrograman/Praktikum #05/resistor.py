valid = True
while(valid):
    R1 = float(input())
    R2 = float(input())
    R3 = float(input())
    kode = input()

    if(R1<=0 or R2<=0 or R3<=0 or (kode!='s' and kode!='S' and kode!='p' and kode!='P')):
        print("Masukan salah")
    else:
        valid = False

if(kode=='S' or kode=='s'):
    ans = R1+R2+R3
else:
    ans = ((R1*R2*R3)/(R1*R2+R1*R3+R2*R3))
print('{:.2f}'.format(round(ans, 2)))