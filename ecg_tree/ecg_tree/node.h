#ifndef _node_h_
#define _node_h_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

class node{
private:
	string name;
	vector<node*> childs;
	static int node_id;				// Aufgabe 1.2
	int depth;						// Aufgabe 1.2.3
	

public:
	node(const string& name);
	node();
	virtual ~node();
	string get_name() const;
	void set_name(string new_name);
	int get_nr_children() const;
	node* get_child(int i) const;
	node* add_child(node* child);
	ostream* print(ostream *str, node* root);		// Aufgabe 1.2.3
	int get_depth();						// Aufgabe 1.2.3
	void set_depth(unsigned depth);				// Aufgabe 1.2.3
	friend ostream& operator<<(ostream& out, node* node);		// Aufgabe 1.2.3
	void tree_set_depth();				// Aufgabe 1.2.3

	
		 

};

extern ostream& operator<<(ostream& out, node* node);		// Aufgabe 1.2.3 

node* create_complete_tree(int nr_child_nodes, int tree_depth);
node* create_complete_tree_it(int nr_child_nodes, int tree_depth);


#endif


