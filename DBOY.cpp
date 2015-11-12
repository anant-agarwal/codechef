#include<stdio.h>
#include<iostream>
#include<map>
#include<bitset>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

 
# define f(i,a,b) for(int i=a;i<b;i++)
# define TT "\t"
# define Clear(x) memset(x,0,sizeof(x))
# define fill(x,a) memset(x,a,sizeof(x))
# define pb push_back
# define mp make_pair
# define X first
# define Y second
# define inf 2147000000
# define linf 9223372036854770000LL
# define sqr(x) ((x)*(x))


typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector < pair<int, int > > vii;
typedef vector<int> vi;

int arr[501];
ll memo[1001];
ll solve(int r,int n)
{
	if(r==0)return 0;
	if(memo[r]!=-1)return memo[r];
	ll min=linf;
	f(i,0,n)
	{
		if(r>=arr[i])
		{
			ll tmp=solve(r-arr[i],n);
			if(tmp<min)
			{
				min=tmp;
			}
		}
	}
	if(min!=linf)
	memo[r]=1+min;
	else memo[r]=linf;
	return memo[r];
}
int main()
{
	int t;
	scanf("%d",&t);
	f(q,0,t)
	{
		int n;
		scanf("%d",&n);
		fill(memo,-1);
		int h[n];		
		int tmp;
		f(i,0,n)
		{
			scanf("%d",&tmp);
			h[i]=tmp;
		}
		f(i,0,n)
		{
			scanf("%d",&tmp);
			arr[i]=tmp;			
		}
		ll ans=0;
		f(i,0,n)
		{
			tmp=h[i];
			ans+=solve(2*tmp,n);
		}
		printf("%lld\n",ans);	
	}
	return 0;
}