all: teste
	./teste

debug: main.c arvore.h
	gcc -g main.c arvore.c -Wall -Werror -Wextra

teste: main.o arvore.o
	gcc -o teste main.o arvore.o -Wall -Wextra -Werror

main.o: main.c arvore.h
	gcc -c main.c -Wall -Wextra -Werror

arvore.o: arvore.c arvore.h
	gcc -c arvore.c -Wall -Wextra -Werror

clean:
	rm -r teste *.o *.out
