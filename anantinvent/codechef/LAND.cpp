#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int p=0;p<t;p++)
	{
		int x[100][100][2]={0};
		int n,m,av=0,count=0;
		cin>>n>>m;	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&x[i][j][0]);
				if(x[i][j][0]!=0)
				{x[i][j][1]=1;av+=x[i][j][0];count++;}
			}
		}
		av/=count;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(x[i][j][1]==0)
				{x[i][j][0]=av;continue;}
				if(x[i][j][1]==1)
				{
					if(j>=1)
					{
						if(x[i][j-1][1]==2)
						x[i][j-1][0]=(x[i][j-1][0]+x[i][j][0])/2;
						else
						{
							x[i][j-1][0]=x[i][j][0];
							x[i][j-1][1]=2;
							//cout<<"changed "<<i<<" "<<j-1<<"to "<<x[i][j-1][0]<<x[i][j][0]<<"\n";
						}
					}
					if(j<m-1)
					{
						if(x[i][j+1][1]==2)
						x[i][j+1][0]=(x[i][j+1][0]+x[i][j][0])/2;
						else
						{
							x[i][j+1][0]=x[i][j][0];
							x[i][j+1][1]=2;
							//cout<<"changed "<<i<<" "<<j+1<<"to "<<x[i][j+1][0]<<x[i][j][0]<<"\n";
						}
					}
					if(i>=1)
					{
						if(x[i-1][j][1]==2)
						x[i-1][j][0]=(x[i-1][j][0]+x[i][j][0])/2;
						else
						{
							x[i-1][j][0]=x[i][j][0];
							x[i-1][j][1]=2;
							//cout<<"changed "<<i-1<<" "<<j<<"to "<<x[i-1][j][0]<<x[i][j][0]<<"\n";
						}
					}
					if(i<n-1)
					{
						if(x[i+1][j][1]==2)
						x[i+1][j][0]=(x[i+1][j][0]+x[i][j][0])/2;
						else
						{
							x[i+1][j][0]=x[i][j][0];
							x[i+1][j][1]=2;
							//cout<<"changed "<<i+1<<" "<<j<<"to "<<x[i+1][j][0]<<x[i][j][0]<<"\n";
						}
					}
				}
			}
		}
		for(int k=0;k<100;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(x[i][j][1]==1)
					continue;
					int sum=0,val=0,count=0,count2=0;
					if(j>=1)
					{
						count++;
						sum+=x[i][j-1][0];
						if(x[i][j-1][1]==1)
						//x[i][j-1][0]=(x[i][j-1][0]+x[i][j][0])/2;
						{val=x[i][j-1][0];count2++;}					
					
					}
					if(j<m-1)
					{
						count++;
						sum+=x[i][j+1][0];
						if(x[i][j+1][1]==1)
						//x[i][j+1][0]=(x[i][j+1][0]+x[i][j][0])/2;
						{val=x[i][j+1][0];count2++;}
					
					}
					if(i>=1)
					{
						count++;
						sum+=x[i-1][j][0];
						if(x[i-1][j][1]==1){val=x[i-1][j][0];count2++;}
					//	x[i-1][j][0]=(x[i-1][j][0]+x[i][j][0])/2;
					
					}
					if(i<n-1)
					{
						count++;
						sum+=x[i+1][j][0];
						if(x[i+1][j][1]==1){val=x[i+1][j][0];count2++;}
					//	x[i+1][j][0]=(x[i+1][j][0]+x[i][j][0])/2;
					
					}
					//if(count2!=1)
					{x[i][j][0]=sum/count;
					//cout<<"---changed "<<i<<" "<<j<<"to "<<x[i][j][0]<<"\n";
					}
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			printf("%d ",x[i][j][0]);
			cout<<"\n";
		}
		cout<<"\n";
	}

			
}