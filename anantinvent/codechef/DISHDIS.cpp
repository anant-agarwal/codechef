#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int p=0;p<t;p++)
	{
		int n,m;
		cin>>n>>m;
		
		vector<int>y;
		
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			//x.push_back(a);
			n-=a;b-=a;
			y.push_back(b);
		}
	
		long long w[101][101];
		for(int j=0;j<=y[0] && j<=n;j++)
		{
			w[0][j]=1;
		}
		for(int j=y[0]+1;j<=n;j++)
		w[0][j]=0;
	
		for(int j=0;j<m;j++)
		w[j][0]=1;

		for(int i=1;i<m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				w[i][j]=0;
				if(j<=y[i])
				w[i][j]=(w[i][j-1]+w[i-1][j])%1000000007;
				else
				{
					w[i][j]=((w[i][j-1]+w[i-1][j])-w[i-1][j-y[i]-1]);
					w[i][j]=(w[i][j]+1000000007)%1000000007;
				}
			}
		}
		if(n==0)
		cout<<"1"<<"\n";
		else if(n<0)
		cout<<"0"<<"\n";
		else
		cout<<w[m-1][n]<<"\n";
		
	}
	return 0;
}