#include<bits/stdc++.h>

using namespace std;

struct suff_tree
{
	const static int amount = 'z' - 'a' + 1; 
	int amount_of_nodes;
	struct node
	{
		unique_ptr<node> kids[amount];
		int num;
		node(int num)
		{
			this->num = num;		
		}
	} head = node(1);	

	suff_tree() 
	{
		amount_of_nodes = 1;
	}
	bool add_suff(const string& s)
	{       	
		node* cur = &head;
		bool is_added = 0;
		for(int i = 0; i < (int)s.size(); i++)
		{
			int symbol = s[i] - 'a';
			if(cur -> kids[symbol] == nullptr)
			{                     
				cur -> kids[symbol].reset(new node(amount_of_nodes + 1));
				is_added = 1;
				amount_of_nodes++;
			}
			cur = cur->kids[symbol].get(); 		
		}
		return is_added;
	}

	void add_string(const string& s)
	{
		for(int i = 0; i < (int)s.size(); i++)
		{
			add_suff(s.substr(i, s.size() - i));
		}
	}

	void out_tree(node* cur)
	{
		for(int i = 0; i < amount; i++)
		{
			if(cur -> kids[i] != nullptr)
			{
				cout << cur -> num << " " << cur -> kids[i] -> num << " " << char(i + 'a') << endl;
				out_tree(cur -> kids[i].get());
			}
		}	
	}
};

int main()
{
	suff_tree my;
	string s;
	cin>>s;
	my.add_string(s);
	cout << my.amount_of_nodes << " " << my.amount_of_nodes - 1 << endl;
	my.out_tree(&my.head);
	return 0;
}