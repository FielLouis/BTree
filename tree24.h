#include "node.h"
#include <iostream>
using namespace std;
class Tree24 {
	Node* root;
	int size;

	Node* search(Node* n, int num) {
		int index = n->getSize();
		for(int i = 0; i < n->getSize(); i++) {
			if(num == n->getData(i)) {
				return n;
			} else if(num < n->getData(i)) {
				index = i;
				break;
			}
		}
		if(!n->getChild(index)) {
				return n;
			}
		return search(n->getChild(index), num);
	}
	
	public:
	Tree24() {
		root = NULL;
		size = 0;
	}
	
	Node* search(int num) {
		return search(root, num);
	}
	
	void insert(int num) {
		if(!root) {
			root = new Node(num, NULL);
		} else {
			Node* w = search(num);
			bool ok = w->addKey(num);
			
			while(!ok) { //overflow
				Node* u;
				int pos;
				
				if(w == root) {
					u = new Node(w->getData(2), NULL);
					root = u;
					pos = 0;
					ok = true;
				} else {
					u = w->getParent();
					ok = u->addKey(w->getData(2));
					pos = u->indexOf(w->getData(2));
				}
				
				Node* wp = new Node(w->getData(0), u);
				wp->addKey(w->getData(1));
				
				Node* w2p = new Node(w->getData(3), u);
				u->insertChildren(wp, w2p, pos);
				w = u;
			}
		}
		size++;
	}
	
	void print() {
		cout << "Size: " << size << endl;
		root->print();
	}
};
