#include<stdio.h>
#include<math.h>
#define MAX_SIZE 100
int a[MAX_SIZE][MAX_SIZE];
int ss(int n,int s,int wt[]);
int main(){
int n,s;
int wt[MAX_SIZE];

printf("enter the size values");
scanf("%d",&n);
for(int i=0;i<MAX_SIZE;i++)
{
for(int j=0;j<MAX_SIZE;j++)
{
a[i][j]=-1;
}
}
printf("enter the values");
for(int i=0;i<n;i++){
scanf("%d",&wt[i]);
}
printf("enter the sum of the values");
scanf("%d",&s);
int result=ss(n,s,wt);
printf("the maximum vales %d\n",result);
return 0;
}

int ss(int n,int s,int wt[])
{
if(a[n][s]!=-1)
return a[n][s];
if(s==0){
return a[n][s]=1;
}
if(n==0){
return a[n][s]=0;
}
if(wt[n-1]<=s)
{
return a[n][s]=ss(n-1,s-wt[n-1],wt)+ss(n-1,s,wt);
}
else
{
return a[n][s]=ss(n-1,s,wt);
}
}

