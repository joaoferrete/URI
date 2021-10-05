def verif(a):
    for i in range(len(a)-1):
        if a[i][0] != a[i+1][0]:
            return False
    return True

while(True):
    a = input().lower().split()
    if a[0] == "*": break

    if verif(a): print("Y")
    else: print("N")
