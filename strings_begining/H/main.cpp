#include<bits/stdc++.h>

using namespace std;

long long h[1000000];
long long h_[1000000];
vector<long long> pPow(1000000);
vector<long long> pPow1(1000000);

const long long M = 100000007;

long long norm_(long long x)
{
	if(x<0)
		x += M;
	else 
		x %= M;
	return x; 
}	

long long get_hash(int from, int to)
{
	long long ans = h[to];
	if(from)
	{
		ans -= h[from - 1];
	}
	return norm_(ans);	
}

long long get_hash_(int from, int to)
{
	long long ans = h_[to];
	if(from)
	{
		ans -= h_[from - 1];
	}
	return ans;	
}

int main()
{
	//freopen("in","r",stdin);
	string t;
	cin >> t;
	
	const long long p = 43;
	const long long p1 = 31;
	
	pPow[0] = 1;
	pPow1[0] = 1;
	
	for(size_t i = 1; i < pPow.size(); i++)
	{
		pPow[i] = (pPow[i - 1] * p);
		pPow[i] = norm_(pPow[i]);
		pPow1[i] = (pPow1[i - 1] * p1);	
	}                    

	for(size_t i=0; i < t.size(); i++)
	{
		h[i] = ((t[i] - 'a' + 1) * pPow[i]);
		
		h_[i] = ((t[i] - 'a' + 1) * pPow1[i]);
		
		if(i) 
		{
			h[i] += h[i - 1];
			h_[i] += h_[i - 1];
		}
		h[i] = norm_(h[i]);
	}
	
	int x;
	cin>>x;
	for(int i = 0; i < x; i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(c < a)
		{
			swap(a,c);
			swap(b,d);
		}
		if(norm_(get_hash(a - 1, b - 1) * pPow[c]) == norm_(get_hash(c - 1, d - 1) * pPow[a]) &&  get_hash_(a - 1,b - 1) * pPow1[c] == get_hash_(c - 1,d - 1)  * pPow1[a] && b-a == d-c)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}