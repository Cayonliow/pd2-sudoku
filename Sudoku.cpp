#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib> 
#include<algorithm>
#include"Sudoku.h"

using namespace std;	

void Sudoku::giveQuestion()	//give question
{	
	count=0; 
	int question[81]={5,3,4,6,7,8,9,1,2,6,7,2,1,9,5,3,4,8,1,9,8,3,4,2,5,6,7,8,5,9,7,6,1,4,2,3,4,2,6,8,5,3,7,9,1,7,1,3,9,2,4,8,5,6,9,6,1,5,3,7,2,8,4,2,8,7,4,1,9,6,3,5,3,4,5,2,8,6,1,7,9};
						
	for(int i=0;i<81-51;i++)
	{
		srand(time(NULL));
		random[i]=rand()%81;
		count++;
		for(int j=0;j<i;j++)
		{
			if(random[i]==random[j])
			{
				random[i]=rand()%81;
				i--;
				count--;
				break;
			}
		}
		
	}
	
	for(int i=0;i<count;i++)
	{
		question[random[i]]=0;
	}
						
	for(int i=0;i<81;i++)
	{
		printf("%d%c",question[i],(i+1)%9==0?'\n':' ');	
	}
										
}

void Sudoku::readIn()	//read data
{
	for(int i=0;i<81;i++)
	{
		scanf("%d",&sudoku[i]);
	}	
}
	
void Sudoku::changeNum(int a,int b)	//exchange number
{
	for(int i=0;i<81;i++)
	{
		if(sudoku[i]==a)
		{
			sudoku[i]=b;
		}
		
		else if(sudoku[i]==b)
		{
			sudoku[i]=a;
		}
	}
}

void Sudoku::change()	//group of exchange
{
	sudokuNum=9;
	srand(time(NULL));
	changeNum(rand()%sudokuNum+1,rand()%sudokuNum+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}

void Sudoku::printout(bool isAns)	//determine whether there are solution
{
	if(isAns==false)
	{
		for(int i=0;0<81;i++)
		{
			printf("%d%c",sudoku[i],(i+1)%9==0?'\n':' ');
		}
	}
	
	else
	{
		for(int i=0;i<81;i++)
		{
			printf("%d%c",print[i],(i+1)%9==0?'\n':' ');		
		}	
	}
	 
}

void Sudoku::transform()	//transform the data
{
	change();
	printout(false);
}
void Sudoku::changeRow(int a,int b)	//exchange row
{
	if (a==b)
	{
		return;
	}
	
	for(int i=0;i<27;i++)
	{
		temp=sudoku[i+(3*a)*9];
		sudoku[i+(3*a)*9]=sudoku[i+(3*b)*9];
		sudoku[i+(3*b)*9]=temp;
			
	}
}

void Sudoku::changeCol(int a,int b)	//exchange column
{ 
	tempr=0;

	if(a==b)
	{
		return;
	}
	
	for(int j=0;j<3;j++)
	{
		for(int i=0;i<=72;i=i+9)
		{
			tempr=sudoku[j+i+(3*a)];
			sudoku[j+i+(3*a)]=sudoku[j+i+(3*b)];
			sudoku[j+i+(3*b)]=tempr;
		}
	}
}

void Sudoku::rotate(int n)	//rotate 90"
{ 
	for(int i=0;i<81;i++)
	{
		tt[i]=0;
	}
	
	if(n%4==0)
	{
		return;
	}
	
	if(n%4==1)
	{
		h=72;

		for(int i=0;i<81;i++)
		{
			tt[i]=sudoku[h];
			h=h-9;
			if((i+1)%9==0 && i>=8)
			{
				h=h+82;
			}
		}
	}
	
	if(n%4==2)
	{
		for(int i=0;i<81;i++)
		{
			tt[i]=sudoku[80-i];
		}
	}
	
	if(n%4==3)
	{
		int h=8;
		for(int i=0;i<81;i++)
		{
			tt[i]=sudoku[h];
			h=h+9;
			
			if((i+1)%9==0&&i>=8)
			{
				h=h-82;
			}
		}
	}
		
	for(int i=0;i<81;i++)
	{
		sudoku[i]=tt[i];
	}
}

void Sudoku::flip(int n)	//reflect
{
	 switch (n)
	{ 
		case 0:
	 	
			for(int i=0;i<4;++i) 
			{
	 			for (int j=0;j<9;++j) 
				{	
					swap(sudoku[i+j*9],sudoku[8-i+j*9]); 
				}
			}		
					
			break; 
		
		case 1: 

			for(int i = 0; i < 4; ++i) 
			{
				for(int j=0;j<9;++j)
				{	
					swap(sudoku[i*9+j],sudoku[(8-i)*9+j]);
				}
			}
			
			break; 
	}
	
}

///////////////////////////////////////////////////////////////////////////////////////////////

bool Sudoku::checkrow()	//
{
 	for(int row=0;row<9;row++)
	{	
		int check[10]={0};
 		check[0]=0;
	
		for(int i=1;i<10;i++)
		{
			if(sudoku[row*9+(i-1)]!=0)
			{
				check[sudoku[row*9+(i-1)]]++;
			}
		}
			
		for(int i=1;i<10;i++)
		{
			if(check[i]>1)
			{
				return false;
			}
		}
			
	}
			
	return true;	
} 
	 
bool Sudoku::checkcol()
{
	for(int col=0;col<9;col++)
	{
		int check[10]={0};
 		check[0]=0; 
	
	 	for(int i=1;i<81;i=i+9)
		{
			if(sudoku[col+i]!=0)
			{
				check[sudoku[col+i]]++;	
			} 	
		}
			
		for(int i=1;i<10;i++)
		{
			if(check[i]>1)
			{
				return false;	
			}	
		}	
	}
	 
	return true;
	
}
	 	 
bool Sudoku::checkcell()
{	
	for(int i=0;i<=54;i=i+3)
	{ 
 		int check[10]={0};
 		check[0]=0;
		
		if(i==9||i==36)
		{
			i=i+18;
		}
		for(int j=i;j<i+3;j++)
		{
			if(sudoku[j]!=0)
			{
				check[sudoku[j]]++;
			}
		
			if(sudoku[9+j]!=0)
			{
				check[sudoku[9+j]]++;
			}
		
			if(sudoku[18+j]!=0)
			{
				check[sudoku[18+j]]++;
			}
		}
	
		for(int i=1;i<10;i++)
		{
			if(check[i]>1)
			{
				return false;
			}
		}
	}
	
	return true;	
	
}

bool Sudoku::isAns()
{
	if(checkrow()==true&&checkcol()==true&&checkcell()==true)
	{
		return true;
	}
	
	else
	{
		return false;
	}
	
}

bool Sudoku::checkINrow(int place,int n)
{
	int gg=(place/9)*9;
	for(int i=0;i<9;i++)
	{
		if(gg+i!=place)
		{
			if( sudoku[gg+i]==n )
			{
				return false;
			}
		}	
	}
	return true;	
} 
	 
bool Sudoku::checkINcol(int place,int n)
{
	for(int i=0;i<81;i=i+9)
	{
		if(place>=0&&place<=8)
		{
			if((place+i)!=place)
			{
				if(sudoku[(place)+i]==n)
				{
					return false;
				}
			}
		}

		if(place>=9&&place<=80)
		{
			int gg=place%9;
			
			if(gg+i!=place)
			{
				if(sudoku[gg+i]==n)
				{
					return false;
				}
			}
		}
	}

	return true;

}
	 	 
bool Sudoku::checkINcell(int place,int n)
{	
	if(place>=0&&place<=2||place>=9&&place<=11||place>=18&&place<=20)
	{
		for(int i=0;i<3;i++)
		{
			if(sudoku[0+i]==n)
			{
				if((0+i)!=place)
				return false;
			}
	
			if(sudoku[9+i]==n)
			{
				if((9+i)!=place)

				return false;
			}
	
			if(sudoku[18+i]==n)
			{
				if((18+i)!=place)

				return false;
			}
		}
	
	}
	
	if(place>=3&&place<=5||place>=12&&place<=14||place>=21&&place<=23)
	{
		for(int i=0;i<3;i++)
		{
			if(sudoku[3+i]==n&&(3+i)!=place)
			{
				return false;
			}
		
			if(sudoku[12+i]==n&&(12+i)!=place)
			{
				return false;
			}
		
			if(sudoku[21+i]==n&&(21+i)!=place)
			{
				return false;
			}
		}
	}
	
	if(place>=6&&place<=8||place>=15&&place<=17||place>=24&&place<=26)
	{
		for(int i=0;i<3;i++)
		{
			if(sudoku[6+i]==n&&(6+i)!=place)
			{
				return false;
			}
			
			if(sudoku[15+i]==n&&(15+i)!=place)
			{
				return false;
			}
		
			if(sudoku[24+i]==n&&(24+i)!=place)
			{
				return false;
			}
		}
	}
	
	if(place>=27&&place<=29||place>=36&&place<=38||place>=45&&place<=47)
	{
		for(int i=0;i<3;i++)
		{
			if(sudoku[27+i]==n&&(27+i)!=place)
			{
				return false;
			}
			
			if(sudoku[36+i]==n&&(36+i)!=place)
			{
				return false;
			}
		
			if(sudoku[45+i]==n&&(45+i)!=place)
			{
				return false;
			}
		}
	}
	
	if(place>=30&&place<=32||place>=39&&place<=41||place>=48&&place<=50)
	{
		for(int i=0;i<3;i++)
		{
			if(sudoku[30+i]==n&&(30+i)!=place)
			{
				return false;
			}
					
			if(sudoku[39+i]==n&&(39+i)!=place)
			{
				return false;
			}
		
			if(sudoku[48+i]==n&&(48+i)!=place)
			{
				return false;
			}
		}
	}
	
	if(place>=33&&place<=35||place>=42&&place<=44||place>=51&&place<=53)
	{
		for(int i=0;i<3;i++)
		{
			if(sudoku[33+i]==n&&(33+i)!=place)
			{
				return false;
			}
			
			if(sudoku[42+i]==n&&(42+i)!=place)
			{
				return false;
			}
		
			if(sudoku[51+i]==n&&(51+i)!=place)
			{
				return false;
			}
		}
	}
	
	if(place>=54&&place<=56||place>=63&&place<=65||place>=72&&place<=74)
	{
		for(int i=0;i<3;i++)
		{
			if(sudoku[54+i]==n&&(54+i)!=place)
			{
				return false;
			}
			
			if(sudoku[63+i]==n&&(63+i)!=place)
			{
				return false;
			}
		
			if(sudoku[72+i]==n&&(72+i)!=place)
			{
				return false;
			}
		}
	}
	
	if(place>=57&&place<=59||place>=66&&place<=68||place>=75&&place<=77)
	{
		for(int i=0;i<3;i++)
		{
			if(sudoku[57+i]==n&&(57+i)!=place)
			{
				return false;
			}
			
			if(sudoku[66+i]==n&&(66+i)!=place)
			{
				return false;
			}
		
			if(sudoku[75+i]==n&&(75+i)!=place)
			{
				return false;
			}
		}
	}
	
	if(place>=60&&place<=62||place>=69&&place<=71||place>=78&&place<=80)
	{
		for(int i=0;i<3;i++)
		{
			if(sudoku[60+i]==n&&(60+i)!=place)
			{
				return false;
			}
			
			if(sudoku[69+i]==n&&(69+i)!=place)
			{
				return false;
			}
		
			if(sudoku[78+i]==n&&(78+i)!=place)
			{
				return false;
			}
		}
	}
	
	return true;
}

void Sudoku::BackTrack(int place)
{
	for(int i=1;i<10;i++)
	{
		if(checkINrow(place,i)==true&&checkINcol(place,i)==true&&checkINcell(place,i)==true)
		{
			sudoku[place]=i;
			if(place==yo)
			{
				solution++;
				if(solution>=2)return;
				for(int j=0;j<81;j++)
				{
					print[j]=sudoku[j];
				}
			}

			for(int h=place+1;h<81;h++)
			{
				if(sudoku[h]==0)
				{
					BackTrack(h);
					break;
				}		
			}		
		}		
	}			
	sudoku[place]=0;						
}				
				
				
void Sudoku::solve()
{	
	solution=0;
	if(isAns()==false)
	{
		printf("0\n");
		return;
		
	}

	yo=0;
	for(int i=80;i>=0;i--)
	{
		if(sudoku[i]==0)
		{
			yo=i;
			break;
		}
	}
	got=0;
	for(int i=0;i<81;i++)
	{
		if(sudoku[i]!=0)
		{
			got++;
		
			if(got==81)
			{
				for(int j=0;j<81;j++)
				{
					print[j]=sudoku[j];
				}
			solution=1;
			break;
			}
		
		}
	
		else
		{
			BackTrack(i);			
			break;
		}
	}
	
	if(solution==0)
	{
		printf("0\n");
		return;
	}
	
	if(solution==1)
	{
		printf("1\n");
		printout(true);
		return;
	}
	
	if(solution>=2)
	{
		printf("2\n");
		return;
	}
} 
		
 
