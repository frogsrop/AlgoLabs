#include<bits/stdc++.h>

using namespace std;

const unsigned int MAXN = (unsigned int) pow(2, 24);

unsigned int t[4 * (MAXN + 1)], t_sum[4 * (MAXN + 1)];

void update_sum(unsigned int add, unsigned int v, unsigned int tl, unsigned int tr, unsigned int l, unsigned int r) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
        t[v] += add;
        return;
    }
    unsigned int tm = (tl + tr) / 2;
    update_sum(add, v * 2, tl, tm, l, min(r, tm));
    update_sum(add, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    t_sum[v] = t[v * 2] * (tm - tl + 1) + t[v * 2 + 1] * (tr - tm) + t_sum[v * 2] + t_sum[v * 2 + 1];
}

unsigned int sum(unsigned int v, unsigned int tl, unsigned int tr, unsigned int l, unsigned int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t_sum[v] + t[v] * (r - l + 1);
    }
    unsigned int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r) + t[v] * (r - l + 1);
}

unsigned int a, b;
unsigned int m, q;
unsigned int cur = 0;

unsigned int nextRand() {
    cur = cur * a + b;
    return cur >> 8;
}

int main() {
    freopen("fastadd.in", "r", stdin);
    freopen("fastadd.out", "w", stdout);
    cin >> m >> q;
    cin >> a >> b;
    for (unsigned int i = 0; i < m; i++) {
        unsigned int l, r;
        unsigned int add = nextRand();
        l = nextRand();
        r = nextRand();
        if (l > r)
            swap(l, r);
        update_sum(add, 1, 1, MAXN, l, r);
    }
    unsigned int ans = 0;
    for (unsigned int i = 0; i < q; i++) {
        unsigned int l, r;
        l = nextRand();
        r = nextRand();
        if (l > r)
            swap(l, r);
        unsigned int x = sum(1, 1, MAXN, l, r);
        ans += x;
    }
    cout << ans;
    return 0;
}


