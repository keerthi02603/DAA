#include<stdio.h>
#include<math.h>
#define MAX_SIZE 100
int ss(int n,int s,int wt[]);
int main(){
int i,n,s;
int wt[MAX_SIZE];
printf("enter the size of values");
scanf("%d",&n);
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
if(s==0){
return 1;}
else if(n==0){
return 0;}
else if(wt[n-1]<=s)
{
return ss(n-1,s-wt[n-1],wt)+ss(n-1,s,wt);
}
else
{
return ss(n-1,s,wt);
}
}

