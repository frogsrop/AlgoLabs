#include <bits/stdc++.h>

#define ll long long
#define f first
#define s second
#define pb push_back 
using namespace std;
 
class pqueue
{
	public:
	vector<pair<int,int> > v;
	pqueue()
	{
		v.pb(make_pair(0,0));
	}
	
	void push(int x,int y)
	{
		v.push_back(make_pair(x,y));
		sift_up((int)v.size()-1);
	}	
	
	void sift_down(int u)
	{
		if((u*2<(int)v.size() && v[u].f>v[u*2].f) || (u*2+1<(int)v.size() && v[u].f>v[u*2+1].f))
		{
			if(u*2+1<(int)v.size() && v[u*2].f>v[u*2+1].f)
			{
				swap(v[u],v[u*2+1]);
				sift_down(u*2+1);
			}
			else
			{
				swap(v[u],v[u*2]);
				sift_down(u*2);	
			}
		}
		return;
	}
	void sift_up(int u)
	{
		if(u!=1)
		{   
			if(v[u/2].f>v[u].f)
			{
				swap(v[u/2],v[u]);
				sift_up(u/2);
			}
		}    
		return;
	}
	int mn()
	{
		if(v.size()==1)
		{
			return int(-pow(2,31));
		}
		return v[1].f; 
	}
    int extract_min()
	{
		if(v.size()==1)
		{
			return int(-pow(2,31));
		}
		int ans;
		ans=v[1].f;
		swap(v[1],v[v.size()-1]);
		v.erase(v.end()-1);
		sift_down(1);
		return ans;
	} 
	void dec_key(int x,int y)
	{
		int n=0;
		for(int i=0;i<(int)v.size();i++)
		{
			if(v[i].s==x)
			{
				n=i;
				break;
			}
		}
		v[n].f=y;
		sift_up(n);
		sift_down(n);
	}       
}; 

int main()
{
	freopen("rmq.in","r",stdin);
	freopen("rmq.out","w",stdout);
	ios_base::sync_with_stdio(false);
	pqueue q;
 	int BIG=int(-pow(2,31));                                            
 	vector<pair<int, pair<int, int> > > v;    
	int n, m;
	cin>>n>>m;
    int ans[300001];
    for(int i=0;i<n;i++) 
    {
    	ans[i]=BIG;
    }
    for (int i=1; i<=m; i++)
    {
        int x,y,d; 
        cin>>x>>y>>d; 
        x--; 
        y--;
        v.pb(make_pair(x, make_pair(-i, d)));
        v.pb(make_pair(y, make_pair(i, d)));
    }           	
    sort(v.begin(), v.end());
    int j=0;
    for(int i=0; i<(int)v.size(); i++)
    {
        int b=v[i].f;
        int num=v[i].s.f;
        int val=v[i].s.s;
        while(j<b)
        {
            if(ans[j]==BIG)
            {
				ans[j] = -q.mn();
            }
            j++;
        }
        if(num>=0)
        {
			if(ans[b]==BIG) 
            	ans[b]=-q.mn();
            q.dec_key(num, BIG);
            q.extract_min();
        } 
        else 
        {    	
            q.push(-val, -num);
		}
    }
    for (int i=0; i<n; i++) {
        ans[i]=max(ans[i], BIG);
        ans[i]=min(ans[i], BIG-1);
        cout<<ans[i]<<" ";
    }
    return 0;
}