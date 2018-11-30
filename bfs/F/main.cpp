#include<bits/stdc++.h>

#define f first;
#define s second;

using namespace std;

struct edge {
	int a, b;
	long long cost;
};
 
int n, m;
vector<edge> e;
const long long INF = 1000000000000;
 

int main()
{
	cin>>n;
	
	for(int i = 0; i < n; i++)
	{	
		for(int j = 0; j < n; j++)
		{
			long long x;
			cin >> x;
			edge eg;
			eg.a = i;
			eg.b = j;
			eg.cost = x;
			e.push_back(eg); 	
		}
	}
	m = e.size();
	vector<long long> d (n);
	vector<int> p (n, -1);
	int x = 0;
	for (int i=0; i < n; ++i) {
		x = -1;
		for (int j=0; j < m; ++j)
			if (d[e[j].b] > d[e[j].a] + e[j].cost) {
				d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
				p[e[j].b] = e[j].a;
				x = e[j].b;
			}
	}
 
	if (x == -1)
		cout << "NO";
	else {
		int y = x;
		for (int i=0; i < n; ++i)
			y = p[y];
 
		vector<int> path;
		for (int cur = y; ; cur = p[cur]) {
			path.push_back (cur);
			if (cur == y && path.size() > 1)  break;
		}
		reverse (path.begin(), path.end());
 
		cout << "YES" << endl;
		cout << path.size() << endl;
		for (size_t i=0; i  < path.size(); ++i)
			cout << path[i] + 1 << ' ';
	}
	return 0; 
}