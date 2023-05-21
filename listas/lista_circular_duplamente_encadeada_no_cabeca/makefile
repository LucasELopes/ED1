all: teste 
	
teste: main.o lista.o
	gcc main.o lista.o -o teste
	./teste 

main.o: main.c lista.h
	gcc -c main.c -Wall

lista.o: lista.c lista.h
	gcc -c lista.c -Wall

clean: 
	rm main.o lista.o teste