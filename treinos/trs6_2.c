// Enunciado
// Ordenando as notas do ENEM
// Alunos de uma certa região do país realizaram o ENEM, e suas notas foram colocadas
// em uma sequência S de inteiros. Parte das notas já foram ordenadas de forma crescente
// e estão contidas na subsequência S1. O restante das notas, ainda em desordem, está na
// subsequência S2.
// Escreva um programa que:
// Insira as notas de S2, na subsequência S1, mantendo S1 ordenada após cada inserção,
// (segundo o conceito de Estabilidade da Ordenação)1.
// Como saída, imprima em ordem crescente, todas as notas obtidas pelos alunos.
// Na entrada,
// os dois últimos dígitos da nota são suas casas decimais.
// Os dois primeiros valores indicam: i) o número total de elementos |S1| + |S2|,
// e ii) o número de elementos de S2.
// No final o programa deve imprimir o número de comparações e o número de movimentações.
// Use os textos “comparou: “ e “movimentou: “ antes dos valores correspondentes.
// Para melhor compreensão, veja o exemplo fornecido para esta questão.
// 1 Segundo este conceito a ordem dos valores iguais no vetor ordenado,
// é definido pela ordem com que aparecem no vetor já ordenado.
// Exemplo de Entrada
// 6 5
// 97054
// 97053 83296 12453 7871 3240
// Exemplo de Saída
// 32.40 78.71 124.53 832.96 970.53 970.54
// comparou: 8
// movimentou: 15