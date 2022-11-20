n = int(input())
c1 = input()
c2 = input()

if (c1 == c2) | (n <= 0):
    print("Masukan tidak valid")
else:
    for it in range(n):
        ans = ""
        if (it == 0) | (it == (n-1)):
            for i in range(n): ans += c1
        else:
            for i in range(n):
                if (i == 0) | (i == (n-1)): ans += c1
                else: ans += c2
        print(ans)