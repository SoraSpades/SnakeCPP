OBJS	= ./out/main.o ./out/board.o ./out/pos.o
SOURCE	= _main.cpp struct/board.cpp struct/pos.cpp
HEADER	= struct/board.h struct/pos.h
OUT	= ./snake.exe
CC	 = g++
FLAGS	 = -g -c -Wall -I ./structs
LFLAGS	 = -g -Wall -I ./structs 

snake.exe: ./out/board.o ./out/pos.o ./out/main.o
	$(CC) $(LFLAGS) $(OBJS) -o ./snake.exe

./out/pos.o: ./structs/pos.cpp
	$(CC) $(FLAGS) ./structs/pos.cpp -o ./out/pos.o

./out/board.o: ./structs/board.cpp
	$(CC) $(FLAGS) ./structs/board.cpp -o ./out/board.o

./out/main.o: _main.cpp
	$(CC) $(FLAGS) ./_main.cpp -o ./out/main.o

clean:
	rm ./out/*.o
	rm ./snake.exe