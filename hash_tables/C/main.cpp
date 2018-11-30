#include<bits/stdc++.h>

using namespace std;

class ver 
{
	public:
		unsigned int val;
		string ans;
		ver *prev, *next;
		ver *l, *r;
		
		ver()
		{
			val = 0;
			prev = nullptr;
			next = nullptr;
			ans = "none";
			l = nullptr;
			r = nullptr;
		}
};

class tree {
	public:
		ver* v = nullptr;
		ver*& find(unsigned int x)
		{
			ver* cur = v;
			if(v == nullptr || v -> val == x)
			{
				return v;
			}
			else
			{
				while(1)
				{
					if(cur->val >= x)	
					{
						if(cur -> l == nullptr || cur -> l -> val == x)
						{
							return cur -> l;
						}	
						cur = cur->l;
					}
					if(cur->val < x)	
					{
						if(cur -> r == nullptr || cur -> r -> val == x)
						{
							return cur -> r;
						}	
						cur = cur->r;
					}
			
				}
			}
		}
	    unsigned int next(unsigned int x)
		{  
			unsigned int n;
			ver* cur = v;
			while(cur != nullptr && cur->val <= x)
				cur = cur->r;
			if(cur == nullptr)
				return x;
			n = cur->val;
			while(cur!=nullptr)
			{
				if(cur -> val > x)
				{
					if(cur -> l != nullptr)
					{
						if(cur -> l ->val > x && cur -> l ->val < n)
						{
							n=cur->l->val;
						}
					}	
					cur = cur->l;
				}
				else             
				if(cur -> val <= x)
				{
					if(cur -> r != nullptr)
					{
						if(cur -> r -> val > x && cur -> r -> val < n)
						{
							n = cur->r->val;
						}
					}	
					cur = cur->r;
				}
			}
			return n;
		}
		unsigned int prev(unsigned int x)
		{  
			unsigned int n;
			ver* cur = v;
			while(cur != nullptr && cur->val >= x)
				cur = cur->l;
			if(cur == nullptr)
				return x;
			n = cur->val;
			while(cur!=nullptr)
			{                  	
				if(cur -> val < x)
				{
					if(cur -> r != nullptr)
					{
						if(cur -> r -> val < x && cur -> r ->val > n)
						{
							n=cur->r->val;
						}
					}	
					cur = cur->r;
				}
				else             
				if(cur -> val >= x)
				{
					if(cur -> l != nullptr)
					{
						if(cur -> l -> val < x && cur -> l -> val > n)
						{
							n = cur->l->val;
						}
					}	
					cur = cur->l;
				}
			}
			return n;
		}
		ver* push(unsigned int x, string y, ver* last)
		{
			ver*& z = find(x);
			if(z == nullptr)
			{
				z = new ver();
				z -> val = x;
				z -> ans = y;
				z -> prev = last;
				if(last != nullptr)
					last -> next = z;  
				return z;
			}
			else
			{
				z -> ans = y;
				return nullptr;
			}
		}
		void erase(unsigned int x,ver*& last)
		{                
			ver*& z = find(x);
			if(z != nullptr)
			{           
				ver* prev = z->prev;
				ver* next = z->next;
				if(prev!=nullptr)
					prev->next = next;
				if(next!=nullptr)
					next->prev = prev;
				if(z->l == nullptr && z->r ==nullptr)
				{       
					if(z==last)
					{
						last = z->prev;
					}
					z = nullptr;
					return;
			   	}
			   	if(z->l == nullptr)
			   	{
			   		z = z->r;
			   		return; 
			   	}
			   	if(z->r == nullptr)
			   	{
			   		z = z->l;
			   		return;
			   	}
			   	unsigned int u = this->next(x);
			   	if(u != x)
			   	{
			   		swap(find(u)->val, z->val);
			   		erase(x, last);
			   	}
			   	else
			   	{       
			   		return;
			   	}
			}			
		}
		string exists(unsigned int x) {
			auto t = find(x); 
			if(t == nullptr)
				return "none";
			else 
				return t->ans;
		}
		string nx(unsigned int x) {
			auto t = find(x); 
			if(t!= nullptr)
			{
				if(t->next == nullptr)
					return "none";
				else 
					return t->next->ans;
			}
			else
			{
				return "none";
			}
		}
		string pr(unsigned int x) {
			auto t = find(x); 
			if(t!= nullptr)
			{
				if(t->prev == nullptr)
					return "none";
				else 
					return t->prev->ans;
			}
			else
			{
				return "none";
			}
		}
		

};

tree v[1000000];
unsigned int P[20];
void pre_calc()
{                             	
	const unsigned int p = 7;
	P[0]=1;
	for(int i = 1;i<20;i++)
	{
		P[i] = P[i-1]*p;
	}
}

unsigned int hashS(string s)
{ 	
	unsigned int ans = 0;
	for(int i = 0;i<(int)s.size();i++)
	{
		ans += (s[i]+4) * P[i];
	}		
	return ans;
}         

int main()
{
	freopen("linkedmap.in","r",stdin);
	freopen("linkedmap.out","w",stdout);
	ios_base::sync_with_stdio(false);
	string s;
	pre_calc();
	ver* last = nullptr;
	while(cin >>s)
	{
		if(s == "put")	
		{
			string buf;
			cin>>buf;
			unsigned int val = hashS(buf);
			unsigned int hash = val%1000000;
			cin>>buf;
			ver* cur = v[hash].push(val, buf,last);
			if(cur!=nullptr)
			{
				last = cur; 
			}
		}	             
		if(s == "get")
		{
			string buf;
			cin>>buf;
			unsigned int val = hashS(buf);
			unsigned int hash = val%1000000;
			cout<<v[hash].exists(val)<<endl;
		}                
		if(s == "delete")	
		{
			string buf;
			cin>>buf;
			unsigned int val = hashS(buf);
			unsigned int hash = val%1000000;
			v[hash].erase(val,last);
		}                
		if(s == "prev")	
		{
			string buf;
			cin>>buf;
			unsigned int val = hashS(buf);
			unsigned int hash = val%1000000;
			cout<<v[hash].pr(val)<<endl;
		}	
		if(s == "next")	
		{
			string buf;
			cin>>buf;
			unsigned int val = hashS(buf);
			unsigned int hash = val%1000000;
			cout<<v[hash].nx(val)<<endl;
		}	                  


		
	}
	return 0;
}
