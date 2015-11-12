#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	char arr[101][101];
	for(int q=0;q<t;q++)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		
		for(int i=0;i<r;i++)
		{
			scanf("%s",arr[i]);
			//printf("%s",arr[r]);
		}
		int flag=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				//cout<<arr[i][j];
				if( j+4<c && (arr[i][j]=='S' || arr[i][j]=='s')  && (arr[i][j+1]=='p' || arr[i][j+1]=='P') && (arr[i][j+2]=='o' || arr[i][j+2]=='O') && (arr[i][j+3]=='o' || arr[i][j+3]=='O') && (arr[i][j+4]=='N' || arr[i][j+4]=='n'))
				{flag=1;break;}
				if( i+4<r && (arr[i][j]=='S' || arr[i][j]=='s')  && (arr[i+1][j]=='p' || arr[i+1][j]=='P') && (arr[i+2][j]=='o' || arr[i+2][j]=='O') && (arr[i+3][j]=='o' || arr[i+3][j]=='O') && (arr[i+4][j]=='N' || arr[i+4][j]=='n'))

				{flag=1;break;}
			} 
			//cout<<"\n";
		}

		if(flag)cout<<"There is a spoon!\n";
		else
		cout<<"There is indeed no spoon!\n";
	}
}