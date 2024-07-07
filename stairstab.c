#include<stdio.h>
# define max_size 100
int stairs(int);
int a[max_size];
int main()
{
int i,n,temp=0;
printf("enter the values");
scanf("%d",&n);
for(i=0;i<max_size;i++)
{
a[i]=-1;
}
/*for(i=0;i<n;i++)
{
temp=temp+stairs(i);
}*/
for(int i=0;i<n;i++)
{
printf("%d",stairs(i));
}
}
int stairs(int n)
{
if(a[n]!=-1)
{
return a[n];
}
for(int i=0;i<=n;i++)
{
if(n==0 ||n==1)
{
return a[i]=1;
}
else
{
return a[i]=stairs(n-1)+stairs(n-2);
}
}
return a[n];
}
 
