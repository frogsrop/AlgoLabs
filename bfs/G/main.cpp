#include<bits/stdc++.h>

#define pb push_back
#define f first
#define s second

using namespace std;


double w(int x,int y,int x1,int y1)
{
	return sqrt((x-x1) * (x-x1) + (y-y1) * (y-y1));
} 
const int N = 5005;
const double INF = 9000000000;

set<pair<double,int>> q;

int m;
vector<pair<int,int> > p;
double ans;

int main()
{         
//	freopen("in","r",stdin);
	
	ios_base::sync_with_stdio(0);
    
    cin>>m;
    
    p.resize(m);

    for(int i = 0;i<m;i++)
    {
    	int l, r;
    	cin>>l>>r;
    	p[i]=make_pair(l, r);
    }
    vector<bool> used (m);
	vector<double> min_e (m, INF);
	vector<int> sel_e (m, -1);
	min_e[0] = 0;
	for (int i=0; i<m; ++i) {
		int v = -1;
		for (int j=0; j<m; ++j)
			if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
				v = j;
		if (min_e[v] == INF) {
			cout << 0<<'!';
			return 0;
		}
        
        if (sel_e[v] != -1)
			ans+=w(p[v].first,p[v].second,p[sel_e[v]].first,p[sel_e[v]].second);
		
		used[v] = true;
		for (int to=0; to<m; ++to)
			if (w(p[v].first,p[v].second,p[to].first,p[to].second) < min_e[to]) {
				min_e[to] = w(p[v].first,p[v].second,p[to].first,p[to].second);
				sel_e[to] = v;
		}
	}
	//for(int t =0; t<m;t++)
	//	ans += min_e[t];
    cout <<setprecision(10) << fixed;
    cout << ans << endl;
	return 0;
}