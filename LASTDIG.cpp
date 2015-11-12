#include<iostream>
using namespace std;
long rem(long a)
{
long temp,sum=0;
while(a>0)
{
temp=a%10;
if(temp%2==0)
sum+=2*temp;
else
sum+=temp;
a/=10;
}
sum%=10;
return sum;
}
int main()
{
int t,x,y,temp,d1,d2;
cin>>t;
long a,b,diff,sum;
while(t--)
{
cin>>a>>b;
d1=10-a%10;
d2=b%10;
diff=b-a;
sum=0;
sum+=rem(a);
if(diff!=0)
{
y=b/10-a/10-1;
sum+=y*45;
for(int i=1;i<d1;i++)
sum+=rem(++a);
for(int i=0;i<=d2;i++)
sum+=rem(b--);
}
cout<<sum<<"\n";
}
}