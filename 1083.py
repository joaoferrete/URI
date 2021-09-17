operadores = "|.<>=#+-*/^"
operandos = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

def lexicalError(ent):
    for i in ent:
        if (i not in operadores) and (i not in operandos) and (i not in '()'):
            return True
    
    return False

def syntaxError(ent):
    global operadores, operandos
    
    parenteses = []

    if len(ent) == 1 and ent in operadores or ent in '()': return True
    
    for i in range(len(ent)-1):
        if ent[i] == '(' and ent[i+1] == ')': return True
        if ent[i] == "(":  parenteses.append(ent[i])
        elif ent[i] == ")":
            if parenteses: parenteses.pop()
            else: return True
        elif ent[i] in operadores and ent[i+1] in operadores: return True
        elif ent[i] in operandos and ent[i+1] in operandos: return True

    if ent[-1] == ")": parenteses.pop()
    if len(parenteses)>0: return True
    return False


def get_prec(op):
    if op in '|': return 1
    if op in '.': return 2
    if op in '<>=#': return 3
    if op in '+-': return 4
    if op in '*/': return 5
    if op in '^': return 6
    if op in '()': return -1
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



while(True):
    try:
        ent = input()
        if lexicalError(ent): print("Lexical Error!")
        elif syntaxError(ent): print("Syntax Error!")
        else: print(toPosfixa(ent))

    except EOFError:
        break