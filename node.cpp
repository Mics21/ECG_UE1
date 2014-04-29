#include "node.h"

int node::node_id = 0;		// Aufgabe 1.2

// Man könnte das mit dem Konstruktor sauberer lösen

node::node(const string& name ) : name(name), depth(0){
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


// Aufgabe 1.2.2		==> tree depth muss richtig übergeben werden!

node* create_complete_tree(unsigned nr_child_nodes, unsigned tree_depth){
	node* root = new node();
	if(tree_depth > 1){
			for(unsigned j = 0; j < nr_child_nodes; j++){
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

unsigned node::get_depth(){
	return depth;
}

void node::tree_set_depth(){
	for(unsigned i = 0; i < get_nr_children(); i++){
		get_child(i)->set_depth(depth + 1);
		get_child(i)->tree_set_depth();
	}
}

 ostream* node::print(ostream *str, node* root){
	for(unsigned i = 0; i < root->get_depth(); i++){
		*str << "\t";
	}

	*str << root->get_name() << endl;
	for(unsigned j = 0; j < root->get_nr_children(); j++){
		print(str, root->get_child(j));
	}

	return str;
}

 ostream& operator<<(ostream& out, node* node){
	 return *node->print(&out , node);
 }


