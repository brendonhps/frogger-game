#ifndef _CARROS_
#define _CARROS_

#include <ncurses.h>
#include <stdlib.h> 	/*remover*/
#include <time.h>   	/*remover*/

// Previne que Sentido seja declarado mais de uma vez ( em "carros.h" e em "campo.h").
#ifndef _SENTIDO_
#define _SENTIDO_
typedef enum
{
	DIREITA,
	ESQUERDA
} Sentido;
#endif

typedef struct Carro{
	int 		xPosi, 
				yPosi;

	Sentido 	sentido;
	
	char		frentecima,
				frentebaixo,
				trascima ,
				trasbaixo ;
				
} Carro;

typedef struct Caminhao{
	int 		xPosi, 
				yPosi;
	
	Sentido 	sentido;

	char		frentecima,
				frentebaixo,
				meiofrentecima,
				meiofrentebaixo,
				meiotrascima,
				meiotrasbaixo,
				trascima ,
				trasbaixo ;
				
} Caminhao;

void move_carros(Carro *veiculo, WINDOW *tela, int larg);

void carregar_carro(Carro *carro, WINDOW *tela);

void inicia_carro(Carro *carro,int posicaox, int posicaoy, Sentido sent);

#endif