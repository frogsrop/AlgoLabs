#include<bits/stdc++.h>

using namespace std;

const int inf=100;

class st{
public:
	st* prev;
	st* top;
	int mn;
	int value;
	int size;
	st(){
		size=0;
		top=this;
		prev=this;
		value=inf;
		mn=inf;
	}
	void push(int x)
	{                
		
		if(size==0)
		{
		    size=1;
			value=x;
			mn=x;
			top=this;
			prev=this;   
			
		}
		else           
		{             
			st* n=new st;
			n->prev=top;
			top=n;
			top->mn=min((top->prev)->mn,x);
			top->value=x;
			size++;	
		}
	}
	int get_min()
	{
	    if(size>0)
	    {
			return (top->mn);
		}
		else
		{
			cout<<"stack is empty"<<endl;
			return 0;
		}
	}
	int pop()
	{             	
		int ans=0;
		if(size>0)
		{
			ans=(top->value);
			st* pr=top->prev;
			if(this!=top)
				free(top);
			top=pr;
			size--;
		}
		else
		{
			cout<<"stack is empty"<<endl;
		}    
		return ans;
	}

};

class qu{
public:
	st s1,s2;
	int get_min()
	{
		if(s1.size==0 && s2.size==0)
		{
			cout<<"queue is empty"<<endl;
			return -1;
		}
		if(s1.size==0)
		{
			return s2.get_min();
		}
		if(s2.size==0)
		{
			return s1.get_min();
		}
		return min(s2.get_min(),s1.get_min());

	}
	void push(int x)
	{
		s1.push(x);
	}
	int pop()
	{
		int ans=0;
		if(s2.size>0)
		{        
			ans=s2.pop();
		}
		else
		{
			while(s1.size>0)
			{
				int w=s1.pop();
				s2.push(w);
			}
			if(s2.size>0)
			{	
				ans= s2.pop();
		   	}
		   	else
		   	{
		   		cout<<"queue is empty"<<endl;
		   		return -1;
		   	}
		}
		return ans;
	}

};

int main()
{
	freopen("queue2.in","r",stdin);
	freopen("queue2.out","w",stdout);
	qu s;
	int n;
	scanf("%d \n",&n);
	for(int i=0;i<n;i++)
	{
		char c;
		scanf("%c \n",&c);
		if(c=='+')
		{
			int a;
			scanf("%d \n",&a);
			s.push(a);
		}
		if(c=='-')
		{
			printf("%d\n",(s.pop()));
		}
	}	return 0;
}