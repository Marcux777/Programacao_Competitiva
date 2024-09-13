n = int(input())

for i in range(n):
    s = input()
    print(s[:len(s)//2][::-1] + s[len(s)//2:][::-1])#A string é dividida ao meio (arredondando para baixo se o comprimento for ímpar).
    #A primeira metade da string é invertida (usando a sintaxe de fatiamento e a função [::-1], que inverte a ordem dos elementos em uma sequência).
    #A segunda metade da string é invertida da mesma forma. No fim, são concatenadas.
