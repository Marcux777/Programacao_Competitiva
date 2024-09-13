# versão em Python do programa em C++

Vinter = 0
Vgremio = 0
empate = 0
grenal = 1
igrenal = 0

while grenal == 1:
    igrenal += 1
    ginter, ggremio = map(int, input().split())
    if ginter > ggremio:
        Vinter += 1
    elif ginter < ggremio:
        Vgremio += 1
    else:
        empate += 1
    print("Novo grenal (1-sim 2-nao)")
    grenal = int(input())

print(f"{igrenal} grenais")
print(f"Inter:{Vinter}")
print(f"Gremio:{Vgremio}")
print(f"Empates:{empate}")

if Vinter > Vgremio:
    print("Inter venceu mais")
elif Vinter < Vgremio:
    print("Gremio venceu mais")
else:
    print("Nao houve vencedor")
