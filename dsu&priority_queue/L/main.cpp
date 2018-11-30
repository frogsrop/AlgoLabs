#include<bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define ll long long
using namespace std;

ll dp[200005];
int par[200005], n=0;
ll ans=0;
   
int main()
{
   	cin>>n;
   	for(int i=0;i<=n;i++)
   	{
   		dp[i]=0;
   		par[i]=0;
   	}
    for(int i=1;i<=n;i++)
    {
    	int x;
    	ll y;
    	cin>>x>>y;
    	if(y==0)
    	{
    		while(x>0 && dp[x]==dp[par[x]])
            {
                x=par[x];
            }    		
            dp[i]=dp[par[x]];
    		par[i]=par[x];
    	}
    	else
    	{
    		dp[i]=dp[x]+y;
    		par[i]=x;
    	}
    }
    for(int i=1;i<=n;i++)
    {
    	ans+=dp[i];
    }
    cout<<ans;
    return 0;
}