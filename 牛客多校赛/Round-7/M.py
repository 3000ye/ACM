T = int(input())
for _ in range(T):
    n = int(input())

    x = len(str(n)) - 1
    y = n % (pow(10, x))

    res = 0
    for i in range(1, x + 1):
        res += i * 9 * (pow(10, i - 1))
    
    res += (x + 1) * y
    print(res)