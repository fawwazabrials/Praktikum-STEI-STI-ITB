haha = 10
for i in range(1, 68):
    if(haha%2==0): haha/=2
    else: haha = (3*haha + 1)
    print(i, haha)