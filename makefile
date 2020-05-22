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

clean:
	rm -f main.o ChessPiece.o ChessPieceFactory.o ChessPieceDescriptor.o main
