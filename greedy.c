
fractional(int wt,int val,int n,int W)
{
res=0;
for(i=0;i<n;i++)
{
if(wt[i]<=W)
{
res=res+val[i];
W=W-WT[i];
}
else
{
res=res+W/wt[i]*val[i];
break;
}
