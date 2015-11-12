#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int k=0;k<t;k++)
	{
		int n;
		cin>>n;
		vector<int>start;
		vector<int>end;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			start.push_back(x);
		}
		
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			end.push_back(x);
		}
		int a[1001]={0};
		for(int i=0;i<n;i++)
		{
			for(int j=start[i];j<end[i];j++)
			a[j]++;
		}
		int max=0;
		for(int i=0;i<1001;i++)
		{
			if(max<a[i])
			max=a[i];
		}
		cout<<max<<"\n";
	}
}