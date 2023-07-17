all: teste
	./teste 
	
teste: main.o lista.o
	gcc -o teste lista.o main.o 

debug: main.o lista.o
	gcc -g main.c lista.c -Wall -Werror -Wextra

lista.o: lista.c lista.h
	gcc -c lista.c -Wall -Werror -Wextra

main.o: main.c lista.h
	gcc -c main.c -Wall -Werror -Wextra

clean: 
	rm -r teste *.o