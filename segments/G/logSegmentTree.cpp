#include<bits/stdc++.h>

using namespace std;

const long long MAXN = (long long) pow(2, 24);

long long t[4 * (MAXN + 1)], t_min[4 * (MAXN + 1)];
long long f[MAXN+1];
void update_min(long long add, unsigned int v, unsigned int tl, unsigned int tr, unsigned int l, unsigned int r) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
        t[v] += add;
        t_min[v] += add;
        return;
    }
    unsigned int tm = (tl + tr) / 2;
    update_min(add, v * 2, tl, tm, l, min(r, tm));
    update_min(add, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    t_min[v] = min(t_min[v * 2], t_min[v * 2 + 1]);
}

long long min_(unsigned int v, unsigned int tl, unsigned int tr, unsigned int l, unsigned int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t_min[v];
    }
    unsigned int tm = (tl + tr) / 2;
    return min(min_(v * 2, tl, tm, l, min(r, tm)), min_(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void build(int v,int l,int r)
{
	if(l==r)
	{
		t_min[v] = f[l];
		return;
	}
	int m = (l+r)/2;
	build(v*2,l,m);
	build(v*2+1,m+1,r);
	t_min[v] = min(t_min[v*2],t_min[v*2+1]);
}

int main() {
    freopen("rmq2.in", "r", stdin);
//	freopen("rmq2.out", "w", stdout);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
    	cin>>f[i];
    }
    build(1,1,n);

    return 0;
}


