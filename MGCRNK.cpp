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


ll memo[101][101];
int arr[101][101];
inline bool valid(int i,int j, int n)
{
	if(i<=n-1 && j<=n-1)return 1;
	else return 0;
}
ll solve(int n,int i,int j)
{
	if(i==n-1 && j==n-1)return 0;
	
	if(memo[i][j]!=-1)return memo[i][j];

	ll a1,a2,ans;
	bool b1=valid(i+1,j,n),b2=valid(i,j+1,n);
	if(b1)a1=solve(n,i+1,j);
	if(b2)a2=solve(n,i,j+1);
	if(b1&&b2)
	{
		ans=arr[i][j]+max(a1,a2);
	}
	else if(b1)
	{
		ans=arr[i][j]+a1;
	}
	else ans=arr[i][j]+a2;
	
	memo[i][j]=ans;
	return ans;
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

		int tmp;
		f(i,0,n)
		{
			f(j,0,n)
			{
				scanf("%d",&tmp);
				arr[i][j]=tmp;			
			}
		}
		ll ans=solve(n,0,0);
		double final=(double)ans/(n-1+n-1-1);
		if(ans>=0)
		printf("%0.6f\n",final);	
		else
		printf("Bad Judges\n");
	}
	return 0;
}