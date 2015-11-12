#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	
	for(int q=0;q<t;q++)
	{
		int xe,ye;char re;
		cin>>xe>>ye>>re;
		int n;
		cin>>n;
		double min=-1;		
		for(int i=0;i<n;i++)
		{
			int x,y,d;
			char r;
			//cout<<"enter:";
			//scanf("%d",&x);
			//scanf("%d",&y);
			//scanf("%c",&r);
			cin>>x>>y>>r;

			x-=xe;y-=ye;
			if(r=='U')
				d=1;
			if(r=='R')
				d=2;
			if(r=='D')
				d=3;
			if(r=='L')
				d=4;
			if(abs(x)==abs(y) || x==0 || y==0)
			{

			
			
				if(x>0 && y>0 && ((d==4 && re=='U') || (d==3 && re=='R')))
				{
					if(min>abs(x)||min==-1)
					min=abs(x);
				}
				if(x<0 && y>0 && ((d==2 && re=='U') || (d==3 && re=='L')))
				{
					if(min>abs(x)||min==-1)
					min=abs(x);
				}

				if(x<0 && y<0 && ((d==1 && re=='L') || (d==2 && re=='D')))
				{
					if(min>abs(x)||min==-1)
					min=abs(x);
				}

				if(x>0 && y<0 && ((r=='L' && re=='D') || (r=='U' && re=='R')))
				{
					if(min>abs(x)||min==-1)
					min=abs(x);
				}

				if(x>0 && y==0 && ((r=='L' && re=='R')))
				{
				
					if(min>(double)abs(x)/2 || min==-1)
					min=(double)abs(x)/2;
				
				}

				if(x==0 && y>0 && ((r=='D' && re=='U') ))
				{
					if(min>(double)abs(y)/2 ||min==-1)
					min=(double)abs(y)/2;
				}

				if(x<0 && y==0 && ((r=='R' && re=='L') ))
				{
				
					if(min>(double)abs(x)/2 || min==-1)
					min=(double)abs(x)/2;
				
				}

				if(x==0 && y<0 && ((r=='U' && re=='D')))
				{
					if(min>(double)abs(y)/2 ||min==-1)
					min=(double)abs(y)/2;
				}
			
			}						
		}
		if(min==-1)
		cout<<"SAFE\n";
		else
		printf("%.1f\n",min);		
	}	
		
}
/*int slope(char re,int d)
{
	if((re=='U' && d==2) || (re=='D' && d==4))
	return 1;
	else
	if(re=='U')
}*/