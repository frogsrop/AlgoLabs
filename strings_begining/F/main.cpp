#include<bits/stdc++.h>

using namespace std;

vector<int> prefix_function (vector<int> s) {
	int n = (int) s.size();
	vector<int> pi (n);
	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])  
			j++;
		pi[i] = j;
	}
	return pi;
}

int main()
{
	int n;
	cin>>n;
	vector<int> v;
	v.resize(n);
	for(int i = 0; i < n; i++)
	{
	    cin >> v[i];
	}
	vector<int> pf = prefix_function(v);
	if ((v.size() - 1) % ((v.size() - 1) - pf[(v.size() - 1) - 1]) == 0) 
	{ 
	    cout << (v.size() - 1) - pf[(v.size() - 1) - 1]; 
		return 0;
	}
	cout<<v.size() - 1;
	return 0;
}