#include<bits/stdc++.h>

using namespace std;

long long h[1000000];
long long h_[1000000];
vector<long long> pPow(1000000);
	
int main()
{
	string s;
	string t;
	cin >> s;
	cin >> t;
	
	const long long p = 23;
	
	pPow[0] = 1;
	
	for(size_t i = 1; i < pPow.size(); i++)
	{
		pPow[i] = (pPow[i - 1] * p);
	}                    

	for(size_t i=0; i < t.size(); i++)
	{
		h[i] = ((t[i] - 'a' + 1) * pPow[i]);
		h_[i] = ((t[i] - 'a' + 1) * pPow[i]);
		
		if(i) 
		{
			h[i] += h[i - 1];
			h_[i] += h_[i - 1];
		}

		h[i] %=10000007;
	}
	long long h_s = 0;
	long long h_s_ = 0;
	for(size_t i = 0; i < s.size(); i++)
	{
		h_s += ((s[i] - 'a' + 1) * pPow[i]);
		h_s %= 10000007;
		h_s_ += ((s[i] - 'a' + 1) * pPow[i]);
	}
	vector<size_t> v;
	for (size_t i = 0; i + s.size() - 1 < t.size(); i++)
	{
		long long cur_h = h[i + s.size()-1];
	    long long cur_h_ = h_[i + s.size()-1];
	
		if(i) 
		{
			cur_h -= h[i-1];
			cur_h_ -= h_[i-1];
		}

	    cur_h %=10000007;
		
		if (cur_h == (h_s * pPow[i]) % 10000007 && cur_h_ == h_s_ * pPow[i] )
		{
			v.push_back(i);
		}
	}
	
	cout << v.size() << endl;
	for(auto &t: v)
	{
		cout<<t + 1<<' ';
	}

	return 0;
}