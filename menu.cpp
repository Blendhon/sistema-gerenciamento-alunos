#include "main.h"

void reset(GerenciadorAlunos *gerenciador) {
	int t;
	
	printf("\n\n--------------------------------\n\n"
		"Precione [ENTER] para voltar ou [ESC] para fechar o programa.");
	
	while(1) {
		if( kbhit() ) {
			
			t = getch();
			
			if ( t == 13 ) {
				menu_ini(gerenciador);
				return;
			}
			
			if ( t == 27 ) {
				printf("\nEncerrando o programa...\n");
				exit(0);
			}
		}
    }
}

void titulo() {
	system("cls");
	printf("--------------------------------\n\n"
		"   LINGUAGENS DE PROGRAMACAO\n"
		"  SIS. GERENCIAMENTO DE ALUNOS\n"
		"    ALUNOS: BLENDHON E BRUNO\n"
		"\n--------------------------------\n\n");
}

void menu_ini(GerenciadorAlunos *gerenciador) {
	int opc = 0;
	int tecla;
	    
	while (1) {
		titulo();
		
		if ( opc == 0 )
			printf("\n  ->  Listar Alunos\n");
		else
			printf("\n     Listar Alunos\n");
		
		if ( opc == 1 )
			printf("\n  ->  Adicionar Aluno");
		else
			printf("\n     Adicionar Aluno");
		
		if ( opc == 2 )
			printf("\n  ->  Editar Aluno");
		else
			printf("\n     Editar Aluno");
		
		if ( opc == 3 )
			printf("\n  ->  Remover Aluno\n");
		else
			printf("\n     Remover Aluno\n");
		
		if ( opc == 4 )
			printf("\n  ->  Sair\n");
		else
			printf("\n     Sair\n");

        tecla = _getch();

        switch (tecla) {
            case 224:
                tecla = _getch();
                if (tecla == 72) {
                    opc = (opc - 1 + 5) % 5;  // Move para cima com volta
                } else if (tecla == 80) {
                    opc = (opc + 1) % 5;  // Move para baixo com volta
                } else if (tecla == 75) {
                    opc = (opc - 1 + 5) % 5; // Move para a esquerda com volta
                } else if (tecla == 77) {
                    opc = (opc + 1) % 5;  // Move para a direita com volta
                }
            break;
            
            case 13:
				switch (opc) {
		            case 0:
		            	titulo();
		            	listarAlunos(gerenciador);
		            	reset(gerenciador);
		            	return;
		            break;
		            
		            case 1:
		            	titulo();
		            	adicionarAluno(gerenciador);
						reset(gerenciador);
						return;
					break;
					
					case 2:
						titulo();
						editarAluno(gerenciador);
						reset(gerenciador);
		                return;
		            break;
		            
		            case 3:
		            	titulo();
		            	removerAluno(gerenciador);
						reset(gerenciador);
						return;
					break;
										
					case 4:
						titulo();
						printf("\nSalvando dados e saindo...\n");
                		salvarAlunos(gerenciador);
						printf("\n\n--------------------------------\n\n"
							"Precione qualquer tecla para fechar o programa.");
						
						while(1) {
							if( kbhit() ) {								
								if ( getch() ) {
									printf("\nEncerrando o programa...\n");
									exit(0);
								}
							}
					    }
					    
						return;
					break;
		        }
			break;
        }
    }
}

