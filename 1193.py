alfa = "0123456789abcdefgh"

def converte(num, base):
    if num < base:
        return alfa[num]
    else:
        return converte(num//base, base) + alfa[num%base]

def base10(num, base):
    if len(num) == 1:
        return alfa.index(num)
    else:
        return base10(num[:-1], base) * base + alfa.index(num[-1])

numero = int(input())

for i in range(1, numero+1):
    entrada = input().split()
    print(f"Case {i}:")
    if entrada[1] == "bin":
        dec = base10(entrada[0], 2)
        print(f"{dec} dec")
        print(f"{converte(dec, 16)} hex")
    elif entrada[1] == "hex":
        dec = base10(entrada[0], 16)
        print(f"{dec} dec")
        print(f"{converte(dec, 2)} bin")
    else:
        dec = int(entrada[0])
        print(f"{converte(dec, 16)} hex")
        print(f"{converte(dec, 2)} bin")
    print()