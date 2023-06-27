all: teste clean

teste: main.o arvore.o
	gcc -o teste main.o arvore.o
	./teste

main.o: main.c arvore.h
	gcc -c main.c # -Werror -Wextra -Wall

arvore.o: main.c arvore.h
	gcc -c arvore.c # -Werror -Wextra -Wall

clean:
	rm -r teste *.o