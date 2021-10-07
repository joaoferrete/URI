def valor(dig):
    if dig == '1': return 2
    if dig == '2' or dig == '3' or dig == '5': return 5
    if dig == '4': return 4
    if dig == '6' or dig == '9' or dig == '0': return 6
    if dig == '7': return 3
    if dig == '8': return 7


num = int(input())

while(num > 0):
    numero = input()
    soma = 0
    for digito in numero:    
        soma += valor(digito)
    print(f"{soma} leds")

    num -= 1