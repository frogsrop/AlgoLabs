#include<bits/stdc++.h>

using namespace std;

#define f first
#define s second

class que{
	public:
	int num;
    int size;
	pair<int*,int>* m;
	pair<int*,int> a[2];
	que()
	{
		num=0;
		size=0;
		m=&a[0];
		for(int i=0;i<2;i++)
		{
			a[i].f=new int[0];
			a[i].s=0;
		}    
	}
	void push(int x)
	{
		if(m->s==size)
		{
			a[(num+1)%2].f=new int[max(size*2,1)];					
			for(int i=0;i<size;i++)
			{
				*(a[(num+1)%2].f+i)=*(a[num].f+i);	
			}
			
		}		
	}
};
	
int main()
{
	return 0;
}