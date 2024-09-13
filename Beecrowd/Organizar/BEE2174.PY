n = int(input())
capturados = set()
for i in range(n):
    capturados.add(input())

faltam = 151 - len(capturados)
print(f"Falta(m) {faltam} pomekon(s).")
