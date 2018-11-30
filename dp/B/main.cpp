#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define f first
#define s second
#define all(c) c.begin(),c.end()
#define len(s) s.size()


const int INF=1000000007;


using namespace std;

        int n,ans=0,p[300005];
        pair<int,int> a[300005],d[300005];
        vector<int> ansv;     

int main()
{
	ios_base::sync_with_stdio(false);
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].f;
		a[i].s=i;
		d[i].f=INF;
	}
	d[0].f=-INF;
	d[0].s=-1;
	for(int i=1;i<=n;i++)
	{                                     
		
		int j=int (upper_bound (d, d+n, a[i]) - d);
		if(d[j-1].f<a[i].f && d[j].f>a[i].f)
		{
			p[a[i].s]=d[j-1].s; 
			d[j]=a[i];
			ans=max(ans,j);
		}
		
	}
	int i=d[ans].s;
	ansv.pb(d[ans].f);
	while(p[i]!=-1)
	{
		ansv.pb(a[p[i]].f); 
		i=p[i];
	}
	cout<<ansv.size()<<endl;
	for(int i=ansv.size()-1;i>=0;i--)
	{
		cout<<ansv[i]<<' ';
	}      
	return 0;
}


