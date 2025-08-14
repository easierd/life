screen.o: screen.c
	gcc -Wall -Wextra -fsanitize=address -c screen.c

board.o: board.c
	gcc -Wall -Wextra -fsanitize=address -c board.c

main: main.c board.o screen.o
	gcc -Wall -Wextra -fsanitize=address -o main main.c board.o screen.o

clean:
	rm main board.o screen.o
