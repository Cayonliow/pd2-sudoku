all:Sudoku.o giveQuestion.cpp solve.cpp transform.cpp
		g++ -o giveQuestion giveQuestion.cpp Sudoku.o
		g++ -o solve solve.cpp Sudoku.o
		g++ -o transform transform.cpp Sudoku.o

Sudoku.o:
		g++ Sudoku.cpp Sudoku.o

clean:
	rm *.o giveQuestion solve transform
