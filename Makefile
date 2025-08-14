screen.o: screen.c
	gcc -Wall -Wextra -fsanitize=address -c screen.c

board.o: board.c
	gcc -Wall -Wextra -fsanitize=address -c board.c

board_state.o: board_state.c
	gcc -Wall -Wextra -fsanitize=address -c board_state.c

main: main.c board.o screen.o board_state.o
	gcc -Wall -Wextra -fsanitize=address -o main main.c board.o screen.o board_state.o

clean:
	rm main *.o
