all: teste clean

teste: main.o fila.o
	gcc -o teste main.o fila.o
	./teste 
	

main.o: main.c fila.h
	gcc -c main.c -Wall -Wextra -Werror 

fila.o: 
	gcc -c fila.c -Wall -Wextra -Werror 

clean:
	rm -r teste *.o