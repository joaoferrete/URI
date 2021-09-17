alfa = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def decimalToBase32(decimal):
    base32 = ""
    while decimal > 0:
        base32 = alfa[decimal % 32] + base32
        decimal = decimal // 32
    return base32

numero = int(input())
while(numero != 0):
    print(decimalToBase32(numero))
    numero = int(input())
print("0")