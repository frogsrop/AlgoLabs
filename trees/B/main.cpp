#include<bits/stdc++.h>                                                                                                                                   

using namespace std;

struct node 
{
	int key;
	unsigned int height;
	node* left;
	node* right;
	node(int k) { key = k; left = right = 0; height = 1; }
};

unsigned int height(node* p)
{
	return p?p->height:0;
}

int bfactor(node* p)
{
	return height(p->right)-height(p->left);
}

void fixheight(node* p)
{
	int hl = height(p->left);
	int hr = height(p->right);
	p->height = (hl>hr?hl:hr)+1;
}

node* rotateright(node* p) {
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* rotateleft(node* q) 
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* balance(node* p) 
{
	fixheight(p);
	if( bfactor(p)==2 )
	{
		if( bfactor(p->right) < 0 )
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if( bfactor(p)==-2 )
	{
		if( bfactor(p->left) > 0  )
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; 
}

node* insert(node* p, int k) 
{
	if( !p ) return new node(k);  
	if( k<p->key )
		p->left = insert(p->left,k);
	else
		p->right = insert(p->right,k);
	return balance(p);
}

node* findmin(node* p) 
{
	return p->left?findmin(p->left):p;
}

node* removemin(node* p) 
{
	if( p->left==0 )
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

node* remove(node* p, int k) 
{
	if(!p) return 0;
	if(k<p->key)
		p->left = remove(p->left,k);
	else if( k > p->key )
		p->right = remove(p->right,k);	
	else 
	{
		node* q = p->left;
		node* r = p->right;
		delete p;
		if( !r ) return q;
		node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

bool exists(node* p, int k)
{
	if(!p) return 0;
	if(p->key == k)
		return 1;
	if( k<p->key )
		return exists(p->left,k);
	else
		return exists(p->right,k);
	
}

int next(node* p, int k)
{
	if(!p) 
		return 999999999;
	printf("%i\n",p->key);
	if((p->key) > k)
	{
		return min(next(p->left,k),p->key);
	}              
	if((p->key) <= k)
	{
		cout<<p->right->key;
		return next(p->right,k);
	}
	return 0;
}

int prev(node* p, int k)
{
	if(!p) 
		return -999999999;
	if(p->key < k)
	{              
		return max(prev(p->right,k),p->key);
	}
	if(p->key >= k)
	{
		return prev(p->left,k);
	}
	return 0;
}

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out1.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	node* t=NULL;
	string s;
	while(cin>>s)         
	{
		int x;
		cin>>x;
		if(s=="insert")
		{
			if(!exists(t,x))
			{
				if(!t)
					t = insert(t,x);
		   		else
		   			insert(t,x);
		   	}
		   	if(x==3)
				cout<<'!'<<exists(t,5)<<'!';
		}
		if(s=="delete")
		{
			if(exists(t,x))
			{	
				if(t->key == x)
				{	
					node* q = t->left;
					node* r = t->right;
					if(!r) 
					{
						t = q;                           
					}
					else
					{                                       
						node* min = findmin(r);
						min->right = removemin(r);
						min->left = q;
						t = balance(min);  
					}
				}
				else
					remove(t,x);
				
			}
		}
		if(s=="exists")
		{
			cout<<(exists(t,x)?"true\n" : "false\n");
		}
		if(s=="next")
		{
			if(x==4)
				cout<<exists(t,5);
			int ans = next(t,x);
			if(ans == 999999999)
				cout<<"none"<<endl;
			else
				cout<<ans<<endl;
		}
		if(s=="prev")
		{
			int ans = prev(t,x);
			if(ans == -999999999)
				cout<<"none"<<endl;
			else
				cout<<ans<<endl;
		}
		//cout<<t.getH()<<' ';
	}
	return 0;
}