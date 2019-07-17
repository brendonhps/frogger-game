#include <ncurses.h>
#include <unistd.h>
#include "carro.h"
#include "jogador.h"
#include "campo.h"

int main(int argc, char *argv[])
{
	Campo			campo;

	Jogador			jogador;

	WINDOW 			*janela;  //Janela principal do jogo;
	
	int 			startx, 
					starty, 
					largura, 
					comprimento,
					cont,
					j,
					k;

	unsigned long i = 0;
	
	
	initscr();                      //Iniciar modo Curses.
	cbreak();                       // Programa receberá e tratra toda e qualquer entrada de usuário.
	keypad(stdscr, TRUE);           // Mapear teclas omo F's, setas, etc...	
	nodelay(stdscr, TRUE);			// Evitar bloqueios quando requisitada entrada de usuário.
	curs_set(0);					// Esconder cursor do terminal.

	comprimento = 28;
	largura = 30;
	starty = (LINES - comprimento) / 2;  	// Calcula-se a posição de centro do terminal em relação a altura.
	startx = (COLS - largura) / 2;    		// Calcula-se a posição de centro do terminal em relação a largura.	
	
	
	printw("Press \'x\' to exit");			//Indicar tecla para finalizar programa.
	refresh();
	
	janela = newwin(comprimento, largura, starty, startx);
	box(janela, 0 , 0);

	carrega_campo(&campo, janela);

	iniciar_jogador(&jogador, janela);

	for(j = 0; j < MAX_LINHAS; j++)
	{
		for(k = 0; k < campo.linhas[j].objetos; k++)
		{
			carregar_carro(campo.linhas[j].carros + k, janela);
		}
	}

	wrefresh(janela);
	while(capi_movimento(&jogador, janela, largura - 3, comprimento - 3) != 'x')
	{  			
		// Velocidade 1
		if((i % 500000) == 0)
		{	
			for(j = 0; j < campo.linhas[0].objetos; j++)
			{
				move_carros(campo.linhas[0].carros + j, janela, largura);
			}
			for(j = 0; j < campo.linhas[3].objetos; j++)
			{
				move_carros(campo.linhas[3].carros + j, janela, largura);
			}
			for(j = 0; j < campo.linhas[6].objetos; j++)
			{
				move_carros(campo.linhas[6].carros + j, janela, largura);
			}
			for(j = 0; j < campo.linhas[9].objetos; j++)
			{
				move_carros(campo.linhas[9].carros + j, janela, largura);
			}
		}	
		// Velocidade 2
		if((i % 200000) == 0)
		{	
			for(j = 0; j < campo.linhas[1].objetos; j++)
			{
				move_carros(campo.linhas[1].carros + j, janela, largura);
			}
			for(j = 0; j < campo.linhas[4].objetos; j++)
			{
				move_carros(campo.linhas[4].carros + j, janela, largura);
			}
			for(j = 0; j < campo.linhas[7].objetos; j++)
			{
				move_carros(campo.linhas[7].carros + j, janela, largura);
			}			
		}	

		// Velocidade 3
		if((i % 300000) == 0)
		{	
			for(j = 0; j < campo.linhas[2].objetos; j++)
			{
				move_carros(campo.linhas[2].carros + j, janela, largura);
			}
			for(j = 0; j < campo.linhas[5].objetos; j++)
			{
				move_carros(campo.linhas[5].carros + j, janela, largura);
			}
			for(j = 0; j < campo.linhas[8].objetos; j++)
			{
				move_carros(campo.linhas[8].carros + j, janela, largura);
			}			
		}	


		i++;
		if(i > 1000000000)
		{
			i = 1;
		}
		
		for(cont = 0; cont < MAX_LINHAS; cont ++)
		{	
			for(j = 0; j < campo.linhas[cont].objetos; j++)
			{
				/*	---------- APRIMORAR VERIFICAÇÃO COM MATRIZ POSTERIORMENTE !!!! ----------- */
				/**/if((jogador.xPosi == (campo.linhas[cont].carros + j)->xPosi) && (jogador.yPosi == (campo.linhas[cont].carros + j)->yPosi))
				/**/{
				/**/	morte_jogador(&jogador, janela);
				/**/	if(jogador.vidas == 0)
				/**/	{
				/**/		printw("MORREU-SE");
				/**/		goto FIM;
				/**/	}
				/**/};
				/**/if((jogador.xPosi == (campo.linhas[cont].carros + j)->xPosi + 1) && (jogador.yPosi == (campo.linhas[cont].carros + j)->yPosi))
				/**/{
				/**/	morte_jogador(&jogador, janela);
				/**/	if(jogador.vidas == 0)
				/**/	{
				/**/		printw("MORREU-SE");
				/**/		goto FIM;
				/**/	}
				/**/}
				/**/if((jogador.xPosi + 1 == (campo.linhas[cont].carros + j)->xPosi) && (jogador.yPosi == (campo.linhas[cont].carros + j)->yPosi))
				/**/{
				/**/	morte_jogador(&jogador, janela);
				/**/	if(jogador.vidas == 0)
				/**/	{
				/**/		printw("MORREU-SE");
				/**/		goto FIM;
				/**/	}
				/**/}
			}
		}
	}
	FIM:
	endwin();
	return 0;
}