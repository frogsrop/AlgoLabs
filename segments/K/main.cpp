#include<bits/stdc++.h>

using namespace std;

const int MAXN = 500000;
vector<int> g[MAXN];
int n;
unordered_set<int> q[MAXN];
int dsu[MAXN], ancestor[MAXN], h[MAXN];
bool used[MAXN];
vector<pair<int, int> > ans;
map<pair<int, int>, int> ansvers;

int dsu_get(int v) {
    if (v == dsu[v])
        return v;
    return dsu[v] = dsu_get(dsu[v]);
}

void dsu_unite(int a, int b, int new_ancestor) {
    a = dsu_get(a);
    b = dsu_get(b);
    if (h[a] > h[b])
        swap(a, b);
    dsu[a] = b;
    ancestor[b] = new_ancestor;
    if (h[a] == h[b])
        h[b]++;
}

void dfs(int v) {
    dsu[v] = v, ancestor[v] = v;
    used[v] = 1;
    for (size_t i = 0; i < g[v].size(); ++i) {
        if (!used[g[v][i]]) {
            dfs(g[v][i]);
            dsu_unite(v, g[v][i], v);
        }
    }
    auto it = q[v].begin();
    for (size_t i = 0; i < q[v].size(); ++i) {
        int cur = * (it++);
        if (used[cur]) {
            ansvers[make_pair(v + 1, cur + 1)] = ancestor[dsu_get(cur)] + 1;
            ansvers[make_pair(cur + 1, v + 1)] = ancestor[dsu_get(cur)] + 1;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
    freopen("lca.in", "r", stdin);
    freopen("lca.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int x, y;
        cin >> s;
        cin >> x >> y;
        x--;
        y--;
        if (s == "ADD") {
            g[x].push_back(y);
        } else {
            ans.push_back(make_pair(x + 1, y + 1));
            q[x].insert(y);
            q[y].insert(x);
        }
    }
    dfs(0);
    for (size_t i = 0; i < ans.size(); i++) {
        cout << ansvers[ans[i]] << endl;
    }
    return 0;
}
 
