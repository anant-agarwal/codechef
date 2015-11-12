#include<iostream>
#include<cstdio>
using namespace std;
int dfs(int u,int p,bool arr[][101],bool visited[],int parent[],int n);
int main()
{
	int t;
	cin>>t;
	for(int q=0;q<t;q++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		bool arr[101][101]={0};
		int parent[101]={0};
		//memset(arr,0,sizeof(arr));
		bool visited[101]={0};
		for(int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			arr[a][b]=1;
			arr[b][a]=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(visited[i]==0)
			dfs(i,i,arr,visited,parent,n);	
		}
		int w;
		scanf("%d",&w);
		for(int i=0;i<w;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(parent[x]==parent[y])
				cout<<"YO\n";
			else
				cout<<"NO\n";
		}
	}
}
int dfs(int u,int p,bool arr[][101],bool visited[],int parent[],int n)
{
	visited[u]=1;
	parent[u]=p;
	for(int i=0;i<=n;i++)
	{
		if(arr[u][i] && !visited[i])
		{
			dfs(i,p,arr,visited,parent,n);
		}
	}
}