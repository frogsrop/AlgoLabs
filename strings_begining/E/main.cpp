#include<bits/stdc++.h>

using namespace std;

vector<int> z_function (string s) {
	int n = (int) s.size();
	vector<int> z (n);
	int l = 0;
	int r = 0;
	for(int i = 1; i < n; i++) 
	{
		if(i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;
		if (i + z[i] - 1 > r)
		{
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

int main()
{
	freopen("search3.in", "r", stdin);
	freopen("search3.out", "w", stdout);
	
	string s;           
	string t;
	cin >> s;
	cin >> t;
	if(s.size()>t.size())
	{
		cout << 0;
		return 0;
	}

	string s1 = s + "#" + t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	string s2 = s + "#" + t;
	
	vector<int> zf1 = z_function(s1);
	vector<int> zf2 = z_function(s2);
	/* 
	for(int i = s.size() + 1; i < (int)zf1.size(); i++)
	{
		cout<<zf1[i]<<' ';
	}
	cout<<endl;
	for(int i = s.size() + 1; i < (int)zf2.size(); i++)
	{
		cout<<zf2[i]<<' ';
	}
	cout<<endl;
	*/ 
	vector<int> v;

	for(size_t i = 0; i < t.size() - s.size() + 1; i++)
	{             
		//cout<< zf2[zf2.size() - s.size() - i] + zf1[s.size() + 1 + i]<<' ';
		//cout<<zf1.size()<<' '; 
		//cout<<s.size() + 1 + i<<' ';
		//cout<<zf2.size() - s.size() - i<<endl;
		if(zf2[zf2.size() - s.size() - i] + zf1[s.size() + 1 + i]>= (int)s.size() - 1)
		{
			v.push_back((int)i + 1);
		}
	}
	//cout<<endl;
	cout<<v.size()<<endl;

	for(auto &t:v)
	{
		cout<<t<<' ';
	}
	return 0;
}