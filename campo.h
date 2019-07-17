#ifndef _CAMPO_
#define _CAMPO_

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "carro.h"


#define MAX_LINHAS 10

// Previne que Sentido seja declarado mais de uma vez ( em "carros.h" e em "campo.h").
#ifndef _SENTIDO_
#define _SENTIDO_
typedef enum
{
	DIREITA,
	ESQUERDA
} Sentido;
#endif

typedef struct Linha
{   
    int             pontos,
                    objetos,
                    intervalo_tempo,
                    yPosi;
    
    Carro           *carros;
    
    Sentido         sentido;
} Linha;

typedef struct Campo
{
    Linha       linhas[MAX_LINHAS];				
} Campo;

void carrega_campo(Campo *campo, WINDOW *tela);

#endif