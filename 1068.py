def verifica_parenteses(expressao):
    pilha = []
    for parenteses in expressao:
        if parenteses == '(':
            pilha.append('(')
        elif parenteses == ')':
            if len(pilha) == 0:
                return False
            else:
                pilha.pop()
    if len(pilha) == 0:
        return True
    else:
        return False


while True:
    try:
        expressao = input()
        if verifica_parenteses(expressao):
            print('correct')
        else:
            print('incorrect')
    except EOFError:
        break
