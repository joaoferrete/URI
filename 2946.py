bin = input()
num = int(bin, 2)

qt = int(input())
lista = []
for i in range(qt):
    div = int(input())
    if num % div == 0:
        lista.append(div)
lista = sorted(lista)

if len(lista) == 0:
    print("Nenhum")
else:
    for i in range(len(lista)):
        if i!=len(lista)-1: print(lista[i], end=' ')
        else: print(lista[i])