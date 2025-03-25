struct reg {
    int s, num;
};
typedef struct reg Reg;

void leituraN(Reg *reg, char nomeReg) {
	char sm;
	
	gotoxy(13, 41);
    printf("Informe o valor de %c:", toupper(nomeReg));
    gotoxy(35,41);
    scanf("%d", &(*reg).num);
    Entrada("Informe o Sinal de Magnitude: [0] para Positivo ou [1] para Negativo");
    gotoxy(41,41);
    printf("");
    sm = getch();
    (*reg).s = sm - '0';
    LimpaEntrada();
}

void leitura(int *reg, char nomeReg) {
	gotoxy(13, 41);
    printf("Informe o valor de %c:", toupper(nomeReg));
    gotoxy(35,41);
    scanf("%d", &*reg);
    gotoxy(41,41);
    printf("");
    LimpaEntrada();
}

void execSoma(Reg A, Reg B) {
	char linha[50][100];
	int i = 0, j, pos = 15;
	
	sprintf(linha[i++],"| A1: %d | A2: %d | B1: %d | B2: %d |", A.s, A.num, B.s, B.num);
    if (B.s == 0) {
        if(A.s == 0) {
	        while (B.num != 0) {
	            A.num++;
	            B.num--;
				sprintf(linha[i++],"| A1: %d | A2: %d | B1: %d | B2: %d |", A.s, A.num, B.s, B.num);
	        }
        } else {
	        while (B.num != 0 && A.num != 0) {
	            A.num--;
	            B.num--;
	            if(A.num == 0)
            		A.s --;
				sprintf(linha[i++],"| A1: %d | A2: %d | B1: %d | B2: %d |", A.s, A.num, B.s, B.num);
	        }
	        while (B.num != 0) {
	            A.num++;
	            B.num--;
				sprintf(linha[i++],"| A1: %d | A2: %d | B1: %d | B2: %d |", A.s, A.num, B.s, B.num);
	        }
        }
    } else {
        if(A.s == 0){
	        while (B.num != 0 && A.num != 0) {
	            A.num--;
	            B.num--;
				sprintf(linha[i++],"| A1: %d | A2: %d | B1: %d | B2: %d |", A.s, A.num, B.s, B.num);
	        }
	        while(B.num != 0) {	        	
	          	if(A.num == 0)
	            	A.s++;
	        	A.num++;
	        	B.num--;
				sprintf(linha[i++],"| A1: %d | A2: %d | B1: %d | B2: %d |", A.s, A.num, B.s, B.num);
	        }
        } else {
	        while (B.num != 0) {
	            A.num++;
	            B.num--;
				sprintf(linha[i++],"| A1: %d | A2: %d | B1: %d | B2: %d |", A.s, A.num, B.s, B.num);
	        }
        }
    }
    for(j=0; j<i; j ++) {
		ExibirLinha(pos++,linha[j]);
		if(pos == 32) {
			pos = 15;
        	Entrada("Pressione para continuar a Simulacao");
			getch();
			LimparMoldura();
		}
    }
}

void execSomaPB(int A, int B) {
	char linha[50][100];
	int i = 0, j, pos = 15, C=0;
	
    sprintf(linha[i++],"| A: %d | B: %d | C: %d |\n", A, B, C);
    while (B != 0) {
        B--;
        C++;
		sprintf(linha[i++],"| A: %d | B: %d | C: %d |\n", A, B, C);
    }
	sprintf(linha[i++],"| A: %d | B: %d | C: %d |\n", A, B, C);
    while (C != 0) {
        A++;
        B++;
        C--;
		sprintf(linha[i++],"| A: %d | B: %d | C: %d |\n", A, B, C);
    }
    for(j=0; j<i; j ++) {
		ExibirLinha(pos++,linha[j]);
		if(pos == 32) {
			pos = 15;
        	Entrada("Pressione para continuar a Simulacao");
			getch();
			LimparMoldura();
		}
    }
}

void execAtribuicao(int A, int B) {
	int C = 0;
	char linha[50][100];
	int i = 0, j, pos = 15;
	
    sprintf(linha[i++],"| A: %d | B: %d | C: %d |\n", A, B, C);
        while (A != 0) {
            A--;
    		sprintf(linha[i++],"| A: %d | B: %d | C: %d |\n", A, B, C);
        }
    	sprintf(linha[i++],"| A: %d | B: %d | C: %d |\n", A, B, C);
            // A e B positivos
            while (B != 0) {
                B--;
                C++;
    			sprintf(linha[i++],"| A: %d | B: %d | C: %d |\n", A, B, C);
            }
    		sprintf(linha[i++],"| A: %d | B: %d | C: %d |\n", A, B, C);
            while (C != 0) {
                A++;
                B++;
                C--;
    			sprintf(linha[i++],"| A: %d | B: %d | C: %d |\n", A, B, C);
            }
    for(j=0; j<i; j ++) {
		ExibirLinha(pos++,linha[j]);
		if(pos == 32) {
			pos = 15;
        	Entrada("Pressione para continuar a Simulacao");
			getch();
			LimparMoldura();
		}
    }
}

void execMultiplicacao(int A, int B) {
	int C = 0, D = 0;
	char linha[1000][100];
	int i = 0, j, pos = 15;
    
	while (A != 0) {
    	sprintf(linha[i++],"| A: %d | B: %d | C: %d | D: %d |\n", A, B, C, D);
	    while (B != 0) {
	        B--;
	        C++;
	        D++;
    		sprintf(linha[i++],"| A: %d | B: %d | C: %d | D: %d |\n", A, B, C, D);
	    }
    	sprintf(linha[i++],"| A: %d | B: %d | C: %d | D: %d |\n", A, B, C, D);
	    while (C != 0) {
	        B++;
	        C--;
    		sprintf(linha[i++],"| A: %d | B: %d | C: %d | D: %d |\n", A, B, C, D);
	    }
	    A--;
	}
    sprintf(linha[i++],"| A: %d | B: %d | C: %d | D: %d |\n", A, B, C, D);
	while (D != 0) {
	    A++;
	    D--;
    	sprintf(linha[i++],"| A: %d | B: %d | C: %d | D: %d |\n", A, B, C, D);
	}
    for(j=0; j<i; j ++) {
		ExibirLinha(pos++,linha[j]);
		if(pos == 32) {
			pos = 15;
        	Entrada("Pressione para continuar a Simulacao");
			getch();
			LimparMoldura();
		}
    }
}


void multiplicacao() {
	int A, B;
	char elem[50];
	
	LimpaOperacao();
	Operacao("A := A x B (Utilizando C e D e Preservando o valor de B)");
	Moldura(20, 13, 100, 34, 0, 7);
	leitura(&A, 'a');
	sprintf(elem, "A: %d", A);
	ExibeTexto(60,10,0,7,elem,"A");
	leitura(&B, 'b');
	sprintf(elem, "B: %d", B);
	ExibeTexto(180,10,0,7,elem,"B");
    execMultiplicacao(A, B);
}

void atribuicao() {
	int A, B;
	char elem[50];
	
	LimpaOperacao();
	Operacao("A := B (Utilizando C e Preservando o valor de B)");
	Moldura(20, 13, 100, 34, 0, 7);
	leitura(&A, 'a');
	sprintf(elem, "A: %d", A);
	ExibeTexto(60,10,0,7,elem,"A");
	leitura(&B, 'b');
	sprintf(elem, "B: %d", B);
	ExibeTexto(180,10,0,7,elem,"B");
    execAtribuicao(A, B);
}

void somaPreservandoB() {	
	int A, B;
	char elem[50];
		
	LimpaOperacao();
	Operacao("A := A + B (Utilizando C e Preservando o valor de B)");
	Moldura(20, 13, 100, 34, 0, 7);
	leitura(&A, 'a');
	sprintf(elem, "A: %d", A);
	ExibeTexto(60,10,0,7,elem,"A");
	leitura(&B, 'b');
	sprintf(elem, "B: %d", B);
	ExibeTexto(180,10,0,7,elem,"B");
	execSomaPB(A, B);
}

void soma(void) {
	Reg A, B;
	char elem[50];
	
	LimpaOperacao();
	Operacao("A := A + B");
	Moldura(20, 13, 100, 34, 0, 7);
	leituraN(&A, 'a');
	sprintf(elem, "A1: %d | A2: %d", A.s, A.num);
	ExibeTexto(60,10,0,7,elem,"A");
	leituraN(&B, 'b');
	sprintf(elem, "B1: %d | B2: %d",B.s, B.num);
	ExibeTexto(180,10,0,7,elem,"B");
	execSoma(A, B);
}
