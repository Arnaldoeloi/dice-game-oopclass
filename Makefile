OBJS	= main.o classes/Game.o classes/Die.o classes/Player.o  
SOURCE	= main.cpp classes/Game.cpp classes/Die.cpp classes/Player.cpp
HEADER	= classes/Game.h classes/Die.h classes/Player.h
OUT	= dice-rolling
CC	 = g++
FLAGS	 = -std=c++11 -g -Wall -O0 -l ./classes/
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
	make run
main.o: main.cpp classes/Game.h     
	$(CC) $(FLAGS) -c main.cpp

Game.o: classes/Game.h classes/Game.cpp
	$(CC) $(FLAGS) -c classes/Game.cpp

Player.o: classes/Player.cpp classes/Player.h
	$(CC) $(FLAGS) -c classes/Player.h

Die.o: classes/Die.cpp classes/Die.h
	$(CC) $(FLAGS) -c classes/Die.h

clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)