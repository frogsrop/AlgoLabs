#include<bits/stdc++.h>

using namespace std;

int main()
{
	ifstream cin("isheap.in");
	ofstream cout("isheap.out");
	int n;
	cin>>n;
	int a[100005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int i=1;
	while(i*2+1<=n)
	{
		if(a[i]>a[i*2] || a[i]>a[i*2+1])
		{
			cout<<"NO";
			return 0;
		}
		i++;
	}
	if(i*2<=n)
	{
		if(a[i]>a[i*2])
		{
			cout<<"NO";
			return 0;
		}
		
	}
	cout<<"YES";
	return 0;
}