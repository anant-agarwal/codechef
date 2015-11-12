#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	map<string,int>graph;
	//vector<string>x;
	for(int i=1;i<=n;i++)
	{
		string a;
		cin>>a;
		//x.push_back(a);
		graph[a]=i;
	}	
	int m;
	cin>>m;
	int weight[51][51]={0};
	for(int i=0;i<m;i++)
	{
		string a,b;
		cin>>a>>b;
		int w;
		cin>>w;
		weight[graph[a]][graph[b]]=w;
	}
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int flag=0;
		int num;
		cin>>num;
		string tmp;
		cin>>tmp;
		//cout<<"inputed"<<tmp;
		int s=graph[tmp];
		int d;
		char visited[51]={0};
		if(s==0)
		{
			flag=1;
			//cout<<"ERROR\n";
			//continue;
		}
		visited[s]=1;
		long sum=0;
		
		for(int j=1;j<num;j++)
		{
			//string tmp;
			cin>>tmp;
			d=graph[tmp];
			if(d==0 || visited[d]==1)
			{
				//cout<<"ERROR\n";
				flag=1;
				//break;
		
			}
			if(weight[s][d]==0)
			{
				//cout<<"ERROR\n";
				flag=1;
				//break;
			}
			else
			{
				sum+=weight[s][d];
				visited[d]=1;
			}
			//int q=s;
			s=d;
		
		}
		if(flag==1)
		cout<<"ERROR\n";
		else
		cout<<sum<<"\n";
	}
}