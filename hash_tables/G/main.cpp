#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> g[100005];
int par[100005];
int n;
bool used[100005];

int mid;

void gen_par(int v, int p)
{
    used[v] = 1;
    par[v] = p;
    for(int i = 0;i<(int) g[v].size(); i++)
    {
        int u = g[v][i];
        if(used[u]==0)
        {
            gen_par(u,v);
        }
    }
}

pair<int,int> farest(int v)
{
    bool used[100005];
    int dist[100005];
    for(int i = 0; i < n; i++)
    {
        used[i] = 0;
        dist[i] = -1;     
	}
    used[v] = 1;
    dist[v] = 0;
    int vx = 0;
    int mx = 0;
    queue<int> q;
    q.push(v);
    while(q.size())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < (int)g[cur].size(); i++)
        {
            int u = g[cur][i];
            if(used[u])
            	continue;
             used[u] = 1;
             dist[u] = dist[cur] + 1;
             if(dist[u] > mx)
             {
             	mx = dist[u];
             	vx = u;
             }
             q.push(u);
        }
    }
    return make_pair(vx, mx);
}

bool flag;
ll dfs(int v, bool Isroot)
{
    used[v] = 1;
    vector<ll> ch;
    ll hash_sum1 = 1;
    ll hash_sum2 = 0;
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int u = g[v][i];
        if (used[u]==0)
        {
            ch.push_back(dfs(u, 0));
            hash_sum1 *= ch.back();
            hash_sum2 += ch.back();
        }
    }
    if(Isroot)
    {
    	if(ch[0] == ch[1])
        {	
        	flag = 1;
        }
        else
        {	
        	flag = 0;
        }
    }
    return hash_sum1 + hash_sum2;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int temp = farest(0).first;
    pair<int,int> thefarest = farest(temp);
    gen_par(temp, temp);
    mid = thefarest.first;
    for (int i=0;i < thefarest.second / 2; i++)
    {
        mid = par[mid];
    }
    if (thefarest.second % 2 == 1 || g[mid].size() != 2)
    {
        cout<<"NO";
        return 0;
    }
    for(int i = 0; i < n; i++)
        used[i] = 0;
    dfs(mid, 1);
    if(flag == 1)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
	}
	return 0;                                   
}

