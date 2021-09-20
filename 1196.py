s1 = "`1234567890-="
s2 = "QWERTYUIOP[]\ "
s2 = s2.replace(" ", "")
s3 = "ASDFGHJKL;'"
s4 = "ZXCVBNM,./"

while(True):
    try:
        ent = input()
        saida = ""
        for i in ent:
            if i in s1:
                saida += s1[(s1.index(i)-1)%len(s1)]
            elif i in s2:
                saida += s2[(s2.index(i)-1)%len(s2)]
            elif i in s3:
                saida += s3[(s3.index(i)-1)%len(s3)]
            elif i in s4:
                saida += s4[(s4.index(i)-1)%len(s4)]
            else:
                saida += i
        print(saida)
    except:
        break
