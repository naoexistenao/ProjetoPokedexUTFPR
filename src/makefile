main: main.o pokedex/pokedex.o mochila/mochila.o colecao/colecao.o batalha/batalha.o captura/captura.o
	@echo "Gerando arquivo executável"
	gcc -g main.o pokedex/pokedex.o  mochila/mochila.o colecao/colecao.o batalha/batalha.o captura/captura.o -o main

main.o: main.c
	@echo "Compilando e gerando os objetos"
	gcc -g -c main.c

pokedex/pokedex.o: ./pokedex/pokedex.c
	@echo "Compilando e gerando os objetos para a pasta pokedex"
	gcc -g -c ./pokedex/pokedex.c -o pokedex/pokedex.o

mochila/mochila.o: ./mochila/mochila.c
	@echo "Compilando e gerando os objetos para a pasta mochila"
	gcc -g -c ./mochila/mochila.c -o mochila/mochila.o

colecao/colecao.o: ./colecao/colecao.c
	@echo "Compilando e gerando os objetos para a pasta colecao"
	gcc -g -c ./colecao/colecao.c -o colecao/colecao.o

batalha/batalha.o: ./batalha/batalha.c
	@echo "Compilando e gerando os objetos para a pasta batalha"
	gcc -g -c ./batalha/batalha.c -o batalha/batalha.o

captura/captura.o: ./captura/captura.c
	@echo "Compilando e gerando os objetos para a pasta captuta"
	gcc -g -c ./captura/captura.c -o captura/captura.o

clean:
	@echo "Apagando objetos e executáveis antigos..."
	rm -f *.o main
	
run:
	gdb ./main
