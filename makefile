CFLAGS = -g -Wall

all: main

main: main.o ChessPiece.o ChessPieceFactory.o ChessPieceDescriptor.o
	g++ $(CFLAGS) main.o ChessPiece.o ChessPieceFactory.o ChessPieceDescriptor.o -o main 

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

clean:
	rm -f main.o Square.o Board.o ChessPiece.o ChessPieceFactory.o ChessPieceDescriptor.o main
