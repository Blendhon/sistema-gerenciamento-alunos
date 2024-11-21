#ifndef ALUNO_H
#define ALUNO_H

// Constantes
#define MAX_ALUNOS 100 // Limite máximo de alunos
#define TAM_NOME 50    // Tamanho máximo do nome do aluno
#define TAM_CURSO 50   // Tamanho máximo do curso

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

/**
 * Inicializa o gerenciador de alunos.
 * 
 * @param g Ponteiro para a estrutura GerenciadorAlunos que será inicializada.
 */
void inicializarGerenciador(GerenciadorAlunos *g);

/**
 * Adiciona um novo aluno ao gerenciador.
 * 
 * @param g Ponteiro para a estrutura GerenciadorAlunos onde o aluno será adicionado.
 */
void adicionarAluno(GerenciadorAlunos *g);

/**
 * Edita as informações de um aluno já cadastrado.
 * 
 * @param g Ponteiro para a estrutura GerenciadorAlunos onde o aluno será editado.
 */
void editarAluno(GerenciadorAlunos *g);

/**
 * Remove um aluno pelo nome.
 * 
 * @param g Ponteiro para a estrutura GerenciadorAlunos onde o aluno será removido.
 */
void removerAluno(GerenciadorAlunos *g);

/**
 * Lista todos os alunos cadastrados.
 * 
 * @param g Ponteiro para a estrutura GerenciadorAlunos a ser listada.
 */
void listarAlunos(const GerenciadorAlunos *g);

#endif // ALUNO_H
