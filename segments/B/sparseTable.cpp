#include<bits/stdc++.h>

using namespace std;

int table[100001][25];

int pow2[25];

void preCalc() {
    int cur = 1;
    for (int i = 0; i < 25; i++) {
        pow2[i] = cur;
        cur <<= 1;
    }
}

int get(int l, int r) {
    int len = r - l + 1;
    int curPow = 0;
    while (pow2[curPow + 1] <= len) {
        curPow++;
    }
    return min(table[l][curPow], table[r - pow2[curPow] + 1][curPow]);
}

int main() {
    freopen("sparse.in", "r", stdin);
    freopen("sparse.out", "w", stdout);

    int n, m;
    cin >> n >> m >> table[1][0];
    preCalc();
    for (int i = 2; i <= n; i++) {
        table[i][0] = (23 * table[i - 1][0] + 21563) % 16714589;
    }
    for (int j = 1; j < 25; j++) {
        for (int i = 1; i <= n; i++) {
            table[i][j] = min(table[i][j - 1], table[min(i + pow2[j - 1], n)][j - 1]);
        }
    }
    int u, v;
    int ans = 0;
    cin >> u >> v;
    ans = get(min(u, v), max(u, v));
    for (int i = 1; i < m; i++) {
        u = ((17 * u + 751 + ans + 2 * i) % n) + 1;
        v = ((13 * v + 593 + ans + 5 * i) % n) + 1;
        ans = get(min(u, v), max(u, v));
    }
    cout << u << ' ' << v << ' ' << ans;
    return 0;
}