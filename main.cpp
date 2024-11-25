#include "main.h"
#include "menu.h"
#include "aluno.h"

int main() {
    GerenciadorAlunos gerenciador;
    inicializarGerenciador(&gerenciador);
    carregarAlunos(&gerenciador);
    menu_ini(&gerenciador);
    return 0;
}
