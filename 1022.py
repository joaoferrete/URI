def mdc(n1, n2):
    while n2 != 0:
        r = n1%n2
        n1 = n2
        n2 = r
    return n1

n = int(input())

for i in range(n):
    ent = input().split()

    n1, d1, n2, d2 = int(ent[0]), int(ent[2]), int(ent[4]), int(ent[6])

    if ent[3] == '+':
        n = (n1 * d2) + (n2 * d1)
        d = d1 * d2
    elif ent[3] == '-':
        n = (n1 * d2) - (n2 * d1)
        d = d1 * d2
    elif ent[3] == '*':
        n = (n1 * n2)
        d = d1 * d2
    elif ent[3] == '/':
        n = (n1 * d2)
        d = (n2*d1)
    
    x = mdc(n, d)
    print(f"{n}/{d} = {int(n/x)}/{int(d/x)}")
