#include<iostream>
#include<cstdio>
#include"Sudoku.h"
using namespace std;

int main()
{
	Sudoku ss;
	ss.readIn();
//	ss.transform();
//	ss.flip(1);




//	ss.printout(false);
	ss.rotate(1);
	ss.solve();
	return 0;
}
