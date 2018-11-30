#include<bits/stdc++.h>

using namespace std;

void sort_(int* a,int n)
{
	if(n>1)
	{
		int v = a[rand()%n];
     	int l = 0;
     	int r = n-1;
     	while(l<=r) 
     	{
        	while (a[l] < v) l++;
        	while (a[r] > v) r--;
       	 	if (l<=r)
       	 	{ 
          		swap(a[l], a[r]); 
          		l++;
          		r--;
          	}
		}
		/*
		cout<<"n="<<n<<' '<<v<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<' ';
		}
		cout<<endl;  */
		if(n>2)
		{
			sort_(a,l);
			sort_(a+l,n-l);
		}
	}		
}

int main()
{
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	int n;
	cin>>n;
	int x[300005];
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}	
	sort_(x,n);
	for(int i=0;i<n;i++)
	{
		cout<<x[i]<<' ';
	}	
	return 0;
}