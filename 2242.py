vogal = "aeiouAEIOU"

risada = input()

vogais = [i for i in risada if i in vogal]

if vogais == vogais[::-1]:
    print("S")
else:
    print("N")