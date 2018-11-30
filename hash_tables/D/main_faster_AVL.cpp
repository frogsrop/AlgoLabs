#include<bits/stdc++.h>
 
using namespace std;
 
 
#define BALANCE_FLAG_R	1	
#define BALANCE_FLAG_H	2	


class AVL_tree{
protected:
	struct node_st {
		node_st *p1;
		node_st *p2;
		string value;	
		int b;		
	};
	node_st *tree_root;
private:
	int count;		
	node_st *NewItem(string value);			
	void DelItem(node_st *node);		
	void Clear(node_st *node);			 
	bool Insert(node_st **node,string value);
	bool Remove(node_st **node,string value);
	bool GetMin(node_st **root,node_st **res);
	node_st *Rotate12(node_st*);			
	node_st *Rotate21(node_st*);			
	int Balance(node_st**,int);				
public:
	AVL_tree();
	~AVL_tree();				
	void Clear();				
	void Insert(string value);		
	void Remove(string value);		
	bool Find(string value);		
	int GetCount();
	vector<string> get();		
};


AVL_tree::AVL_tree()
{
	tree_root=0; count=0;
}

AVL_tree::~AVL_tree()
{
	Clear(tree_root);
}

int AVL_tree::GetCount()
{
	return count;
}

void AVL_tree::Clear()
{
	Clear(tree_root);
	tree_root=0;
}

void AVL_tree::Clear(node_st *node)
{
	if(!node) return;
	Clear(node->p1);
	Clear(node->p2);
	DelItem(node);
}

AVL_tree::node_st *AVL_tree::NewItem(string value)
{
	count++;
	node_st *node=new node_st;
	node->b=0;
	node->value=value;
	node->p1=node->p2=0;
	return node;
}

void AVL_tree::DelItem(node_st *node)
{
	count--;
	delete node;
}

void AVL_tree::Insert(string value)
{
	Insert(&tree_root,value);
}

void AVL_tree::Remove(string value)
{
	Remove(&tree_root,value);
}

bool AVL_tree::Find(string value)
{
	node_st *node=tree_root;
	while(node) {
		if(node->value==value) return true;
		if(node->value>value) node=node->p1; else node=node->p2;
	}
	return false;
}

int AVL_tree::Balance(node_st **root,int res=0)
{
	node_st *node=*root; 
	if(node->b>1) {
		res=BALANCE_FLAG_R;
		if(node->p2->b) res|=BALANCE_FLAG_H;
		if(node->p2->b<0) node->p2=Rotate12(node->p2);
		*root=Rotate21(node);
	}
	if(node->b<-1) {
		res=BALANCE_FLAG_R;
		if(node->p1->b) res|=BALANCE_FLAG_H;
		if(node->p1->b>0) node->p1=Rotate21(node->p1);
		*root=Rotate12(node);
	}
	return res;
}

bool AVL_tree::Insert(node_st **root,string value)
{
	bool res=false;
	node_st *node=*root;
	if(!node) {
		*root=NewItem(value);
		return true;
	}
	if(value==node->value) return false; 
	if(value<node->value) res=Insert(&node->p1,value) && !!--node->b;
	else                  res=Insert(&node->p2,value) && !!++node->b;
	if(Balance(root)&BALANCE_FLAG_R) res=false;
	return res;
}

AVL_tree::node_st *AVL_tree::Rotate12(node_st *node)
{
	static const int array[6][4]={
		-1,-1,+1,+1,
		-1,+0,+1,+0,
		-1,+1,+2,+0,
		-2,-1,+0,+0,
		-2,-2,+0,+1,
		-2,+0,+1,-1 
	};
	node_st *p1=node->p1;
	node_st *p12=p1->p2;
	p1->p2=node;
	node->p1=p12;
	for(int n=0;n<6;n++) if(array[n][0]==node->b && array[n][1]==p1->b) {
		p1->b=array[n][2];
		node->b=array[n][3];
		break;
	}
	return p1;
}

AVL_tree::node_st *AVL_tree::Rotate21(node_st *node)
{
	static const int array[6][4]={
		+1,-1,-2,+0,
		+1,+0,-1,+0,
		+1,+1,-1,-1,
		+2,+0,-1,+1,
		+2,+1,+0,+0,
		+2,+2,+0,-1 
	};
	node_st *p2=node->p2;
	node_st *p21=p2->p1;
	p2->p1=node;
	node->p2=p21;
	for(int n=0;n<6;n++) if(array[n][0]==node->b && array[n][1]==p2->b) {
		p2->b=array[n][2];
		node->b=array[n][3];
		break;
	}
	return p2;
}

bool AVL_tree::GetMin(node_st **root,node_st **res)
{
	node_st *node=*root;
	if(node->p1) {
		if(GetMin(&node->p1,res) && !++node->b) return true;
		return !!(Balance(root)&BALANCE_FLAG_H);
	}
	*res=node;
	*root=node->p2;
	return true;
}


bool AVL_tree::Remove(node_st **root,string value)
{
	bool ok=false;
	node_st *node=*root;
	if(!node) return ok;
	if(node->value<value) {
		if(Remove(&node->p2,value) && !--node->b) ok=true;
	}else if(node->value>value) {
		if(Remove(&node->p1,value) && !++node->b) ok=true;
	}else {						
		if(!node->p2) {			
			*root=node->p1;DelItem(node);
			return true;
		}
		ok=GetMin(&node->p2,root);
		(*root)->b =node->b;	
		(*root)->p1=node->p1;
		(*root)->p2=node->p2;
		DelItem(node);
		if(ok) ok=!--(*root)->b;
	} 
	return !!(Balance(root,ok?BALANCE_FLAG_H:0)&BALANCE_FLAG_H);
}
vector<string> AVL_tree::get()
{
	vector<string> v;
	if(tree_root == 0)
		return v;
	queue<node_st> q;
	q.push(*tree_root);
	while(q.size())
	{
		v.push_back(q.front().value);
		if(q.front().p1!=0)
		q.push(*(q.front().p1));
		if(q.front().p2!=0)
		q.push(*(q.front().p2));
		q.pop();
	}
	return v;
}
 
class ver {
    public:
        unsigned int val;
        AVL_tree ans;
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
                z -> ans.Insert(y);
            }
            else
            {
                z->ans.Insert(y);
            }
        }
        void erase(unsigned int x, string y)
        {
            ver*& z = find(x);
            if(z != nullptr)
            {
                z->ans.Remove(y);
                if(z->ans.GetCount()!=0)
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
 
        AVL_tree* exists(unsigned int x) {
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
            auto cur = v[hash].exists(val); 
            if(cur == nullptr)
            	cout<<0<<endl;
            else
            {	
            	cout<<cur->GetCount()<<' '; 
            	vector<string> out = cur->get();
            	for(auto& t:out)
            	{
            			cout<<t<<' ';
           	 	}                     
            	cout<<endl;  
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