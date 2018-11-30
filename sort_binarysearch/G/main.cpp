#include<iostream>
#include<queue>
#include<set>

using namespace std;

unsigned int cur=0;
unsigned int a,b;
unsigned int nextrand24()
{
	cur=cur*a+b;
	return cur>>8;
}
unsigned int nextrand32()
{
	unsigned int a=nextrand24(),b=nextrand24();
	return (a<<8)^b;
}
unsigned int mas[100004][4];
queue<unsigned int> v[70001], w[70001];
set<unsigned int> s1,s2;
int main()
{
	freopen("buckets.in","r",stdin);
	freopen("buckets.out","w",stdout);
	int t;
	int n;
	cin>>t>>n>>a>>b;
	while(t>0)
	{ 
		for(int i=1;i<=n;i++)
		{
			mas[i][0]=nextrand32();
			mas[i][3]=mas[i][0]>>24;
			mas[i][2]=(mas[i][0]<<8)>>24;
			mas[i][1]=(mas[i][0]<<16)>>24;
			mas[i][0]=(mas[i][0]<<24)>>24;
		}
		/*
		for(int i=1;i<=n;i++)
		{
			cout<<(mas[i][3]<<24)+(mas[i][2]<<16)+(mas[i][1]<<8)+mas[i][0]<<' ';
		}
		cout<<endl;*/
		for(int i=1;i<=n;i++)
		{
			s1.insert(mas[i][0]);
			v[mas[i][0]].push(i);
		} 
		for(int i=1;i<4;i++)
		{
			while(s1.size())
			{
				if(v[(*s1.begin())].size()>0)
				{          
					while(v[(*s1.begin())].size())
					{
						w[mas[v[(*s1.begin())].front()][i]].push(v[(*s1.begin())].front());
						s2.insert(mas[v[(*s1.begin())].front()][i]);
						v[(*s1.begin())].pop();    
					}
				}
				s1.erase(s1.begin());
			}
			swap(s1,s2);
			swap(v,w);		
		}
	
		unsigned long long ans=0;
		int it=1;
		for(auto &z:s1)
		{
		
			if(v[z].size()>0)
			{
					//cout<<((mas[v[j][i]][1]<<16)+mas[v[j][i]][0])<<' ';
				while(!v[z].empty())
				{
					ans=ans+(0ull+(mas[v[z].front()][3]<<24)+(mas[v[z].front()][2]<<16)+(mas[v[z].front()][1]<<8)+mas[v[z].front()][0])*it;
					v[z].pop();
					it++;
				}
			}
		}
		s1.clear();
		s2.clear();
		cout<<ans<<endl;
		t--;
	}	
	return 0;
}