#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

struct reg {
    char s;
    int num;
};

typedef struct reg Reg;

void limparTela() {
#ifdef __linux__
    system("clear");
#else
    system("cls");
#endif
}

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
}

void atribuicao(Reg *A, Reg *B, Reg *C) {
    printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
    if ((*A).s == 0) {
        while ((*A).num != 0) {
            (*A).num--;
            printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
        }
        printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
        if ((*B).s == 0) {
            // A e B positivos
            while ((*B).num != 0) {
                (*B).num--;
                (*C).num++;
                printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
            }
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
        printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
        if ((*B).s == 0) {
            // A negativo e B positivo
            while ((*B).num != 0) {
                (*B).num--;
                (*C).num++;
                printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
            }
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
            printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
            while ((*C).num != 0) {
                (*A).num--;
                (*B).num--;
                (*C).num--;
                printf("| A: %d | B: %d | C: %d |\n", (*A).num, (*B).num, (*C).num);
            }
        }
    }
}

void multiplicacao(Reg *A, Reg *B, Reg *C, Reg *D) {
    printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
    if ((*A).s == 0) {
        if ((*B).s == 0) {
            // A e B positivos
            while ((*A).num != 0) {
                while ((*B).num != 0) {
                    (*B).num--;
                    (*C).num++;
                    (*D).num++;
                }
                while ((*C).num != 0) {
                    (*B).num++;
                    (*C).num--;
                }
                (*A).num--;
            }
            while ((*D).num != 0) {
                (*A).num++;
                (*D).num--;
            }
        } else {
            // A positivo e B negativo
            while ((*A).num != 0) {
                while ((*B).num != 0) {
                    (*B).num++;
                    (*C).num++;
                    (*D).num++;
                }
                while ((*C).num != 0) {
                    (*B).num--;
                    (*C).num--;
                }
                (*A).num--;
            }
            while ((*D).num != 0) {
                (*A).num--;
                (*D).num--;
            }
        }
    } else {
        if ((*B).s == 0) {
            // A negativo e B positivo
            while ((*A).num != 0) {
                while ((*B).num != 0) {
                    (*B).num--;
                    (*C).num++;
                    (*D).num++;
                }
                while ((*C).num != 0) {
                    (*B).num++;
                    (*C).num--;
                }
                (*A).num++;
            }
            while ((*D).num != 0) {
                (*A).num--;
                (*D).num--;
            }
        } else {
            // A e B negativos
            while ((*A).num != 0) {
                while ((*B).num != 0) {
                    (*B).num++;
                    (*C).num++;
                    (*D).num++;
                }
                while ((*C).num != 0) {
                    (*B).num--;
                    (*C).num--;
                }
                (*A).num++;
            }
            while ((*D).num != 0) {
                (*A).num++;
                (*D).num--;
            }
        }
    }
    printf("| A: %d | B: %d | C: %d | D: %d |\n", (*A).num, (*B).num, (*C).num, (*D).num);
}

char menu(void) {
    char op;
    printf("Selecione uma opcao:\n");
    printf("[1] - A := A + B\n");
    printf("[2] - A := A + B usando C (O conteudo de B sera mantido)\n");
    printf("[3] - A := B usando C (O conteudo de B sera mantido)\n");
    printf("[4] - A := A x B usando C, D (O conteudo de B sera mantido)\n");
    printf("[Sair]\n");
    scanf(" %c", &op);
    return op;
}

int main(void) {
    Reg A, B, C, D;
    char op;

    do {
        op = menu();
        if (op >= '1' && op <= '4') {
            leitura(&A, 'a');
            leitura(&B, 'b');
        }
        switch (op) {
            case '1':
                soma(&A, &B);
                break;
            case '2':
                C.num = 0;
                somaPreservandoB(&A, &B, &C);
                break;
            case '3':
                C.num = 0;
                atribuicao(&A, &B, &C);
                break;
            case '4':
                C.num = 0;
                D.num = 0;
                multiplicacao(&A, &B, &C, &D);
                break;
            default:
                printf("Opcao Invalida!\n");
        }
        limparTela();
        printf("teste");
    } while (op != 27);
    return 0;
}
