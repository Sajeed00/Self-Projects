#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

class game_2048
{
public:
	int matrix[4][4];
	bool gamewin=false;

	game_2048()
	{
		int i,j;
		char ch;
		for(i=0;i<4;i++)
		{
			for (j=0;j<4;j++)
			{
				matrix[i][j] = 0;
			}
		}
		while(!endgame())
		{
			rand_ins();
			print_mat();
			do cin>>ch; while(invalidmove(ch));
		}

		if(gamewin)
			cout<<"\nYOU WIN";
		else
			cout<<"\nYOU LOSE";
	}


	bool invalidmove(char ch)
	{
		int i,j;
		int temp[4][4];
		if(endgame())
			return false;
		if (ch!='w'&& ch!='a'&& ch!='s'&& ch!='d')
		{
			cout<<"Invalid Move!!!"<<endl;
			return true;
		}	
		for(i=0;i<4;i++)
		{
			for (j=0;j<4;j++)
			{
				temp[i][j]=matrix[i][j];
			}
		}
		move(ch);
		for(i=0;i<4;i++)
		{
			for (j=0;j<4;j++)
			{
				if(temp[i][j]!=matrix[i][j])
					return false;
			}
		}
		cout<<"Invalid Move!!!"<<endl;
		return true;
	}

	void movel_1r(int a[4])
	{
		int i,j;
		for(i=0;i<3;i++)
		{
			if (a[i+1]==0)
			{
				for(j=i;j>=0;j--)
				{
					a[j+1]=a[j];
					a[j]=0;
				}
			}
		}
		for(i=3;i>0;i--)
		{
			if(a[i]==a[i-1])
			{
				a[i]=2*a[i];
				a[i-1]=0;
				for(j=i-1;j>0;j--)
				{
					a[j]=a[j-1];
					a[j-1]=0;
				}
			}
		}
		return;
	}


	void move(char ch)
	{
		int temp[4];
		switch(ch)
		{
			case 'd':
				for(int i=0;i<4;i++)
				{
					movel_1r(matrix[i]);
				}
				break;

			case 'w':
				for(int i=0;i<4;i++)
				{
					temp[0]=matrix[3][i];
					temp[1]=matrix[2][i];
					temp[2]=matrix[1][i];
					temp[3]=matrix[0][i];
					movel_1r(temp);
					matrix[3][i]=temp[0];
					matrix[2][i]=temp[1];
					matrix[1][i]=temp[2];
					matrix[0][i]=temp[3];
				}
				break;

			case 'a':
				for(int i=0;i<4;i++)
				{
					temp[0]=matrix[i][3];
					temp[1]=matrix[i][2];
					temp[2]=matrix[i][1];
					temp[3]=matrix[i][0];
					movel_1r(temp);
					matrix[i][3]=temp[0];
					matrix[i][2]=temp[1];
					matrix[i][1]=temp[2];
					matrix[i][0]=temp[3];
				}
				break;

			case 's':
				for(int i=0;i<4;i++)
				{
					temp[0]=matrix[0][i];
					temp[1]=matrix[1][i];
					temp[2]=matrix[2][i];
					temp[3]=matrix[3][i];
					movel_1r(temp);
					matrix[0][i]=temp[0];
					matrix[1][i]=temp[1];
					matrix[2][i]=temp[2];
					matrix[3][i]=temp[3];
				}
				break;
		}
		return;
	}


	bool endgame()
	{
		int i,j;

		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(matrix[i][j]==2048)
				{
					gamewin=true;
					return true;
				}
			}
		}

		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(matrix[i][j]==0)
					return false;
				if(i!=3 && matrix[i][j]==matrix[i+1][j])
					return false;
				if(i!=0 && matrix[i][j]==matrix[i-1][j])
					return false;
				if(j!=3 && matrix[i][j]==matrix[i][j+1])
					return false;
				if(j!=0 && matrix[i][j]==matrix[i][j-1])
					return false;
			}
		}
		return true;
	}


	void rand_ins()
	{	
		int a;
		srand(time(NULL));
		while(1)
		{
			a=rand()%16;
			if (matrix[a/4][a%4]==0)
			{
				matrix[a/4][a%4]=2;
				break;
			}
		}
		return;
	}


	void print_mat()
	{
		int i,j;
		system("cls");
		for(i=0;i<4;i++)
		{
			for (j=0;j<4;j++)
			{
				cout<<setw(4)<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
		return;
	}

};


void code()
{
	game_2048 G1;
}

int main(){
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/

code();

 return 0;
}