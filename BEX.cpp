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
vi v;
vector<string>s;
vi mi;
int pos;
inline int insert(int n,string a)
{
	if(pos<v.size())
	{
		v[pos]=n;
		s[pos]=a;
		if(pos>0 && v[mi[pos-1]]<n)
		{
			mi[pos]=mi[pos-1];
		}
		else mi[pos]=pos;		
	}
	else 
	{
		v.pb(n);
		s.pb(a);
		if(pos>0 && v[mi[pos-1]]<n)
		{
			mi.pb(mi[pos-1]);
		}
		else mi.pb(pos);
	}
	pos++;
	/*for(int i=0;i<pos;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<"\n";
	for(int i=0;i<pos;i++)
	{
		cout<<mi[i]<<" ";
	}
	cout<<"\n"<<pos<<"\n";
*/
}
inline long remove(long &ans)
{
	long index=mi[pos-1];
	ans=pos-mi[pos-1]-1;
	pos=mi[pos-1];
	return index;
}
int main()
{
	ll t;
	scanf("%lld",&t);
	pos=0;	
	f(q,0,t)
	{
		long n;
		char arr[16];
		scanf("%ld",&n);
		if(n!=-1)
		{
			scanf("%s",arr);
			string a(arr);
			if(n!=0)	
			insert(n,a);
		}	
		else 
		{
			long ans;
			long num =remove(ans);
			string a=s[num];
			printf("%ld %s\n",ans,a.c_str());
		}
		
	}
	return 0;
}