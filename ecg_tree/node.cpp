#include "node.h"

int node::node_id = 0;		// Aufgabe 1.2


node::node(const string& name) : name(name), depth(0){
	node_id++;
	if( name == "" ){
		stringstream str_sm;
		str_sm << "node_" << node_id;
		this->name = str_sm.str();
	}
}

node::node() : depth(0){
	node_id++;
	stringstream str_sm;
	str_sm << "node_" << node_id;
	this->name = str_sm.str();
}

node::~node(){
	cout << "enter ~node of \"" << name << "\""<< endl;
	while(childs.empty()  == false){
		delete childs.front();
		childs.erase(childs.begin());
	} 
	node_id--;
	cout << "leave ~node of \"" << name << "\"" << endl;
}

string node::get_name() const{
	return name;
}

void node::set_name(string new_name){
	name = new_name;
}

int node::get_nr_children() const{
	return childs.size();		
}

node* node::get_child(int i) const{
	return childs.at(i);
}

node* node::add_child(node* child){
	child->set_depth(depth + 1);
	childs.push_back( child );
	return child;
}


// Aufgabe 1.2.2

node* create_complete_tree(int nr_child_nodes, int tree_depth){
	node* root = new node();
	if(tree_depth > 1){
			for(int j = 0; j < nr_child_nodes; j++){
				root->add_child(create_complete_tree(nr_child_nodes, tree_depth - 1));
			}
	}
	root->tree_set_depth();
	return root;
}

// Aufgabe 1.2.3

void node::set_depth(unsigned depth){
	this->depth = depth;
}

int node::get_depth(){
	return depth;
}

void node::tree_set_depth(){
	for(int i = 0; i < get_nr_children(); i++){
		get_child(i)->set_depth(depth + 1);
		get_child(i)->tree_set_depth();
	}
}

 ostream* node::print(ostream *str, node* root){
	for(int i = 0; i < root->get_depth(); i++){
		*str << "\t";
	}

	*str << root->get_name() << endl;
	for(int j = 0; j < root->get_nr_children(); j++){
		print(str, root->get_child(j));
	}

	return str;
}

 ostream& operator<<(ostream& out, node* node){
	 return *node->print(&out , node);
 }

 // Zusatzaufgabe

 node* create_complete_tree_it(int nr_child_nodes, int tree_depth){
	 stack<node*> nodes;

	 node* root = new node();
	 nodes.push(root);

	 while(nodes.empty() == false){
		 if(nodes.top()->get_nr_children() < nr_child_nodes && nodes.top()->get_depth() < tree_depth -1){
			nodes.push(nodes.top()->add_child(new node()));
		 }else{
			 nodes.pop();
		 }
	 }
	 return root;
 }


