#include<stdio.h>
#include<math.h>
#define MAX_SIZE 100
int a[MAX_SIZE][MAX_SIZE];
int ss(int n,int s,int wt[]);
int main(){
int i,n,s;
int wt[MAX_SIZE];
printf("enter the size values");
scanf("%d",&n);
for(i=0;i<MAX_SIZE;i++)
{
for(int j=0;j<MAX_SIZE;j++)
{
a[i][j]=-1;
}
}
printf("enter the values");
for(i=0;i<n;i++){
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
for(int i=0;i<=n;i++)
{
for(int j=0;j<=s;j++)
{
if(i==0){
a[i][j]=(j==0)?1:0;
}
else{
/*if(j==0){
return 
a[i][j]=1;
continue;
}*/

if(wt[i-1]<=j){
a[i][j]=a[i-1][j-wt[i-1]]+a[i-1][j];
}
else
{
a[i][j]=a[i-1][j];
}
}
}

}
return a[n][s];
}
