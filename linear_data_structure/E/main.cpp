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

bool check(string s)
{
	st sk;
	for(int i=0;s.size()-i;i++)
	{
		if(s[i]=='[')
		{
			sk.push(1);
		}
		if(s[i]=='(')
		{
			sk.push(2);
		}
		if(s[i]==']')
		{
			if(!(sk.size && sk.pop()==1))
			{
				return 0;
			}
		}
		if(s[i]==')')
		{
			if(!(sk.size && sk.pop()==2))
			{
				return 0;
			}
		}
	}
	if(sk.size==0)
		return 1;
	else
		return 0;
}

int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	string s;
	while(cin>>s){
		cout<<(check(s)?"YES":"NO")<<endl;
	}
	     	
	return 0;
}