#include <iostream>
#include <cstdlib>
using namespace std;
class Node {
	Node** children;
	Node* parent;
	int* data;
	int size;
	
	public:
	Node(int num, Node* parent) {
		this->parent = parent;
		size = 1;
		
		data = (int*) malloc(sizeof(int*) * 4);
		data[0] = num;
		
		children = (Node**) calloc(sizeof(Node*), 5);
	}
	
	int getData(int i) {
		return data[i];
	}
	
	int getSize() {
		return size;
	}
	
	Node* getParent() {
		return parent;
	}
	
	Node* getChild(int i) {
		return children[i];
	}
	
	int indexOf(int num) {
		for(int i = 0; i < size; i++) {
			if(num == data[i]) {
				return i;
			}
		}
	}
	
	void insertChildren(Node* wp, Node* w2p, int pos) {
		for(int i = size- 1; i > pos; i--) {
			children[i + 1] = children[i];
		}
		children[pos] = wp;
		children[pos + 1] = w2p;
	}
	
	bool addKey(int num) {
		int i;
		for(i = size; i > 0; i--) {
			if(data[i - 1] > num) {
				data[i] = data[i - 1];
			} else {
				break;
			}
		}
		data[i] = num;
		return ++size != 4;
	}
	
	void print() {
		for(int i = 0; i < size; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
		for(int i = 0; i < 5; i++) {
			if(children[i]) {
				children[i]->print();
			}
		}
	}
};
