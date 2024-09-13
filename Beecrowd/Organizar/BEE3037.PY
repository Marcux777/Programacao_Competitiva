# Recebe o número de casos de teste
n = int(input())

# Loop para cada caso de teste
for i in range(n):
    # Inicializa as pontuações dos jogadores
    pontuacao_joao = 0
    pontuacao_maria = 0

    # Loop para ler as jogadas de João
    for j in range(3):
        x, d = map(int, input().split())
        pontuacao_joao += x * d

    # Loop para ler as jogadas de Maria
    for j in range(3):
        x, d = map(int, input().split())
        pontuacao_maria += x * d

    # Verifica qual jogador ganhou
    if pontuacao_joao > pontuacao_maria:
        print("JOAO")
    elif pontuacao_maria > pontuacao_joao:
        print("MARIA")
    else:
        print("JOAO")
