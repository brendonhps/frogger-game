#include "campo.h"
#include "carro.h"

void carrega_campo(Campo *campo, WINDOW *tela)
{
    int             i,
                    j,
                    largura,
                    altura,
                    Posicaox;

    // Transfere dimenções da WINDOW para as variáveis altura e largura.
    getmaxyx(tela, altura, largura);
	
	srand (time(NULL));

    // Definindo caracteres de definição do carro e a posição de cada carro.
    for(i = 0; i < MAX_LINHAS; i++)
    {
		// Sorteia em qual dos sentidos os objetos irão de mover.
        campo->linhas[i].sentido = rand() % 2;
        campo->linhas[i].pontos = 10;
       
        //---- Usando dimenção de carro, trocar para quando acrescentar mais objetos.-----
        campo->linhas[i].objetos = (rand() % 2) + 1; // de 1 a 2 carros por linha.
        
        campo->linhas[i].carros = malloc(campo->linhas[i].objetos * sizeof(Carro));

        // Define carros acima da zona intermediária.
        if(i < MAX_LINHAS /2)
        {
            campo->linhas[i].yPosi = (i * 2) + 3;
        }

        // Define carros abiaxo da zoana intermediária.
        else
        {
            campo->linhas[i].yPosi = (i * 2) + 5;
        }

        for (j = 0; j < campo->linhas[i].objetos; j++)
        {
            // Calcula a melhor distribuição do carro em relação a quantidade de carros nesta linha.
            Posicaox = ((largura - 2) / campo->linhas[i].objetos) * (j+1) - 1;

            // Envia informações para setar carro nesta linha.
            inicia_carro(campo->linhas[i].carros + j, Posicaox, campo->linhas[i].yPosi, campo->linhas[i].sentido);
        }      
    }
}