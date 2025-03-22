#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

struct reg {
    char s;
    int num;
};
typedef struct reg Reg;

void leitura(Reg *reg, char nomeReg) {
    printf("Informe o valor de %c: ", toupper(nomeReg));
    scanf("%d", &(*reg).num);
    if ((*reg).num > 0)
        (*reg).s = 0;
    else
        (*reg).s = 1;
}

void soma(Reg *A, Reg *B) {
    printf("| A: %d | B: %d |\n", (*A).num, (*B).num);
    if ((*B).s == 0) {
        // B positivo
        while ((*B).num != 0) {
            (*A).num++;
            (*B).num--;
            printf("| A: %d | B: %d |\n", (*A).num, (*B).num);
        }
    } else {
        // B negativo
        while ((*B).num != 0) {
            (*A).num--;
            (*B).num++;
            printf("| A: %d | B: %d |\n", (*A).num, (*B).num);
        }
    }
    printf("\n");
}

void somaPreservandoB(Reg *A, Reg *B, Reg *C) {
    printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
    if ((*B).s == 0) {
        // B positivo
        while ((*B).num != 0) {
            (*B).num--;
            (*C).num++;
            printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
        }
        printf("\n");
        printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
        while ((*C).num != 0) {
            (*A).num++;
            (*B).num++;
            (*C).num--;
            printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
        }
    } else {
        // B negativo
        while ((*B).num != 0) {
            (*B).num++;
            (*C).num++;
            printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
        }
        printf("\n");
        printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
        while ((*C).num != 0) {
            (*A).num--;
            (*B).num--;
            (*C).num--;
            printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
        }
    }
    printf("\n");
}

void atribuicao(Reg *A, Reg *B, Reg *C) {
    printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
    if ((*A).s == 0) {
        while ((*A).num != 0) {
            (*A).num--;
            printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
        }
        printf("\n");
        printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
        if ((*B).s == 0) {
            // A e B positivos
            while ((*B).num != 0) {
                (*B).num--;
                (*C).num++;
                printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
            }
        	printf("\n");
            printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
            while ((*C).num != 0) {
                (*A).num++;
                (*B).num++;
                (*C).num--;
                printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
            }
        } else {
            // A positivo e B negativo
            while ((*B).num != 0) {
                (*B).num++;
                (*C).num++;
                printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
            }
        	printf("\n");
            printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
            while ((*C).num != 0) {
                (*A).num--;
                (*B).num--;
                (*C).num--;
                printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
            }
        }
    } else {
        while ((*A).num != 0) {
            (*A).num++;
            printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
        }
        printf("\n");
        printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
        if ((*B).s == 0) {
            // A negativo e B positivo
            while ((*B).num != 0) {
                (*B).num--;
                (*C).num++;
                printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
            }
        	printf("\n");
            printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
            while ((*C).num != 0) {
                (*A).num++;
                (*B).num++;
                (*C).num--;
                printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
            }
        } else {
            // A e B negativos
            while ((*B).num != 0) {
                (*B).num++;
                (*C).num++;
                printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
            }
        	printf("\n");
            printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
            while ((*C).num != 0) {
                (*A).num--;
                (*B).num--;
                (*C).num--;
                printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
            }
        }
    }
    printf("\n");
}

void multiplicacao(Reg *A, Reg *B, Reg *C, Reg *D) {
    if ((*A).s == 0) {
        if ((*B).s == 0) {
            // A e B positivos
            while ((*A).num != 0) {
    			printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
                while ((*B).num != 0) {
                    (*B).num--;
                    (*C).num++;
                    (*D).num++;
    				printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
                }
    			printf("\n");
    			printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
                while ((*C).num != 0) {
                    (*B).num++;
                    (*C).num--;
    				printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
                }
    			printf("\n");
                (*A).num--;
            }
    		printf("\n");
    		printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
            while ((*D).num != 0) {
                (*A).num++;
                (*D).num--;
    			printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
            }
        } else {
            // A positivo e B negativo
            while ((*A).num != 0) {
    			printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
                while ((*B).num != 0) {
                    (*B).num++;
                    (*C).num++;
                    (*D).num++;
    				printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
                }
    			printf("\n");
    			printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
                while ((*C).num != 0) {
                    (*B).num--;
                    (*C).num--;
    				printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
                }
                (*A).num--;
            }
    		printf("\n");
    		printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
            while ((*D).num != 0) {
                (*A).num--;
                (*D).num--;
    			printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
            }
        }
    } else {
        if ((*B).s == 0) {
            // A negativo e B positivo
            while ((*A).num != 0) {
    			printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
                while ((*B).num != 0) {
                    (*B).num--;
                    (*C).num++;
                    (*D).num++;
    				printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
                }
    			printf("\n");
    			printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
                while ((*C).num != 0) {
                    (*B).num++;
                    (*C).num--;
    				printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
                }
                (*A).num++;
            }
    		printf("\n");
    		printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
            while ((*D).num != 0) {
                (*A).num--;
                (*D).num--;
    			printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
            }
        } else {
            // A e B negativos
            while ((*A).num != 0) {
    			printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
                while ((*B).num != 0) {
                    (*B).num++;
                    (*C).num++;
                    (*D).num++;
    				printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
                }
    			printf("\n");
    			printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
                while ((*C).num != 0) {
                    (*B).num--;
                    (*C).num--;
    				printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
                }
                (*A).num++;
            }
    		printf("\n");
    		printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
            while ((*D).num != 0) {
                (*A).num++;
                (*D).num--;
    			printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
            }
        }
    }
    printf("\n");
}

char menu(void) {
    printf("Selecione uma opcao:\n");
    printf("[1] - A := A + B\n");
    printf("[2] - A := A + B usando C (O conteudo de B sera mantido)\n");
    printf("[3] - A := B usando C (O conteudo de B sera mantido)\n");
    printf("[4] - A := A x B usando C, D (O conteudo de B sera mantido)\n");
    printf("[Sair]\n");
    return getch();
}

int main(void) {
    Reg A, B, C, D;
    char op;

    do {
        op = menu();
        clrscr();
        switch (op) {
            case '1':
            	printf("  _______              _______      __      _______  \n");
				printf(" |   _   |   ______   |   _   |   _|  |_   |   _   \\  \n");
				printf(" |.  1   |  |______|  |.  1   |  |_    _|  |.  1   / \n");
				printf(" |.  _   |  |______|  |.  _   |    |__|    |.  _   \\ \n");
				printf(" |:  |   |            |:  |   |            |:  1    \\\n");
				printf(" |::.|:. |            |::.|:. |            |::.. .  /\n");
				printf(" `--- ---'            `--- ---'            `-------'");
				printf("\n");
            	leitura(&A, 'a');
            	leitura(&B, 'b');
				printf("\n");
                soma(&A, &B);
                break;
            case '2':
            	printf("  _______              _______      __      _______  \n");
				printf(" |   _   |   ______   |   _   |   _|  |_   |   _   \\  \n");
				printf(" |.  1   |  |______|  |.  1   |  |_    _|  |.  1   / \n");
				printf(" |.  _   |  |______|  |.  _   |    |__|    |.  _   \\ \n");
				printf(" |:  |   |            |:  |   |            |:  1    \\\n");
				printf(" |::.|:. |            |::.|:. |            |::.. .  /\n");
				printf(" `--- ---'            `--- ---'            `-------'");
				printf("\n");
				printf("Preservando B\n");
				printf("\n");
                C.num = 0;
            	leitura(&A, 'a');
            	leitura(&B, 'b');
				printf("\n");
                somaPreservandoB(&A, &B, &C);
                break;
            case '3':
            	printf("  _______              _______  \n");
				printf(" |   _   |   ______   |   _   \\ \n");
				printf(" |.  1   |  |______|  |.  1   / \n");
				printf(" |.  _   |  |______|  |.  _   \\ \n");
				printf(" |:  |   |            |:  1    \\\n");
				printf(" |::.|:. |            |::.. .  /\n");
				printf(" `--- ---'            `-------'\n");
            	printf("A := B\n");
                C.num = 0;
            	leitura(&A, 'a');
            	leitura(&B, 'b');
				printf("\n");
                atribuicao(&A, &B, &C);
                break;
            case '4':
            	printf("  _______              _______             _______  \n");
				printf(" |   _   |   ______   |   _   |  .--.--.  |   _   \\ \n");
				printf(" |.  1   |  |______|  |.  1   |  |_   _|  |.  1   / \n");
				printf(" |.  _   |  |______|  |.  _   |  |__.__|  |.  _   \\ \n");
				printf(" |:  |   |            |:  |   |           |:  1    \\\n");
				printf(" |::.|:. |            |::.|:. |           |::.. .  /\n");
				printf(" `--- ---'            `--- ---'           `-------'\n");
                C.num = 0;
                D.num = 0;
            	leitura(&A, 'a');
            	leitura(&B, 'b');
				printf("\n");
                multiplicacao(&A, &B, &C, &D);
        }
        if(op != 27){
        	printf("Pressione qualquer tecla para continuar");
        	getch();
        	clrscr();
		}
    } while (op != 27);
    return 0;
}
