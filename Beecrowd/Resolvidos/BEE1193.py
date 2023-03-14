# Obtenha a quantidade de casos de teste
n = int(input())

# Loop através de cada caso de teste
for i in range(1, n+1):
    # Obtenha o valor e o formato de entrada
    x, y = input().split()
    
    # Imprima o número de caso de teste
    print("Case {}:".format(i))
    
    # Verifique o formato de entrada
    if y == "bin":
        decimal = int(x, 2)
        print("{} dec".format(decimal))
        hexadecimal = hex(decimal)[2:]
        print("{} hex".format(hexadecimal))
    elif y == "dec":
        decimal = int(x)
        hexadecimal = hex(decimal)[2:]
        print("{} hex".format(hexadecimal))
        binary = bin(decimal)[2:]
        print("{} bin".format(binary))
    elif y == "hex":
        decimal = int(x, 16)
        print("{} dec".format(decimal))
        binary = bin(decimal)[2:]
        print("{} bin".format(binary))
    print()
