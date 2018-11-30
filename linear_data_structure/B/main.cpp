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
			top->mn=min(top->prev->mn,x);
			top->value=x;
			size++;	
		}
	}
	void print_min()
	{
	    if(size>0)
	    {
			cout<<"min is "<<(top->mn)<<endl;
		}
		else
		{
			cout<<"stack is empty";
		}
	}
	void pop()
	{
		if(size>0)
		{
			printf("%d\n",(top->value));
			st* pr=top->prev;
			if(this!=top)
				free(top);
			top=pr;
			size--;
		}
		else
		{
			cout<<"stack is empty";
		}
	}

};

int main()
{
	freopen("stack2.in","r",stdin);
	freopen("stack2.out","w",stdout);
	st s;
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
			s.pop();
		}
	}        	
	return 0;
}