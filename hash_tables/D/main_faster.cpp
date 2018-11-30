#include<bits/stdc++.h>
 
using namespace std;
 
 
class mySet { 
    public:
    vector<string> st;
    int size = 0;
    const unsigned int q = 7;
    unsigned int P[20];
	void pre_calc()
	{
	    const unsigned int p = 7;
	    P[0]=7;
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
	        ans += (s[i]-40) * P[i];
	    }       
	    return ans;
	}         

    mySet(){
        st.resize(100,"");
        pre_calc();
    }
    bool get(string s)
    {
        int hash = hashS(s) % st.size();
        int i = hash;
        if(st[i] != s && st[i]!="")
        {
        	i = (i+q) % st.size();
        	while(i!=hash && st[i] != s && st[i]!="")
        	{
        	    i = (i+q) % st.size();
        	}
        }
        if(st[i] == s)
            return 1;
        else
            return 0;
    }
                            
    void push(string s)
    {
        if(get(s))
            return;
        size++;
        pushing(s);
    }

    void pushing(string s)
    {
        bool flag = 1;
       	vector<string> temp;
       	if((size*100)/st.size()>=50)
        	temp.resize(st.size()*2, "");
       	else
       		temp.resize(st.size(), "");
       	st.push_back(s);
       	while(flag)
       	{
			int pos;
			int x;
			flag = 0;
			for(int i=0;i<(int)st.size();i++)
        	{	
        		if(st[i]=="")
        			continue;
        		x = hashS(st[i]) % temp.size();
         	  	pos = x;
				if(temp[x]!="")
				{
					pos = (pos + q) % temp.size(); 
					while(pos!=x && temp[pos]!="")
            		{
                		pos=(pos+q)%temp.size();
            		}
            	}
            	if(temp[pos]=="")
                	temp[pos]=st[i];
                else
                {
                	flag = 1;
                	break;
                }
        	}
        	if(flag)
        	{
        		temp.assign(temp.size() * 2, "");
        	}
       	}
        st.resize(temp.size());
        for(int i = 0;i<(int)st.size();i++)
            st[i] = temp[i];
    }
    void dlt(string s)
    {
        if(!get(s))
            return;
        size--;
        int pos = hashS(s) % st.size();;
        while(st[pos]!=s)
        {
            pos = (pos + q) % st.size();
        }               
        st[pos] = "";
        bool flag = 1;
       	vector<string> temp;
        temp.resize(st.size(), "");
       	while(flag)
       	{
			int pos;
			int x;
			flag = 0;
			for(int i=0;i<(int)st.size();i++)
        	{	
        		if(st[i]=="")
        			continue;
        		x = hashS(st[i]) % temp.size();
         	  	pos = x;
				if(temp[x]!="")
				{
					pos = (pos + q) % temp.size(); 
					while(pos!=x && temp[pos]!="")
            		{
                		pos=(pos+q)%temp.size();
            		}
            	}
            	if(temp[pos]=="")
                	temp[pos]=st[i];
                else
                {
                	flag = 1;
                	break;
                }
        	}
        	if(flag)
        	{
        		temp.assign((temp.size()*3)/2, "");
        	}
       	}
        st.resize(temp.size());
        for(int i = 0;i<(int)st.size();i++)
            st[i] = temp[i];        
    }         
}; 
class ver {
    public:
        unsigned int val;
        mySet ans;
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
        void push(unsigned int x, string y)
        {
            ver*& z = find(x);
            if(z == nullptr)
            {
                z = new ver();
                z -> val = x;
                z -> ans.push(y);
            }
            else
            {
                z->ans.push(y);
            }
        }
        void erase(unsigned int x, string y)
        {
            ver*& z = find(x);
            if(z != nullptr)
            {
                z->ans.dlt(y);
                if(z->ans.size!=0)
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
                    erase(x,y);
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
 
        mySet* exists(unsigned int x) {
            auto t = find(x); 
            if(t == nullptr)
            {
                return nullptr;
            }
            else
                return &t->ans;
        }
};
 
const unsigned int SZ = 1000000;
 
tree v[SZ];
unsigned int P[20];
void pre_calc()
{
    const unsigned int p = 7;
    P[0]=7;                 
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
        ans += (s[i]-40) * P[i];
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
            unsigned int hash = val%SZ;
            cin>>buf;
            v[hash].push(val, buf);
        }           
        if(s == "get")
        {                   
            string buf;
            cin>>buf;       
            unsigned int val = hashS(buf);
            unsigned int hash = val%SZ;
            mySet* cur = v[hash].exists(val); 
            if(cur!=nullptr)
            {
                vector<string>& u = cur->st;
                cout<<cur->size<<' ';
                for(int i = 0;i<(int)u.size();i++)
                {
                	if(u[i]!="")
                  		cout<<u[i]<<' ';
                }                     
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
            unsigned int hash = val%SZ;
            v[hash].erase(val,s1);
        }
        if(s == "deleteall")    
        {
            string buf;   
            cin>>buf;
            unsigned int val = hashS(buf);
            unsigned int hash = val%SZ;
            v[hash].eraseAll(val);
        }   
         
    }
    return 0;
}