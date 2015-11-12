#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int fac(int x)
{
	if(x==0||x==1)return 1;
	if(x==2)return 2;
	if(x==3)return 6;
	if(x==4)return 24;
	if(x==5)return 120;
	if(x==6)return 720;
	
}
int main()
{
	int x,n;
	cin>>x>>n;
	long count=0;	
	for(int q=0;q<n;q++)
	{
		
		string s;
		cin>>s;
		for(int i=1;i<=9;i++)
		{
			int free=0;
			for(int j=1;j<=4;j++)
			{
				if(s[(i-1)*4+j-1] =='0')
				free++;
				//cout<<(i-1)*4+j-1<<" ";
			}
			if(s[54-2*(i-1)-1]=='0')free++;
			if(s[53-2*(i-1)-1]=='0')free++;
			//cout<<54-2*(i-1)-1<<" "<<53-2*(i-1)-1<<"\n";
			if(free >=x)
			{count+=fac(free)/(fac(x)*fac(free-x));}
		}

	}
	cout<<count;
}