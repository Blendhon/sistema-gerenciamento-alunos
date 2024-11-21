#ifndef MENU_H
#define MENU_H

#include "aluno.h" // Inclui as fun��es relacionadas aos alunos

// Prot�tipos das fun��es do menu

/**
 * Reseta o menu principal, permitindo retornar ou sair do programa.
 */
void reset();

/**
 * Exibe o t�tulo principal do programa.
 */
void titulo();

/**
 * Exibe o menu inicial e gerencia as op��es de intera��o do usu�rio.
 */
void menu_ini(GerenciadorAlunos *gerenciador);

#endif // MENU_H

