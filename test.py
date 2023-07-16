ls = list()

for i in range(0, 7):
    x = pow(5, i)

    ls.append(bin(x)[2:])

print(ls[:: -1])