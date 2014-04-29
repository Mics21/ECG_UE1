#include "node.h"

int main(){
	node* root = new node("root");
	root->add_child( new node("left child") );
	root->add_child( new node("right child") );

	cout << root << endl;

	delete root; 


	node* baum = create_complete_tree(2,4);


	cout << baum << endl;
	//delete baum;
	system("Pause");
}