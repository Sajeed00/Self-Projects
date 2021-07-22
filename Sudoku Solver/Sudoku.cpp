#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

class sudoku_solver
{
public:
	int sudoku[9][9];
	int fzr,fzc;
	bool complete=false;

	sudoku_solver()
	{
		get_input();
		find_fz();
		solver(1,fzr,fzc);
		show_output();
	}

	void find_fz()
	{
		int i,j;
		for(i=0;i<81;i++)
		{	
			if(sudoku[i/9][i%9]==0)
				{
					fzr=i/9;
					fzc=j%9;
					break;
				}
		}
	}

	void get_input()
	{
		int i,j;
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				cin>>sudoku[i][j];
			}
		}
	}

	void show_output()
	{
		int i,j;
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				cout<<sudoku[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	bool check(int n,int r,int c)
	{
		int i;
		for(i=0;i<9;i++)
		{
			if(sudoku[i][c]==n)
				return false;
			if(sudoku[r][i]==n)
				return false;
			if(sudoku[(r/3)*3+i/3][(c/3)*3+i%3]==n)
				return false;
		}
		return true;
	}

	void solver(int n,int r,int c)
	{
		int a,b;
		int nr=r;
		int nc=c;
		if(check(n,r,c))
		{
			sudoku[r][c]=n;
			if(r==8 && c==8)
			{
				complete=true;
				return;
			}
			else
			{
				while(sudoku[nr][nc]!=0)
				{
					if(nc==8)
					{
						nr++;
						nc=0;
					}
					else
					{
						nc++;
					}
				}
				solver(1,nr,nc);
				if(!complete)
					if(n<9)
						solver(n+1,r,c);
					else
						sudoku[r][c]=0;
			}
		}
		else
		{	
			if(n<9)
				solver(n+1,r,c);
			else
				sudoku[r][c]=0;
		}
		return;
	}
};



void code()
{
	sudoku_solver S;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input_s.txt", "r", stdin);
	freopen("output_s.txt", "w", stdout);
	#endif

	code();

	return 0;
}