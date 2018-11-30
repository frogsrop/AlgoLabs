#include<bits/stdc++.h>

using namespace std;

vector<int> g[100001];
vector<int> depth;
vector<int> ver;  
int used[100001];
int pos[100001];

void dfs(int v = 0, int d = 0)
{
	used[v] = 1;
	depth.push_back(d);
	pos[v] = ver.size();
	ver.push_back(v);
	for(size_t i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		if(used[u]==0)
		{
			dfs(u,d+1);
			depth.push_back(d);
			ver.push_back(v);
		}
	}
}

int n,m;

int main() {
	ios_base::sync_with_stdio(0);
    freopen("lca_rmq.in", "r", stdin);
    freopen("lca_rmq.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i < n; i++)
    {
    	int buf;
    	cin>>buf;
    	g[buf].push_back(i);
    	//cout<<buf<<"->"<<i<<endl;
    }
    dfs();             
    /*
    for(int i = 0; i < ver.size(); i++)
    {
    	cout<<ver[i]<<' ';
    }
    cout<<endl;
    for(int i = 0; i < ver.size(); i++)
    {
    	cout<<depth[i]<<' ';
    }              
    */
    /*
    for(int i = 0; i < m; i++)
    {
    	int x,y;
    	cin>>x>>y;
    	int ans = pos[x];
    	for(int j = pos[x];j<=pos[y];j++)
    	{
    		if(depth[j]<depth[ans])
    			ans = j;
    	}
    	cout<<endl;
    	cout<<ver[ans]<<'!';
    }                
    */
    int a1,a2,x,y,z;
    long long sum = 0;
    int ans = 0;
    cin>>a1>>a2>>x>>y>>z;
    for(int i = 0; i < m; i++)
    {
		int l = pos[(a1+ans)%n], r = pos[a2];
		if(l > r)
			swap(l, r);
    	ans = l;
    	for(int j = l;j<=r;j++)
    	{
    		if(depth[j]<depth[ans])
    			ans = j;
    	}
    	ans = ver[ans];
    	sum += ans*1ll;
    	//cout<<ans<<endl;
    	int na1,na2;
    	na1 = (x * a1 + y * a2 + z) % n;
    	na2 = (x * a2 + y * na1 + z) % n;
    	a1=na1;
    	a2=na2;
    }
    cout<<sum;      
    return 0;
}
 
