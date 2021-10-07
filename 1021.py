num = float(input())

print("NOTAS:")
print(f"{num//100:.0f} nota(s) de R$ 100.00")
n = num % 100
print(f"{n//50:.0f} nota(s) de R$ 50.00")
n = n % 50
print(f"{n//20:.0f} nota(s) de R$ 20.00")
n = n % 20
print(f"{n//10:.0f} nota(s) de R$ 10.00")
n = n % 10
print(f"{n//5:.0f} nota(s) de R$ 5.00")
n = n % 5
print(f"{n//2:.0f} nota(s) de R$ 2.00")
n = n % 2
print(f"MOEDAS:")
print(f"{n//1:.0f} moeda(s) de R$ 1.00")
n = n % 1
print(f"{n//0.50:.0f} moeda(s) de R$ 0.50")
n = round(n % 0.50, 2)
print(f"{n//0.25:.0f} moeda(s) de R$ 0.25")
n = round(n % 0.25, 2)
print(f"{n//0.10:.0f} moeda(s) de R$ 0.10")
n = round(n % 0.10, 2)
print(f"{n//0.05:.0f} moeda(s) de R$ 0.05")
n = n % 0.05
print(f"{n*100:.0f} moeda(s) de R$ 0.01")

