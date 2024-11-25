#include "main.h"

// Inicializa o gerenciador de alunos
void inicializarGerenciador(GerenciadorAlunos *g) {
	g->total = 0;
}

// Adiciona um aluno ao gerenciador
void adicionarAluno(GerenciadorAlunos *g) {
	if (g->total >= MAX_ALUNOS) {
		printf("\nNao e possivel adicionar mais alunos. Lista cheia.\n");
		return;
	}
	
	Aluno novo;
	printf("\nDigite o nome do aluno: ");
	fgets(novo.nome, TAM_NOME, stdin);
	novo.nome[strcspn(novo.nome, "\n")] = '\0';
	
	printf("Digite a idade do aluno: ");
	scanf("%d", &novo.idade);
	getchar();
	
	printf("Digite o curso do aluno: ");
	fgets(novo.curso, TAM_CURSO, stdin);
	novo.curso[strcspn(novo.curso, "\n")] = '\0';
	
	printf("Digite a media do aluno: ");
	scanf("%f", &novo.media);
	getchar();
	
	g->lista[g->total++] = novo;
	printf("\nAluno adicionado com sucesso!\n");
}

// Edita um aluno pelo nome
void editarAluno(GerenciadorAlunos *g) {
	char nome[TAM_NOME];
	printf("\nDigite o nome do aluno a ser editado: ");
	fgets(nome, TAM_NOME, stdin);
	nome[strcspn(nome, "\n")] = '\0';
	
	for (int i = 0; i < g->total; i++) {
		if (strcmp(g->lista[i].nome, nome) == 0) {
			printf("Digite os novos dados para o aluno:\n");
			
			printf("Nome: ");
			fgets(g->lista[i].nome, TAM_NOME, stdin);
			g->lista[i].nome[strcspn(g->lista[i].nome, "\n")] = '\0';
			
			printf("Idade: ");
			scanf("%d", &g->lista[i].idade);
			getchar();
			
			printf("Curso: ");
			fgets(g->lista[i].curso, TAM_CURSO, stdin);
			g->lista[i].curso[strcspn(g->lista[i].curso, "\n")] = '\0';
			
			printf("Media: ");
			scanf("%f", &g->lista[i].media);
			getchar();
			
			printf("Aluno editado com sucesso!\n");
			return;
		}
	}
	printf("Aluno nao encontrado.\n");
}

// Remove um aluno pelo nome
void removerAluno(GerenciadorAlunos *g) {
	char nome[TAM_NOME];
	printf("\nDigite o nome do aluno a ser removido: ");
	fgets(nome, TAM_NOME, stdin);
	nome[strcspn(nome, "\n")] = '\0';
	
	for (int i = 0; i < g->total; i++) {
		if (strcmp(g->lista[i].nome, nome) == 0) {
			for (int j = i; j < g->total - 1; j++) {
				g->lista[j] = g->lista[j + 1];
			}
			g->total--;
			printf("Aluno removido com sucesso!\n");
			return;
		}
	}
	printf("Aluno nao encontrado.\n");
}

// Lista todos os alunos
void listarAlunos(const GerenciadorAlunos *g) {
	if (g->total == 0) {
		printf("\nNenhum aluno cadastrado.\n");
		return;
	}

	printf("\nLista de alunos:\n");
	for (int i = 0; i < g->total; i++) {
		printf("Nome: %s | Idade: %d | Curso: %s | Media: %.2f\n",
		g->lista[i].nome, g->lista[i].idade, g->lista[i].curso, g->lista[i].media);
	}
}

// Carrega alunos de um arquivo
void carregarAlunos(GerenciadorAlunos *g) {
    FILE *file = fopen(ARQUIVO, "r");
    if (!file) {
        printf("Nenhum arquivo encontrado. Uma nova lista sera criada.\n");
        return;
    }

    while (fscanf(file, "%49[^\n]%*c %d %49[^\n]%*c %f%*c",
                  g->lista[g->total].nome,
                  &g->lista[g->total].idade,
                  g->lista[g->total].curso,
                  &g->lista[g->total].media) == 4) {
        g->total++;
        if (g->total >= MAX_ALUNOS) {
            printf("A lista atingiu o limite maximo de alunos durante a leitura do arquivo.\n");
            break;
        }
    }

    fclose(file);
    printf("Dados carregados com sucesso! %d aluno(s) encontrado(s).\n", g->total);
}

// Salva alunos em um arquivo
void salvarAlunos(const GerenciadorAlunos *g) {
    FILE *file = fopen(ARQUIVO, "w");
    if (!file) {
        printf("Erro ao salvar os dados!\n");
        return;
    }

    for (int i = 0; i < g->total; i++) {
        fprintf(file, "%s\n%d\n%s\n%.2f\n",
                g->lista[i].nome,
                g->lista[i].idade,
                g->lista[i].curso,
                g->lista[i].media);
    }

    fclose(file);
    printf("Dados salvos com sucesso!\n");
}
