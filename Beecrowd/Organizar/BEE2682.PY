# Convertido para Python:
anterior = -1
a = 0
while True:
    try:
        n = int(input())
        if n > anterior and a == 0:
            anterior = n
        else:
            a = 1
    except:
        break
print(anterior + 1)
