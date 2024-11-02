def calcular_soma_distancias(t, casos):
    resultados = []
    for i in range(t):
        n, m, r, c = casos[i]
        # Calcula a posição em ordem row-major
        pos = (r - 1) * m + c
        
        # Calcula floor((pos -1)/m)
        floor_div = (pos - 1) // m
        
        # Número de movimentos com distância m
        mov_m = (n - 1) - floor_div
        
        # Número de movimentos com distância 1
        mov_1 = (n * m - pos) - mov_m
        
        # Soma das distâncias
        soma = mov_1 * 1 + mov_m * m
        resultados.append(soma)
    return resultados

# Exemplo de uso:
if __name__ == "__main__":
    import sys

    # Leitura da entrada
    t = int(sys.stdin.readline())
    casos = []
    for _ in range(t):
        linha = sys.stdin.readline()
        while linha.strip() == '':
            linha = sys.stdin.readline()
        n, m, r, c = map(int, linha.strip().split())
        casos.append((n, m, r, c))
    
    # Cálculo das somas
    resultados = calcular_soma_distancias(t, casos)
    
    # Impressão dos resultados
    for res in resultados:
        print(res)
