#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;
long c=0;
int create(long d,long long num)
{
	if(d==0)
	{
		long long y=num;
		int c3=0,c5=0,c8=0;
		while(y)
		{
			if(y%10==3)c3++;
			else if(y%10==5)c5++;
			else if(y%10==8)c8++;
			y/=10;
		}
		if(c8>=c5 && c5>=c3)
		{
			printf("%lld\n",num);
			c++;
			if(c==50000)exit(0);
		}
	}
	else
	{
		create(d-1,num*10+3);
		create(d-1,num*10+5);
		create(d-1,num*10+8);
	}
}
int main()
{
	long i=1;
	while(c<50000)
	{
		create(i,0);
		i++;
	}
}