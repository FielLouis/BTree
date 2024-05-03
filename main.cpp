#include <iostream>
#include "tree24.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Tree24* tree = new Tree24();
	tree->insert(13);
	
	cout << "Searching for 4: ";
	tree->search(4)->print();
	cout << endl;
	
	tree->insert(4);
	tree->insert(17);
	tree->insert(5);
	tree->insert(26);
	
	tree->insert(69);
	tree->insert(1);
	tree->insert(2);
	tree->print();
	return 0;
}
