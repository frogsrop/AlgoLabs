#include<bits/stdc++.h>

#define f first
#define s second
#define pb push_back

using namespace std;


class dsu
{
    public:
	
	int* parent;
	int* rank;
	int *mx,*mn;
	dsu(int n)
	{
		parent = new int[n];
		rank = new int[n];
		mx=new int[n];
		mn=new int[n];
		for(int i=0;i<n;i++)
		{
			parent[i]=i;
			rank[i]=0;
			mx[i]=mn[i]=i;
		}
	}

	int get(int x)
	{
		if(parent[x]==x)
		{
				return x;
		}
		else
		{
			int root=get(parent[x]);
			parent[x]=root;
			return 	root;
		}
	}  	
   	
	void union_(int x, int y) {
		x = get(x);
		y = get(y);
		if (x != y) {
			if(rank[x]>rank[y])
			{
				swap(x,y);
			}
			parent[x] = y;
			mx[y]=max(mx[y],mx[x]);
			mn[y]=min(mn[y],mn[x]);
			if(rank[x]==rank[y])
			{
				rank[y]++;
			}
		}
	}  	
};
int main()
{
	freopen("cutting.in","r",stdin);
    freopen("cutting.out","w",stdout);
    int n;
    int m;
    int k;
	cin>>n;
	cin>>m;
	cin>>k;
	vector<pair<string, pair<int,int> > >  v;
	for(int i=0;i<m;i++)
	{
		int l,r;
		cin>>l>>r;	
	}
	for(int i=0;i<k;i++)
	{
		string s;
		cin>>s;
		int l,r;
		cin>>l>>r;
		v.pb(make_pair(s,make_pair(l-1,r-1)));
	}
	dsu d(n);
	vector<string> s;
	for(int i=k-1;i>=0;i--)
	{
		if(v[i].f=="ask")
		{
			if(d.get(v[i].s.f)==d.get(v[i].s.s))
			{
				s.pb("YES");
			}       
			else
			{
				s.pb("NO");
			}
		}
		if(v[i].f=="cut")
		{
			d.union_(v[i].s.f,v[i].s.s);
		}
	}                           
	for(int i=s.size()-1;i>=0;i--)
	{
		cout<<s[i]<<endl;         
	}                           
	return 0;
}
