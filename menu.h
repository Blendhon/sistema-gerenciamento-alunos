#ifndef MENU_H
#define MENU_H

#include "aluno.h" // Inclui as funções relacionadas aos alunos

// Protótipos das funções do menu

/**
 * Reseta o menu principal, permitindo retornar ou sair do programa.
 */
void reset();

/**
 * Exibe o título principal do programa.
 */
void titulo();

/**
 * Exibe o menu inicial e gerencia as opções de interação do usuário.
 */
void menu_ini(GerenciadorAlunos *gerenciador);

#endif // MENU_H

