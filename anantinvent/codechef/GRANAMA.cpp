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



int main()
{
	int t;
	scanf("%d",&t);
	f(q,0,t)
	{
		char r[1002],s[1002];
		scanf("%s%s",r,s);
		vi count(26,0);	
		vi a(26,0);	
		vi b(26,0);		
		for(int i=0;r[i];i++)
		{
			count[r[i]-'a']++;
			a[r[i]-'a']=1;	
		}
		for(int i=0;s[i];i++)
		{
			count[s[i]-'a']--;		
			b[s[i]-'a']=1;
		}
		int fl=0,chef=0;
		f(j,0,26)
		{
			if(count[j]!=0){fl=1;break;}
		}
		f(j,0,26)
		{
			if(a[j]!=b[j]){chef=1;break;}
		}	
		if(chef!=fl)
		printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}