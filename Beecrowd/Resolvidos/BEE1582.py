import math

def E_Primo(x, y, z):
    div = 2
    mdc = True
    while div <= x:
        if x % div == 0 and y % div == 0 and z % div == 0:
            mdc = False
        div += 1
    return mdc

while True:
    try:
        a, b, c = map(int, input().split())
    except:
        break
    
    if a > b:
        if a > c:
            if b < c:
                aux = b
                b = c
                c = aux
        else:
            aux = a
            a = c
            c = aux
            aux = b
            b = c
            c = aux
    elif b > a:
        aux = a
        a = b
        b = aux
        if a < c:
            aux = a
            a = c
            c = aux
            aux = b
            b = c
            c = aux
        if b < c:
            aux = b
            b = c
            c = aux
    else:
        aux = a
        a = c
        c = aux
        if b < c:
            aux = b
            b = c
            c = aux

    if a * a == b * b + c * c:
        if E_Primo(a, b, c):
            print("tripla pitagorica primitiva")
        else:
            print("tripla pitagorica")
    else:
        print("tripla")
