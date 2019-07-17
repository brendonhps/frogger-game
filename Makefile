# DOUGLAS AFFONSO CLEMENTINO
# GRR20175877

CFLAGS = -Wall     # flags de compilacao
LDLIBS = -lncurses       # bibliotecas a ligar

EXECS  = jogo
 
# arquivos-objeto
objects = carro.o jogo.o jogador.o campo.o

all:  $(EXECS)

jogo: jogo.o carro.o campo.o jogador.o 
	gcc carro.o jogo.o jogador.o campo.o -o jogo $(LDLIBS) 


jogo.o : jogo.c carro.h campo.h
	gcc -c jogo.c $(CFLAGS) $(LDLIBS) 

carro.o : carro.c carro.h campo.h
	gcc -c carro.c $(CFLAGS) $(LDLIBS) 

campo.o : campo.c campo.h carro.h
	gcc -c campo.c $(CFLAGS) $(LDLIBS) 

jogador.o : jogador.c jogador.h
	gcc -c jogador.c $(CFLAGS) $(LDLIBS) 



clean:
	-rm $(objects)
	-rm *~

purge: clean
	-rm $(EXECS)