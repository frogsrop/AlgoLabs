#include<bits/stdc++.h>

using namespace std;


const unsigned int MAXN = (unsigned int)pow(2,17);
vector<unsigned int> t[(MAXN+1)*4];
           
unsigned int f[MAXN];
void build(unsigned int v,unsigned int tl,unsigned int tr){
	if(tl == tr){
		t[v].push_back(f[tl]);
	    return;
	}
	unsigned int tm = (tl + tr)/2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	t[v].resize(t[v*2].size()+t[v*2+1].size());
	merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(), t[v].begin());
}

unsigned int amount (unsigned int x,unsigned int y,unsigned int v,unsigned int tl,unsigned int tr,unsigned int l,unsigned int r)
{
	if(l > r) {
		return 0;
	}
	if(tl==l && tr==r)
	{
		unsigned int ans = abs(lower_bound(t[v].begin(),t[v].end(), x) - upper_bound(t[v].begin(),t[v].end(), y));
		return ans;
	}
	unsigned int tm = (tr+tl)/2;
	unsigned int ansl = amount(x,y,v*2,tl,tm,l,min(tm,r));
	unsigned int ansr = amount(x,y,v*2+1,tm+1,tr,max(tm+1,l),r);
	return ansl+ansr;
}	

unsigned int a, b; 
unsigned int cur = 0; 
unsigned int nextRand17() {
	cur = cur * a + b; 
	return cur >> 15; 
}
unsigned int nextRand24() {
	cur = cur * a + b; 
	return cur >> 8; 
}


int main(){
	freopen("find2d.in","r",stdin);
	freopen("find2d.out","w",stdout);
	unsigned int q,l,r,x,y,c;
	unsigned int sum=0;
	cin>>q;
	cin>>a>>b;
	for (unsigned int i = 0; i < MAXN; i++)
	{
		f[i] = nextRand24();
	}
	build(1,0,MAXN-1);
	for(unsigned int i = 0; i < q; i++)
	{
		l = nextRand17();
		r = nextRand17();
		if (l > r) swap(l, r); 
		x = nextRand24();
		y = nextRand24();	
		if (x > y) swap(x, y);
		c = amount(x,y,1,0,MAXN-1,l,r); 	
		sum+=c;
		b += c; 
	}
	cout<<sum;
	return 0;
}