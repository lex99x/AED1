// Interface de programa para cadastro de alunos

// Estrutura de um aluno

typedef struct{

	char nome[81];
	int matricula, turma;
	float p1, p2, p3;

} Aluno;

// Função que aloca espaço de memória e retorna endereço para um aluno

Aluno* init_aluno(void);

// Função que preenche cadastro e retorna vetor de ponteiros dos alunos

Aluno** preenche_cadastros(int n);

// Função que calcula e retorna a média de um aluno

float calc_media(Aluno* aluno);

// Função que imprime alunos aprovados

void imprime_aprovados(int n, Aluno** alunos);