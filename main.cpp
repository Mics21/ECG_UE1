#include "node.h"



int main(){
	// Aufgabe 1.1
	node* root = new node("root");
	root->add_child( new node("left child") );
	root->add_child( new node("right child") );

	cout << root << endl;

	delete root; 


	node* baum = create_complete_tree(2,4);


	cout << baum << endl;
	delete baum;


	// Zusatzaufgabe 2

	node* baum_it = create_complete_tree_it(2, 4);

	cout << baum_it << endl;



	system("Pause");
}