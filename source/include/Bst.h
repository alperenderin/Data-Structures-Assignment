#include <iostream>
#include <fstream>
#include <conio.h>
#include "Node.h"

using namespace std;

class Bst {
private:
	Node* myRoot = NULL;
	Node* oponentRoot = NULL;
	
	fstream file;
	
	int tempAllChild = 0;
	int allChildMyLeaf = 0;
	int allChildOponentLeaf = 0;
	
	Node* iter;
	Node* iterParent;
	Node* node;
	Node* tempNode;
public:
	void insert(Node*&, int);
	void findAndRemove(Node*&, int);
	bool remove(Node*&);

	void postorder(Node*);
	void print(int, int);

	void readMyList();
	void readOponentList();
	
	int calculateAllChild(Node* subNode);
	int max(Node*); 
	
	void start();
	void control();
	
	~Bst();
};

