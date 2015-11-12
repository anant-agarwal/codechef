#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;
int main()
{
	int n;
	cin>>n;
	
	long count=0;
	for(int q=0;q<n;)
	{
		string s;
		
		char ch=getchar();
		//while(ch=='\n' || ch=='\r' )
		//ch=getchar();	
		getline(cin,s);
		if(s.size()==0)
		continue;
		q++;
		long n5=0,n3=0,n8=0,flag=0;
		int i=s.size()-1;
		while(s[i]>'9' || s[i]<'0')
		i--;
		for(;i>=0 && s[i]!=' ';i--)
		{
			if(s[i]=='5')
				n5++;
			else if(s[i]=='3')
				n3++;
			else if(s[i]=='8')
				n8++;
			else flag=1;
		}
		if(!flag)
		{
			if(n8>=n5 && n5>=n3)
			count++;
		}
		
	}
	cout<<count<<"\n";
}