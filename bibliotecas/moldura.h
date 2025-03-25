void Moldura(int CI, int LI, int CF, int LF, int CorT, int CorF)
{
	int i;

	textcolor(CorT);
	textbackground(CorF);
	gotoxy(CI, LI);
	printf("%c", 201);
	gotoxy(CF, LI);
	printf("%c", 187);
	gotoxy(CI, LF);
	printf("%c", 200);
	gotoxy(CF, LF);
	printf("%c", 188);
	for (i = CI + 1; i < CF; i++)
	{
		gotoxy(i, LI);
		printf("%c", 205);
		gotoxy(i, LF);
		printf("%c", 205);
	}
	for (i = LI + 1; i < LF; i++)
	{
		gotoxy(CI, i);
		printf("%c", 186);
		gotoxy(CF, i);
		printf("%c", 186);
	}
	textbackground(7);
	textcolor(0);
}

void FundoQuadro(int CI, int LI, int CF, int LF, int Cor)
{
	int L = LI + 1, C = CI + 1;
	char linha[150] = "";

	while (CI < CF - 1)
	{
		strcat(linha, " ");
		CI++;
	}
	textbackground(Cor);
	while (L < LF)
	{
		gotoxy(C, L);
		printf("%s", linha);
		L++;
	}
}

void Sombra(int CI, int LI, int CF, int LF, int CorF)
{
	int i;
	textbackground(CorF);
	for (i = LI; i < LF; i++)
	{
		gotoxy(CF + 1, i + 1);
		printf("  ");
	}
	for (i = CI; i < CF + 2; i++)
	{
		gotoxy(i + 1, LF + 1);
		printf(" ");
	}
	textbackground(7);
}

void Titulo(int CI, int CF, char *Titulo, int Linha)
{
	int pos = (CF + CI) / 2 - (strlen(Titulo) + 2) / 2;

	if (strlen(Titulo))
	{
		textbackground(0);
		textcolor(14);
		gotoxy(pos, Linha);
		printf(" %s ", Titulo);
		textcolor(0);
		textbackground(7);
	}
}

void RetiraCursor(void){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void LigaCursor(void){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void Dimensao(char *C, char *L){
	char linha[30];
	strcpy(linha, "mode con cols=");
	strcat(linha, C);
	strcat(linha, " lines=");
	strcat(linha, L);
	system(linha);
}

void Container(int CI, int LI, int CF, int LF, int corT, int corF) {
	FundoQuadro(CI, LI, CF, LF, corF);
	Moldura(CI, LI, CF, LF, corT, corF);
	Sombra(CI,LI,CF,LF,0);
}

void MolduraCompleta(void)
{
	FundoQuadro(1, 1, 120, 45, 3);
	Moldura(1, 1, 120, 45, 0, 3);
}

void LimpaLinha(int Num)
{
	gotoxy(2, Num);
	printf("                                                                                                  ");
}

void LimpaTela(void)
{
	int i;

	for (i = 2; i < 48; i++)
		LimpaLinha(i);
}

void LinhaMoldura(int Linha, int CorF, int CorT)
{
	int i;
	textbackground(CorF);
	textbackground(CorT);
	gotoxy(1, Linha);
	printf("%c", 204);
	gotoxy(100, Linha);
	printf("%c", 185);
	for (i = 2; i < 100; i++) {
		gotoxy(i, Linha);
		printf("%c", 205);
	}
}

void ColunaMoldura(int LI, int LF, int Coluna, int CorF, int CorT)
{
	int i;

	textbackground(CorF);
	textbackground(CorT);
	gotoxy(Coluna, LI);
	printf("%c", 203);
	gotoxy(Coluna, LF);
	printf("%c", 202);
	for (i = LI + 1; i < LF; i++)
	{
		gotoxy(Coluna, i);
		printf("%c", 186);
	}
}

void ExibeTexto(int TamC, int Linha, int CorT, int CorF, char *texto, char *titulo)
{
	int CI = TamC / 2 - (strlen(texto) / 2 + 2), CF = TamC / 2 + (strlen(texto) / 2 + 2), LI = Linha - 1, LF = Linha + 1;

	Moldura(CI, LI, CF, LF, CorT, CorF);
	FundoQuadro(CI, LI, CF, LF, CorF);
	Sombra(CI, LI, CF, LF, 0);
	Titulo(CI, CF, titulo, LI);
	textcolor(CorT);
	textbackground(CorF);
	gotoxy(TamC / 2 - strlen(texto) / 2, LI + 1);
	printf("%s", texto);
}

void ExibirLinha(int Linha, char *linha) {
	gotoxy(60 - strlen(linha)/2, Linha);
	printf("%s",linha);
}

void Operacao(char *operacao) {
	int len = strlen("                                                                                                ");
	gotoxy(60 - strlen(operacao)/2, 4);
	printf("%s",operacao);
}

void LimpaOperacao(void) {
	gotoxy(13, 4);
	printf("                                                                                                ");
}

void Entrada(char *entrada) {	
	gotoxy(13, 41);
	printf("%s",entrada);
}

void LimpaEntrada(void) {
	gotoxy(13, 41);
	printf("                                                                                                ");
}

void LimparCaixa(void) {
	int i;
	for(i = 9; i < 36; i ++){
		gotoxy(13,i);
		printf("                                                                                                ");
	}
}

void LimparMoldura(void) {
	int i;
	for(i = 15; i < 33; i ++) {
		gotoxy(21,i);
		printf("                                                                               ");
	}
}

void iniciarTela(void) {
	RetiraCursor();
	Dimensao("120","45");
	MolduraCompleta();
	ExibeTexto(120,41,0,7,"                                                                                               ","Entrada:");
	ExibeTexto(120, 4, 0, 7, "                                                                                                 ","Operacao");
	Container(10,8,110,36,0,7);
}

void MsgFim(void)
{
	Dimensao("80", "30");
	Moldura(1, 1, 80, 30, 0, 3);
	FundoQuadro(1, 1, 80, 30, 3);

	ExibeTexto(80, 4, 0, 7, "TEORIA DA COMPUTACAO", "");
	ExibeTexto(80, 9, 0, 14, "SIMULACAO DE UMA MAQUINA NORMA", "");
	ExibeTexto(80, 14, 0, 7, "102011907 - JOHN HERIC RODRIGUES PINTO", "");
	ExibeTexto(80, 18, 0, 7, "102421080 - MATHEUS OLIVEIRA DA SILVA", "");
	ExibeTexto(80, 26, 0, 7, "PROF. ME. DANIELA TEREZA ASCENCIO RUSSI", "");
}
