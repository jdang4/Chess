CFLAGS = -g -std=c++14 -Wall

all: main

main: main.o ChessPiece.o ChessPieceFactory.o ChessPieceDescriptor.o Square.o Board.o ChessMovementRules.o RuleProvider.o
	g++ $(CFLAGS) main.o ChessPiece.o ChessPieceFactory.o ChessPieceDescriptor.o Square.o Board.o ChessMovementRules.o RuleProvider.o -o main 

main.o: main.cpp 
	g++ $(CFLAGS) -c main.cpp 

ChessPiece.o: chess/ChessPiece.cpp chess/headers/ChessPiece.h chess/headers/ChessPieceFactory.h 
	g++ $(CFLAGS) -c chess/ChessPiece.cpp

ChessPieceFactory.o: chess/ChessPieceFactory.cpp chess/headers/ChessPieceFactory.h 
	g++ $(CFLAGS) -c chess/ChessPieceFactory.cpp

ChessPieceDescriptor.o: chess/ChessPieceDescriptor.cpp chess/headers/ChessPieceDescriptor.h 
	g++ $(CFLAGS) -c chess/ChessPieceDescriptor.cpp

Board.o: util/Board.cpp util/headers/Board.h util/headers/Square.h
	g++ $(CFLAGS) -c util/Board.cpp	

Square.o: util/Square.cpp util/headers/Square.h 
	g++ $(CFLAGS) -c util/Square.cpp

ChessMovementRules.o : chess/ChessMovementRules.cpp chess/headers/ChessMovementRules.h util/headers/Square.h util/headers/Board.h
	g++ $(CFLAGS) -c chess/ChessMovementRules.cpp

RuleProvider.o : chess/RuleProvider.cpp chess/headers/RuleProvider.h chess/headers/ChessMovementRules.h util/headers/Square.h util/headers/Board.h
	g++ $(CFLAGS) -c chess/RuleProvider.cpp

clean:
	rm -f main.o ChessPiece.o ChessPieceFactory.o ChessPieceDescriptor.o Square.o Board.o RuleProvider.o ChessMovementRules.o main
