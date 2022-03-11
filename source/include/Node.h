#include <iostream>
class Node {
private:
	int data;
	int childCount = 0;
public:
	Node* left;
	Node* right;
	
	Node(int);
	Node();

	int getData();
	void setData(int);

	int getChildCount();
	void setChildCount(int);

	int getChildCount(Node*);
};
