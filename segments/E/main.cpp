#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstdlib>

#include<vector>
#include<map>
#include<set>
#include<cstring>
#include<queue>
#include<deque>
#include<stack>

#include<cmath>
#include<algorithm>




#define ll long long
#define pb push_back
#define f first
#define s second
#define all(c) c.begin(),c.end()
#define len(s) s.size()
#define inf32 (int)10E8*2
#define inf64 (long long)10E17*9
#define inf86 (double)10E14*9

using namespace std;

    const long long MAXN=500000+4;
	long long ar[MAXN],tSum[MAXN*4];
	void build_sum(long long a[],long long v, long long tl, long long tr)
	{
		if(tl==tr)
		{
			tSum[v]=a[tl];	
		}
		else
		{
			long long tm=(tl+tr)/2;
			build_sum(a,v*2,tl,tm);
			build_sum(a,v*2+1,tm+1,tr);
			tSum[v]=tSum[v*2]+tSum[v*2+1];
		}                   
	}

	long long sum (long long v, long long l, long long r, long long tl, long long tr) 
	{
		if (l > r)
			return 0;
		if (l == tl && r == tr)
			return tSum[v];
		long long tm = (tl + tr) / 2;
		return sum (v*2, l, min(r,tm),tl, tm) + sum (v*2+1, max(l,tm+1), r, tm+1, tr);
	}


	void updateSum(long long v,long long tl, long long tr,long long pos, long long newVal)
	{
		if(tl==tr)
		{
			tSum[v]=newVal;		
		}
		else
		{
			long long tm=(tr+tl)/2;
			if(pos<=tm)
			{
				updateSum(v*2,tl,tm,pos,newVal);
			}
			else
			{
				updateSum(v*2+1,tm+1,tr,pos,newVal);
			}
			tSum[v]=tSum[v*2]+tSum[v*2+1];
		}
	}

int main()
{
	ios_base::sync_with_stdio(0);
	freopen("rsq.in ","r",stdin);
	freopen("rsq.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>ar[i];
	}
	string query;
	build_sum(ar,1,1,n);
	while(cin>>query){
		long long x,y;
		cin>>x>>y;
		if(query=="sum")
		{
			long long ans = sum(1,x,y,1,n);
			cout<<ans<<endl;	
		}
		else
		{
			updateSum(1,1,n,x,y);
		}
	}	
	return 0;
}


