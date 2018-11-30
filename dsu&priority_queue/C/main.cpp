#include<bits/stdc++.h>       

#define f first
#define s second

using namespace std;

class pqueue
{
	public:
	vector<pair<int,int> > v;
	pqueue()
	{
		v.push_back(make_pair(0,0));
	}
	void push(int x,int y)
	{
		v.push_back(make_pair(x,y));
		sift_up((int)v.size()-1);
	}	
	void sift_down(int u)
	{
		if((u*2<(int)v.size() && v[u].f>v[u*2].f) || (u*2+1<(int)v.size() && v[u].f>v[u*2+1].f))
		{
			if(u*2+1<(int)v.size() && v[u*2].f>v[u*2+1].f)
			{
				swap(v[u],v[u*2+1]);
				sift_down(u*2+1);
			}
			else
			{
				swap(v[u],v[u*2]);
				sift_down(u*2);	
			}
		}
		return;
	}
	void sift_up(int u)
	{
		if(u!=1)
		{
			if(v[u/2].f>v[u].f)
			{
				swap(v[u/2],v[u]);
				sift_up(u/2);
			}
		}    
		return;
	}
	int extract_min()
	{
		if(v.size()==1)
		{
			return 1000000007;
		}
		int ans;
		ans=v[1].f;
		swap(v[1],v[v.size()-1]);
		v.erase(v.end()-1);
		sift_down(1);
		return ans;
	} 
	void dec_key(int x,int y)
	{
		int n=0;
		for(int i=0;i<(int)v.size();i++)
		{
			if(v[i].s==x)
			{
				n=i;
				break;
			}
		}
		v[n].f=y;
		sift_up(n);
	}
}; 

int main()
{
	freopen("priorityqueue.in","r",stdin);
	freopen("priorityqueue.out","w",stdout);
	string s;
	pqueue q;
	int i=1;
	while(cin>>s)
	{
		if(s=="push")
		{
			int buf;
			cin>>buf;
			q.push(buf,i);
		}
		if(s=="extract-min")
		{
			int ans=q.extract_min();
			if(ans!=1000000007)
				cout<<ans<<endl;
		   	else
		   		cout<<"*"<<endl;
		}
		if(s=="decrease-key")
		{
			int x,y;
			cin>>x>>y;
			q.dec_key(x,y);
		}
		i++;  /*
		for(auto &t:q.v){
			cout<<t.f;
		}         
		cout<<endl;*/
	}
	return 0;
}