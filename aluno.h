#ifndef ALUNO_H
#define ALUNO_H

// Constantes
#define MAX_ALUNOS 100 // Limite m�ximo de alunos
#define TAM_NOME 50    // Tamanho m�ximo do nome do aluno
#define TAM_CURSO 50   // Tamanho m�ximo do curso

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

// Prot�tipos das fun��es

/**
 * Inicializa o gerenciador de alunos.
 * 
 * @param g Ponteiro para a estrutura GerenciadorAlunos que ser� inicializada.
 */
void inicializarGerenciador(GerenciadorAlunos *g);

/**
 * Adiciona um novo aluno ao gerenciador.
 * 
 * @param g Ponteiro para a estrutura GerenciadorAlunos onde o aluno ser� adicionado.
 */
void adicionarAluno(GerenciadorAlunos *g);

/**
 * Edita as informa��es de um aluno j� cadastrado.
 * 
 * @param g Ponteiro para a estrutura GerenciadorAlunos onde o aluno ser� editado.
 */
void editarAluno(GerenciadorAlunos *g);

/**
 * Remove um aluno pelo nome.
 * 
 * @param g Ponteiro para a estrutura GerenciadorAlunos onde o aluno ser� removido.
 */
void removerAluno(GerenciadorAlunos *g);

/**
 * Lista todos os alunos cadastrados.
 * 
 * @param g Ponteiro para a estrutura GerenciadorAlunos a ser listada.
 */
void listarAlunos(const GerenciadorAlunos *g);

#endif // ALUNO_H
