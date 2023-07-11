all: teste
	./teste

teste: main.o lista.o
	gcc -o teste main.o lista.o -Wall -Wextra -Werror

main.o: main.c arvore.h
	gcc -c main.c -Wall -Wextra -Werror

lista.o: lista.c lista.h
	gcc -c lista.c -Wall -Wextra -Werror

clean:
	rm -r teste *.o
