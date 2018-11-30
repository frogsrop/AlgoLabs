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

    const int MAXVAL=1000000000+7;
	const int MAXN=500000+4;
	int ar[MAXN],artmin[MAXN*4];
	void build_min(int* a, int v, int tl,int tr)
	{
		if(tl==tr)
		{
			artmin[v]=a[tl];
		}
		else
		{
			int tm=(tr+tl)/2;
			build_min(a,v*2,tl,tm);
			build_min(a,v*2+1,tm+1,tr);
			artmin[v]=min(artmin[v*2],artmin[v*2+1]);
		}
	}

	int tmin(int v, int l, int r, int tl, int tr)
	{
		if (l > r)
		{
			return MAXVAL;
		}
		if(tl==l && tr==r)
		{
			return artmin[v];
		}
		int tm=(tl+tr)/2;
		return min(tmin(v*2,l,min(tm,r),tl,tm),tmin(v*2+1,max(tm+1,l),r,tm+1,tr));
	}

	void updateMin(int v,int tl, int tr,int pos, int newVal)
	{
		if(tl==tr)
		{
			artmin[v]=newVal;		
		}
		else
		{
			int tm=(tr+tl)/2;
			if(pos<=tm)
			{
				updateMin(v*2,tl,tm,pos,newVal);
			}
			else
			{
				updateMin(v*2+1,tm+1,tr,pos,newVal);
			}
			artmin[v]=min(artmin[v*2], artmin[v*2+1]);
		}
	}

int main()
{
	ios_base::sync_with_stdio(0);
	freopen("rmq.in ","r",stdin);
	freopen("rmq.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}
	string query;
	build_min(ar,1,1,n);
	while(cin>>query){
		int x,y;
		cin>>x>>y;
		if(query=="min")
		{
			int ans = tmin(1,x,y,1,n);
			cout<<ans<<endl;	
		}
		else
		{
			updateMin(1,1,n,x,y);
		}
	}	
	return 0;
}


