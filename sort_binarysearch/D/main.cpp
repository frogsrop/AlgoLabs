#include<bits/stdc++.h>

using namespace std;


int main()
{
	freopen("garland.in","r",stdin);
	freopen("garland.out","w",stdout);
	int n;
	double x,r;
	cin>>n>>x;
	double l=0;
	r=10000000;
	double mxdst=1;
	double ans=10000000.0f;
	while(mxdst>0.0000001f)
	{
		double mid=(l+r)/2.0f;
		double f=x;
		double s=mid;
		bool b=0;
		mxdst=min(x,mid);
		double w;
		for(int i=0;i<n-2;i++)
		{
			w=2.0*(s+1)-f;
			mxdst=min(mxdst,w);
			if(w<=0)
			{
				b=1;
				mxdst=100;
				break;
			}
			f=s;
			s=w;
			
		}
		if(b==1)
		{
			l=mid;
		}	
		else
		{
			ans=min(ans,s);
			r=mid;
		}
	}
	printf("%.2f",ans);
	return 0;
}