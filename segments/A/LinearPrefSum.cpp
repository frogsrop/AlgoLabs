#include<bits/stdc++.h>

using namespace std;

const unsigned int MAXN = (unsigned int) pow(2, 24);

unsigned int querysAdd[MAXN + 5];
unsigned int querysDif[MAXN + 5];

unsigned int prefSum[MAXN + 5];

void add_query(unsigned int add, unsigned int l, unsigned int r) {
    querysAdd[l] += add;
    querysDif[r] += add;
}

void calc() {
    unsigned int cur = 0;
    for (unsigned int i = 0; i <= MAXN; i++) {
        cur += querysAdd[i];
        if (i >= 1)
            prefSum[i] = prefSum[i - 1] + cur;
        else
            prefSum[i] = cur;
        cur -= querysDif[i];
    }
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
        add_query(add, l, r);
    }
    calc();
    unsigned int ans = 0;
    for (unsigned int i = 0; i < q; i++) {
        unsigned int l, r;
        l = nextRand();
        r = nextRand();
        if (l > r)
            swap(l, r);
        if (l >= 1)
            ans += prefSum[r] - prefSum[l - 1];
        else
            ans += prefSum[r];
    }
    cout << ans;
    return 0;
}


