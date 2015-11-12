#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
long long gcd(long long a,long long b);
int main()
{
	int t;
	cin>>t;
	for(int y=0;y<t;y++)
	{
		long long n,k;
		scanf("%lld %lld",&n,&k);
		//n=n-k;
		long long a,b;
		a=k-1;b=n-k;	
		if(a<b)
		{
			long long temp=a;
			a=b;
			b=temp;
		}
		long long res=1;
		for(long long x=n-1,y=1;x>a;x--,y++)
		{
			long long i=x,j=y;
			//long long fac=gcd(numer,j);
			//cout<<"recived "<<fac<<"\n";
			//numer/=fac;
			//j/=fac;
			//fac=gcd(denom,i);
			//cout<<"recived "<<fac<<"\n";
			//denom/=fac;
			//i/=fac;
			//fac=gcd(i,j);			
			//cout<<"recived "<<fac<<"\n";
		//	i/=fac;
		//	j/=fac;
			res*=i;
			res/=j;
			//cout<<"numerator is"<<numer<<"denom is"<<denom<<"\n";
		}
		cout<<res<<"\n";
	}
}
long long gcd(long long a,long long b)
{

	if(a==1 || b==1)
	return 1;
	if(a==0)
	return b;
	if(b==0)
	return a;
	if(a<b)
	{
		long long temp=b;
		b=a;
		a=temp; 	
	}
	return gcd(b,a%b);
}