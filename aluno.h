#ifndef ALUNO_H
#define ALUNO_H

// Constantes
#define MAX_ALUNOS 100 // Limite máximo de alunos
#define TAM_NOME 50    // Tamanho máximo do nome do aluno
#define TAM_CURSO 50   // Tamanho máximo do curso
#define ARQUIVO "alunos.txt"

// Estrutura para representar um aluno
typedef struct {
    char nome[TAM_NOME];
    int idade;
    char curso[TAM_CURSO];
    float media;
} Aluno;

// Estrutura para gerenciar a lista de alunos
typedef struct {
    Aluno lista[MAX_ALUNOS];
    int total;
} GerenciadorAlunos;

// Protótipos das funções
void inicializarGerenciador(GerenciadorAlunos *g);
void adicionarAluno(GerenciadorAlunos *g);
void editarAluno(GerenciadorAlunos *g);
void removerAluno(GerenciadorAlunos *g);
void listarAlunos(const GerenciadorAlunos *g);
void carregarAlunos(GerenciadorAlunos *g);
void salvarAlunos(const GerenciadorAlunos *g);

#endif // ALUNO_H
