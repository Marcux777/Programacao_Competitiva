/*É o ano 3002. Os robôs da "ROBOTS'R US (R:US)" assumiram o controle do mundo. 
Você é uma das poucas pessoas que permanecem vivas apenas para agir como 
cobaias deles. De tempos em tempos, os robôs o usam para descobrir se conseguiram
 se tornar mais inteligentes. Você, sendo o cara esperto, sempre teve sucesso em provar
  ser mais inteligente.
Hoje é o seu grande dia. Se você conseguir vencer o robô mais rápido
 na terra IRQ2003, estará livre.
Esses robôs são inteligentes. No entanto, eles não conseguiram superar uma 
grande deficiência em seu design físico - eles só podem 
se mover em 4 direções: Para frente, Para trás, Para cima e Para baixo. 
Eles levam 1 unidade de tempo para percorrer 1 unidade de distância. 
Como você só tem uma chance, está planejando cuidadosamente. 
Os robôs deixaram um dos robôs mais rápidos para te vigiar. 
Você precisará programar outro robô que o leve através do terreno acidentado. 
Uma parte crucial do seu plano requer que você descubra quanto tempo o 
robô de guarda precisará para alcançar seu destino. 
Se você conseguir vencê-lo, estará livre.Bombas! Não, são minas.
Cenário de entrada de exemplo
S- origem, D- destino
Devemos avisá-lo de que a terra IRQ2003 não é um lugar agradável para perambular. 
A R:US largou inúmeras bombas enquanto invadiam a terra dos humanos. 
A maioria das bombas explodiu. Ainda assim, algumas das bombas permanecem 
agindo como minas terrestres. Conseguimos obter um mapa que mostra as regiões 
inseguras da terra IRQ2003; infelizmente, o seu guarda também tem uma cópia do mapa. 
Sabemos que no máximo 40% da área pode ser insegura. Se você quiser vencer o seu guarda,
 terá que encontrar a rota mais rápida dele muito antes que ele a encontre.
Entrada
A entrada consiste em vários casos de teste. 
Cada teste começa com dois inteiros R (1 ≤ R ≤ 1000), C (1 ≤ C ≤ 1000) - 
eles dão o número total de linhas e colunas no mapa de grade da terra. 
Em seguida, seguem as localizações na grade das bombas. Começa com o número de linhas, 
(0 ≤ linhas ≤ R) contendo bombas. Para cada uma das linhas, você terá uma linha de entrada. 
Essas linhas começam com o número da linha, seguido pelo número de bombas nessa linha. 
Em seguida, você terá as localizações das colunas daquelas bombas naquela linha. 
O caso de teste termina com a localização inicial (linha, coluna) seguida pelo seu destino (linha, coluna). 
Todos os pontos na região estão no intervalo (0, 0) a (R − 1, C − 1). 
A entrada termina com um caso de teste onde R = 0 e C = 0, você não deve processar este caso de teste.

Saída
Para cada caso de teste, imprima o tempo que o robô de guarda levaria para 
ir da localização inicial ao destino.*/