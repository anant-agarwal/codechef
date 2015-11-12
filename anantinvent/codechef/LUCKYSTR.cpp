#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
	vector<string>v;
int is(string s, string v);
int chk(string s)
{
	if(s.size() >=47)
		return 1;

	int k=v.size();
	for(int i=0;i<k;i++)
	{	
	/*	for(int j=0;j<s.size()-v[i].size();j++)
		{
			int fl=0;
			for(int k=0;k<v[i].size() && j+k<s.size();k++)
			{
				if(s[j+k]!=v[i][k])
				{fl=1;break;}
			}
			if(fl==0)
				return 1;
		}
	*/
		if(is(s,v[i]))return 1;
	}
	return 0;
}
int is(string s, string v)
{
	int fl=1;
	for(int i=0;i<s.size();i++)
	{
		int j;
		for( j=0;j<v.size() && i+j< s.size();j++)
		{
			if(s[i+j]!=v[j])
				break;
		}
		if(j==v.size())return 1;
		
	}	
	return 0;
}
int main()
{
	int n,k;
	cin>>k>>n;
	for(int i=0;i<k;i++)
	{	
		string s;
		cin>>s;
		v.push_back(s);
	}	
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		if(chk(s))
		printf("Good\n");
		else printf("Bad\n");	
	}
}