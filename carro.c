#include "carro.h"

void carregar_carro(Carro *carro, WINDOW *tela)
{      
        mvwaddch(tela,carro->yPosi, carro->xPosi, carro->frentecima); //carro frente cima
        mvwaddch(tela,carro->yPosi+1, carro->xPosi, carro->frentebaixo); // carro frente baixo
        mvwaddch(tela,carro->yPosi, carro->xPosi + 1, carro->trascima); //carro tras cima
        mvwaddch(tela,carro->yPosi+1, carro->xPosi + 1, carro->trasbaixo); //carro tras baixo
}

void move_carros(Carro *veiculo, WINDOW *tela, int larg)
{	
	// Trata veículo caso este esteja indo para esquerda.
	if(veiculo->sentido == ESQUERDA)
	{
		//Atualiza posicao do veiculo.
		veiculo->xPosi -= 1;

		// tenha chegado a borda.
		if(veiculo->xPosi < 1)
		{
			// Remove carro antigo.
			mvwaddch(tela,veiculo->yPosi, veiculo->xPosi + 1, ' '); //carro frente cima
			mvwaddch(tela,veiculo->yPosi+1, veiculo->xPosi + 1, ' '); // carro frente baixo
			mvwaddch(tela,veiculo->yPosi, veiculo->xPosi + 2, ' '); //carro tras cima
			mvwaddch(tela,veiculo->yPosi+1, veiculo->xPosi + 2, ' '); //carro tras baixo
			// Remove carro antigo.
			
			veiculo->xPosi = larg - 2;
			mvwaddch(tela,veiculo->yPosi, veiculo->xPosi, veiculo->frentecima); //carro frente cima
			mvwaddch(tela,veiculo->yPosi+1, veiculo->xPosi, veiculo->frentebaixo); // carro frente baixo
			mvwaddch(tela,veiculo->yPosi, 1, veiculo->trascima); //carro tras cima
			mvwaddch(tela,veiculo->yPosi+1, 1, veiculo->trasbaixo); //carro tras baixo
		}
		else
		{
			if(veiculo->xPosi >= larg - 3)
			{
				// Remove carro antigo.
				mvwaddch(tela,veiculo->yPosi, veiculo->xPosi + 1, ' '); //carro frente cima
				mvwaddch(tela,veiculo->yPosi+1, veiculo->xPosi + 1, ' '); // carro frente baixo
				mvwaddch(tela,veiculo->yPosi, 1, ' '); //carro tras cima
				mvwaddch(tela,veiculo->yPosi+1, 1, ' '); //carro tras baixo
				// Remove carro antigo.
			}
			else
			{
				// Remove carro antigo.
				mvwaddch(tela,veiculo->yPosi, veiculo->xPosi + 1, ' '); //carro frente cima
				mvwaddch(tela,veiculo->yPosi+1, veiculo->xPosi + 1, ' '); // carro frente baixo
				mvwaddch(tela,veiculo->yPosi, veiculo->xPosi + 2, ' '); //carro tras cima
				mvwaddch(tela,veiculo->yPosi+1, veiculo->xPosi + 2, ' '); //carro tras baixo
				// Remove carro antigo.
			}
	
	
			mvwaddch(tela,veiculo->yPosi, veiculo->xPosi, veiculo->frentecima); //carro frente cima
			mvwaddch(tela,veiculo->yPosi+1, veiculo->xPosi, veiculo->frentebaixo); // carro frente baixo
			mvwaddch(tela,veiculo->yPosi, veiculo->xPosi + 1, veiculo->trascima); //carro tras cima
			mvwaddch(tela,veiculo->yPosi+1, veiculo->xPosi + 1, veiculo->trasbaixo); //carro tras baixo
			
		}
	}
	else
	{

		//Atualiza posição do veículo.
		veiculo->xPosi += 1;

		//Detecta se veiculo passou da borda direita apos atualização.
		if(veiculo->xPosi == larg - 3)
		{
			// Remove carro antigo.
			mvwaddch(tela,veiculo->yPosi, veiculo->xPosi - 1, ' '); //carro frente cima
			mvwaddch(tela,veiculo->yPosi+1, veiculo->xPosi - 1, ' '); // carro frente baixo
			mvwaddch(tela,veiculo->yPosi, veiculo->xPosi, ' '); //carro tras cima
			mvwaddch(tela,veiculo->yPosi+1, veiculo->xPosi, ' '); //carro tras baixo
			// Remove carro antigo.
			
			mvwaddch(tela,veiculo->yPosi, veiculo->xPosi, veiculo->frentecima); //carro frente cima
			mvwaddch(tela,veiculo->yPosi+1, veiculo->xPosi, veiculo->frentebaixo); // carro frente baixo
			mvwaddch(tela,veiculo->yPosi, veiculo->xPosi + 1, veiculo->trascima); //carro tras cima
			mvwaddch(tela,veiculo->yPosi+1, veiculo->xPosi + 1, veiculo->trasbaixo); //carro tras baixo
		}
		else
		{
			if(veiculo->xPosi >= larg - 2)
			{				
				// Remove carro antigo.
				mvwaddch(tela,veiculo->yPosi, veiculo->xPosi, ' '); //carro frente cima
				mvwaddch(tela,veiculo->yPosi+1, veiculo->xPosi, ' '); // carro frente baixo
				mvwaddch(tela,veiculo->yPosi, veiculo->xPosi - 1, ' '); //carro tras cima
				mvwaddch(tela,veiculo->yPosi+1, veiculo->xPosi - 1, ' '); //carro tras baixo
				// Remove carro antigo.


				veiculo->xPosi = 1;
			}
			else
			{
				// Remove carro antigo.
				mvwaddch(tela,veiculo->yPosi, veiculo->xPosi , ' '); //carro frente cima
				mvwaddch(tela,veiculo->yPosi+1, veiculo->xPosi , ' '); // carro frente baixo
				mvwaddch(tela,veiculo->yPosi, veiculo->xPosi - 1, ' '); //carro tras cima
				mvwaddch(tela,veiculo->yPosi+1, veiculo->xPosi - 1, ' '); //carro tras baixo
				// Remove carro antigo.
			}
	
	
			mvwaddch(tela,veiculo->yPosi, veiculo->xPosi, veiculo->frentecima); //carro frente cima
			mvwaddch(tela,veiculo->yPosi+1, veiculo->xPosi, veiculo->frentebaixo); // carro frente baixo
			mvwaddch(tela,veiculo->yPosi, veiculo->xPosi + 1, veiculo->trascima); //carro tras cima
			mvwaddch(tela,veiculo->yPosi+1, veiculo->xPosi + 1, veiculo->trasbaixo); //carro tras baixo
			
		}
	}
	wrefresh(tela);
}

void inicia_carro(Carro *carro,int posicaox, int posicaoy, Sentido sent)
{

	carro->sentido = sent;
	
	if(carro->sentido == DIREITA)
	{
		carro->frentecima = '-';
		carro->frentebaixo = '-';
		carro->trascima = '\\';
		carro->trasbaixo = '/';
	}
	
	if(carro->sentido == ESQUERDA)
	{
		carro->frentecima = '/';
		carro->frentebaixo = '\\';
		carro->trascima = '-';
		carro->trasbaixo = '-';
	}

	carro->xPosi = posicaox;
	carro->yPosi = posicaoy;
}