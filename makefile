CC=g++

CFLAGS=-c
graphflags= -lsfml-graphics -lsfml-window -lsfml-system

all:
	$(CC) $(CFLAGS) ArturTestSFML.cpp
	$(CC) ArturTestSFML.cpp -o sfml-app $(graphflags)
	rm -rf ArturTestSFML.o
	./sfml-app
	
