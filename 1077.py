prec1 = "+-"
prec2 = "*/"
prec3 = "^"

def get_prec(op):
    if op in prec1:
        return 1
    if op in prec2:
        return 2
    if op in prec3:
        return 3
    if op == ')' or op == '(':
        return -1
    return 0

def toPosfixa(entrada):
    pilha = []
    saida = ''
    for i in entrada:
        if get_prec(i) == 0:
            saida += i
        elif i == '(' :
            pilha.append(i)
        elif i == ')':
            while pilha and pilha[-1] != '(':
                saida += pilha.pop()
            pilha.pop()
        else:
            while pilha and get_prec(pilha[-1]) >= get_prec(i):
                saida += pilha.pop()
            pilha.append(i)
    while pilha:
        saida += pilha.pop()
    return saida


casos = int(input())

for i in range(casos):
    entrada = input()
    print(toPosfixa(entrada))


