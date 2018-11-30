#include<bits/stdc++.h>

using namespace std;

class ver 
{
	public:
		unsigned int val;
		set<string> ans;

		ver *l, *r;
		
		ver()
		{
			val = 0;
			l = nullptr;
			r = nullptr;
		}
};

class tree {
	private:
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
		
	public:
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
						if(cur -> l -> val > x && cur -> l ->val < n)
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
		void push(unsigned int x, string y)
		{
			ver*& z = find(x);
			if(z == nullptr)
			{
				z = new ver();
				z -> val = x;
				z -> ans.insert(y);
			}
			else
			{
				z -> ans.insert(y);
			}
		}
		void erase(unsigned int x, string y)
		{
			ver*& z = find(x);
			if(z != nullptr)
			{
				z->ans.erase(y);
				if(z->ans.size()!=0)
					return;
				if(z->l == nullptr && z->r ==nullptr)
				{
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
			   	unsigned int u = next(x);
			   	if(u != x)
			   	{
			   		swap(find(u)->val, z->val);
			   		erase(x,"");
			   	}
			   	else
			   	{
			   		return;
			   	}
			}			
		}
		void eraseAll(unsigned int x)
		{
			ver*& z = find(x);
			if(z != nullptr)
			{
				if(z->l == nullptr && z->r ==nullptr)
				{
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
			   	unsigned int u = next(x);
			   	if(u != x)
			   	{
			   		swap(find(u)->val, z->val);
			   		eraseAll(x);
			   	}
			   	else
			   	{
			   		return;
			   	}
			}			
		}

		set<string>* exists(unsigned int x) {
			auto t = find(x); 
			if(t == nullptr)
			{
				return nullptr;
			}
			else 
				return &t->ans;
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
	freopen("multimap.in","r",stdin);
	freopen("multimap.out","w",stdout);
	ios_base::sync_with_stdio(false);
	string s;
	pre_calc();
	while(cin >>s)
	{
		if(s == "put")	
		{
			string buf;
			cin>>buf;
			unsigned int val = hashS(buf);
			unsigned int hash = val%1000000;
			cin>>buf;
			v[hash].push(val, buf);
		}	
		if(s == "get")
		{
			string buf;
			cin>>buf;
			unsigned int val = hashS(buf);
			unsigned int hash = val%1000000;
			set<string>* cur = v[hash].exists(val); 
			if(cur!=nullptr)
			{
				cout<<(*cur).size()<<' ';
				for(auto &go:(*cur))
					cout<<go<<' ';
				cout<<endl;   
			}
			else
			{
				cout<<0<<endl;
			}
		}
		if(s == "delete")	
		{
			string buf;
			string s1;
			cin>>buf;
			cin>>s1;
			unsigned int val = hashS(buf);
			unsigned int hash = val%1000000;
			v[hash].erase(val,s1);
		}
		if(s == "deleteall")	
		{
			string buf;   
			cin>>buf;
			unsigned int val = hashS(buf);
			unsigned int hash = val%1000000;
			v[hash].eraseAll(val);
		}	
		
	}
	return 0;
}
