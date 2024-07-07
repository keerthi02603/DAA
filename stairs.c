#include<stdio.h>
int stairs(int);
int main()
{
int i,n,a[100],temp=0;
printf("enter the values");
scanf("%d",&n);
int f=stairs(n);
for(i=0;i<n;i++)
{
temp=temp+stairs(i);
}
for(int i=0;i<n;i++)
{
printf("%d",stairs(i));
}
}
int stairs(int n)
{
if(n==1 || n==0)
{
return 1;
}
else
{
return stairs(n-1)+stairs(n-2);
}
}

