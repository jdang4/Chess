CFLAGS = -g -Wall

all: main

main: main.o ChessPiece.o ChessPieceFactory.o ChessPieceDescriptor.o Coordinate.o
	g++ $(CFLAGS) main.o ChessPiece.o ChessPieceFactory.o ChessPieceDescriptor.o Coordinate.o -o main 

main.o: main.cpp 
	g++ $(CFLAGS) -c main.cpp 

ChessPiece.o: chess/ChessPiece.cpp chess/headers/ChessPiece.h chess/headers/ChessPieceFactory.h 
	g++ $(CFLAGS) -c chess/ChessPiece.cpp

ChessPieceFactory.o: chess/ChessPieceFactory.cpp chess/headers/ChessPieceFactory.h 
	g++ $(CFLAGS) -c chess/ChessPieceFactory.cpp

ChessPieceDescriptor.o: chess/ChessPieceDescriptor.cpp chess/headers/ChessPieceDescriptor.h 
	g++ $(CFLAGS) -c chess/ChessPieceDescriptor.cpp

Square.o: Field/Square.cpp Field/Headers/Square.h
	g++ $(CFLAGS) -c Field/Square.cpp

Board.o: Field/Board.cpp Field/Headers/Board.h Field/Headers/Square.h
	g++ $(CFLAGS) -c Field/Board.cpp	

Coordinate.o: util/Coordinate.cpp util/headers/Coordinate.h 
	g++ $(CFLAGS) -c util/Coordinate.cpp

clean:
<<<<<<< HEAD
	rm -f main.o ChessPiece.o ChessPieceFactory.o ChessPieceDescriptor.o Coordinate.o main
=======
	rm -f main.o Square.o Board.o ChessPiece.o ChessPieceFactory.o ChessPieceDescriptor.o main
>>>>>>> f16bc9d96ad8ec6889db95a2a0d8f48d96f514b4
