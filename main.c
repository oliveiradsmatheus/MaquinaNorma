#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <windows.h>
#include <string.h>
#include "bibliotecas\\moldura.h"
#include "bibliotecas\\operacoes.h"

char menu(void) {	
	Operacao(" # # # Menu # # #");
	ExibeTexto(120,10,0,14,"Selecione uma opcao:","");
	ExibeTexto(120,16,0,14,"[1] - A := A + B","");
	ExibeTexto(120,20,0,14,"[2] - A := A + B usando C (O conteudo de B sera mantido)","");
	ExibeTexto(120,24,0,14,"[3] - A := B usando C (O conteudo de B sera mantido)","");
	ExibeTexto(120,28,0,14,"[4] - A := A x B usando C, D (O conteudo de B sera mantido)","");
	ExibeTexto(120,33,0,14,"[Sair]","");
	textbackground(7);
    return getch();
}

void executa(void) {
    Reg A, B, C, D;
    char elem[50], op;

    do {
        op = menu();
        LimparCaixa();
        switch (op) {
            case '1':
                soma();
                break;
            case '2':
                somaPreservandoB();
                break;
            case '3':
            	atribuicao();
                break;
            case '4':
                multiplicacao();
        }
        if(op != 27){
        	Entrada("Pressione qualquer tecla para continuar");
        	getch();
        	LimpaEntrada();
        	LimparCaixa();
		}
    } while (op != 27);
}

int main (void) {
	iniciarTela();
	executa();
	MsgFim();
	return 0;
}
