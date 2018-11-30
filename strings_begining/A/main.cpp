#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	string t;
	cin>>s>>t;
	vector<int> v;
	for(size_t i = 0; i < t.size(); i++) 
	{
		if(t.substr(i, s.size()) == s)
		{
			v.push_back(i);		
		}		
	}
	cout << v.size() << endl;
	for(auto &it: v)
	{
		cout << it + 1 << ' ';
	}
	return 0;
}