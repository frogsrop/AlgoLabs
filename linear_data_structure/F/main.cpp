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
	int pop()
	{
		if(size>0)
		{
			int ans=(top->value);
			st* pr=top->prev;
			if(this!=top)
				free(top);
			top=pr;
			size--;
			return ans;
		}
		else
		{
			return 0;
			cout<<"stack is empty";
		}
	}

};

int parser(string s)
{
	int ans=0;
	for(int i=0;s.size()-i>0;i++)
	{
		ans=ans*10+s[i]-'0';
	}
	return ans;
}
int main()
{
	freopen("postfix.in","r",stdin);
	freopen("postfix.out","w",stdout);
	string s;
	st sk;
	while(cin>>s)
	{
		if(s=="+")
		{
			int x=sk.pop();
			int y=sk.pop();
			x+=y;
			sk.push(x);	
		}else
		if(s=="*")
		{
			int x=sk.pop();
			int y=sk.pop();
			x*=y;
			sk.push(x);	
		}else
		if(s=="-")
		{
			int x=sk.pop();
			int y=sk.pop();
			y-=x;
			sk.push(y);	
		}else
		{
			sk.push(parser(s));
		}
	}
	cout<<sk.pop();     	
	return 0;
}