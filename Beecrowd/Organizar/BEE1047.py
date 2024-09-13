from math import floor
lista = input().split()
a = int(lista[0])
b = int(lista[1])
c = int(lista[2])
d = int(lista[3])
min1 = a*60 + b
min2 = c*60 + d
if a == b == c == d:
    print("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)")
elif min1 < min2:
    dif = min2 - min1
    h = dif/60
    mints = (dif % 60)
    print('O JOGO DUROU {} HORA(S) E {} MINUTO(S)'.format(floor(h), mints))
elif a == c:
    dif = b - d
    h =
