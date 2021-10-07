letraMaiuscula = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
letraMinuscula = "abcdefghijklmnopqrstuvwxyz"
numero = "0123456789"

def TemletraMaiuscula(palavras):
    for palavra in palavras:
        if palavra in letraMaiuscula:
            return True
    return False

def TemletraMinuscula(palavras):
    for palavra in palavras:
        if palavra in letraMinuscula:
            return True
    return False

def Temnumero(palavras):
    for palavra in palavras:
        if palavra in numero:
            return True
    return False

def caracteres(palavras):
    for palavra in palavras:
        if palavra not in letraMaiuscula and palavra not in letraMinuscula and palavra not in numero:
            return True
    return False

while(True):
    try:
        s = input()
        if len(s)<6 or len(s)>32 or not TemletraMaiuscula(s) or not TemletraMinuscula(s) or not Temnumero(s) or caracteres(s):
            print("Senha invalida.")
        else:
            print("Senha valida.")
    except EOFError:
        break