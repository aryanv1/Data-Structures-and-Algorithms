#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Least Recently Used
class LRUCache {
public:
	class node {
	public:
		int key;
		int val;
		node* next;
		node* prev;
		node(int _key, int _val) 
		{
			key = _key;
			val = _val;
		}
	};

	node* head = new node(-1, -1);
	node* tail = new node(-1, -1);
	unordered_map<int, node*> m;
	int cap;

	LRUCache(int capacity) 
	{
		cap = capacity;
		head->next = tail;
		tail->prev = head;
	}

	void add_newnode(node* n) 
	{
		node *temp = head->next;
		n->next = temp;
		n->prev = head;
		head->next = n;
		temp->prev = n;
	}

	void delete_node(node* delnode) 
	{
		node * delprev = delnode->prev;
		node * delnext = delnode->next;
		delprev->next = delnext;
		delnext->prev = delprev;
	}

	int get(int key) 
	{
		if (m.find(key) != m.end())
		{
			node* t = m[key];
			int value = t->val;
			m.erase(key);
			delete_node(t);

			add_newnode(t);
			m[key] = head->next;
			return value;
		}
		return -1;
	}

	void put(int key, int value) 
	{
		if (m.find(key) != m.end()) 
		{
			node *temp = m[key];
			m.erase(key);
			delete_node(temp);
		} 
		if (m.size() == cap) 
		{
			m.erase(tail->prev->key);
			delete_node(tail->prev);
		}
		node* p = new node(key, value);
		add_newnode(p);
		m[key] = head->next;
	}
};

int main()
{
	
	return 0;
}