#include<bits/stdc++.h>

using namespace std;

vector<int> prefix_function (string s) {
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
	string s;
	string t;
	cin >> s;
	cin >> t;
	t = s + "#" + t;
	//cout<<t<<endl;
	vector<int> pf = prefix_function(t);
	vector<size_t> ans;
	for(size_t i = s.size() + 1; i < pf.size(); i++)
	{
		//cout<<pf[i];
		if(pf[i] == (int)s.size())
		{
			ans.push_back(i - s.size() + 1 - s.size() );
		}
	}
	cout<<ans.size()<<endl;
	for(auto &t:ans)
	{
		cout<<t<<' ';
	}
	return 0;
}