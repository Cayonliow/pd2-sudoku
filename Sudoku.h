//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<ctime>
//#include<cstdlib> 
//#include"Sudoku.h"
class Sudoku{
	

	public:
			
			void giveQuestion();
			void readIn();
			void changeNum(int a,int b);
			void changeRow(int a,int b);
			void changeCol(int a,int b);
			void rotate(int n);
			void flip(int n); 
			void solve();
			void change();
			void transform();

			bool checkrow();
			bool checkcol();
			bool checkcell();
			bool isAns();
			void printout(bool isAns);
			void transform();
			bool checkINrow(int place,int n);
			bool checkINcol(int place,int n);
			bool checkINcell(int place,int n);
			void BackTrack(int place);
			
			

		private:	
			
			int sudoku[81];
			int random[81];
			int print[81];
			int count;
			int temp;
			int tempr;
			int tt[81];
			int h;
			int r[81];
			int k;
			int p[81];
			int poss[81][10]; 
			int space; 
			int row_tocheck;
			int col_tocheck;
			int cell_tocheck;
			int flag;
			int a,b;
			int sudokuNum;
			int got;
			int solution;
			int mark;
			int next;
			int yo;

};
	
