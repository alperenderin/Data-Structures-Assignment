/**
* @file Veri_Yapıları_Ödevi
* @description 	.txt dosyası içerisinden çekilen dataları Binary Search Tree içerisinde sakalama ve soy sayıları değerlendirilerek kazanılan bir oyun yapma
* @date 14.12.2019
* @author Alperen Derin alperenderinn@gmail.com
*/

#include "Bst.h"

	void Bst::insert(Node*& subNode, int data) {

		if (subNode == NULL)	//If there are no nodes or the end has been reached
			subNode = new Node(data);

		else if (data <= subNode->getData())
			insert(subNode->left, data);

		else if (data > subNode->getData())
			insert(subNode->right, data);

		else return;
	}

	void Bst::postorder(Node* subNode) {

		node = new Node;
		
		if (subNode != NULL) {
			postorder(subNode->left);
			postorder(subNode->right);
			cout << " < " << subNode->getData() << "," << node->getChildCount(subNode) << " > ";
		}
	}


	void Bst::findAndRemove(Node*& subNode, int data) {

		if (subNode == NULL) return; //There is no tree

		if (data < subNode->getData())
			return findAndRemove(subNode->left, data);
		else if (data > subNode->getData())
			return findAndRemove(subNode->right, data);
		else if (data == subNode->getData())
			remove(subNode);
	}

	bool Bst::remove(Node*& subNode) {
	
		iter = subNode;
		iterParent = subNode;

		if (subNode->left == NULL)			//A single child and a leaf
			subNode = subNode->right; 		//If it's leaf, we made it NULL, if it's only one child, we linked it to a child
		else if (subNode->right == NULL)	//A single left child
			subNode = subNode->left;
		else {								//If it has two child nodes (Replacing the Left Subtree with the Largest)
			iter = subNode->left;			
			while (iter->right != NULL) {
				iterParent = iter;
				iter = iter->right;
			}
			subNode->setData(iter->getData());
			if (iterParent == subNode) subNode->left = iter->left;	//If there is only one node under the subNode, iterParent == subNode will not enter the while loop. Because of this - and because iter needs to be removed - we connect the subNode to a child node
			else iterParent->right = iter->left;					//If there is no single node, to remove the element before iter
		}

		return true;
	}

	void Bst::print(int myAllChild, int oponentallChild) {

		cout << "Benim Agac Postorder :" << endl;
		postorder(myRoot);
		cout << "\nBenim Agac Toplam Soy Sayisi : "<<myAllChild<<endl;
		cout << "\n-------------------------------------" << endl;
		cout << "Rakip Agac Postorder :" << endl;
		postorder(oponentRoot);
		cout << "\nRakip Agac Toplam Soy Sayisi : "<<oponentallChild<<endl;
	}

	void Bst::readMyList() {

		int counter = 0;
		int my_data = 0;

		file.open(".\\doc\\benim.txt", ios::in);

		while (file >> my_data) {	

			insert(myRoot, my_data);
		}
		file.close();
	}

	void Bst::readOponentList() {

		int oponent_data = 0;
		int counter = 0;

		file.open(".\\doc\\rakip.txt", ios::in);

		while (file >> oponent_data) {

			insert(oponentRoot, oponent_data);
		}
		file.close();
	}

	int Bst::calculateAllChild(Node* subNode)
{
		node = new Node;
		
		//it works like postorder logic
		if (subNode != NULL) {
			calculateAllChild(subNode->left);
			calculateAllChild(subNode->right);
			node->setChildCount(node->getChildCount(subNode));	//Children under the current node are found and assigned to their own subdomains
			tempAllChild += node->getChildCount();				//Then, the number of children from each sub-domain is summed. At the end of this process, the total subdomain of the node is found.
		}
		
		return tempAllChild;
	}

	int Bst::max(Node* subNode) {	//Find max node
	
		while (subNode->right != NULL) {
			subNode = subNode->right;
		}
		int tempval = subNode->getData();

		return tempval;
	}

	void Bst::control() {
		
		int lap = 0;
		int myScore = 0;
		int oponentScore = 0;
		
		do {
			lap++;
			
			if (abs(oponentScore - myScore) == 5 || lap == 20)
				break;
	 
			allChildMyLeaf = calculateAllChild(myRoot);				//Finds the sum of all children of my tree
			tempAllChild = 0;										//Since I keep the total number of children with the same field for both my and oponent trees, it should be reset after each calculation.
			allChildOponentLeaf = calculateAllChild(oponentRoot);
			tempAllChild = 0;										

			print(allChildMyLeaf, allChildOponentLeaf);

			if (allChildMyLeaf < allChildOponentLeaf)			//The winner is my tree
			{
				insert(myRoot, max(oponentRoot));				//Adds the largest node of the opposing tree to itself and deletes the largest element of the opposite tree
				findAndRemove(oponentRoot, max(oponentRoot));	
				insert(oponentRoot, myRoot->getData());			//Adds its own root to the opposing tree
				findAndRemove(myRoot, myRoot->getData());		//And delete its own root
				myScore++;
				cout << "\n\n--------------TEBRIKLER, TURU SIZ KAZANDINIZ--------------\n";
			}
			else if (allChildMyLeaf > allChildOponentLeaf)		//The winning ıs opposite
			{
				insert(oponentRoot, max(myRoot));
				findAndRemove(myRoot, max(myRoot));
				insert(myRoot, oponentRoot->getData());
				findAndRemove(oponentRoot, oponentRoot->getData());
				oponentScore++;
				cout << "\n\n--------------TEBRIKLER, TURU RAKIP KAZANDI--------------\n";
			}
			else if (allChildMyLeaf == allChildOponentLeaf)				//Draw
			{	
				
				int myData = myRoot->getData();							//Data is backed up			
				int oponentData = oponentRoot->getData();

				findAndRemove(myRoot, myRoot->getData()); 				//Both Roots are removed
				findAndRemove(oponentRoot, oponentRoot->getData());

				insert(myRoot, oponentData);							//Roots are added by exchanging
				insert(oponentRoot, myData);

				cout << "\n\n--------------SONUC BERABERE--------------\n";
			}
			cout << "SKOR:\n" << "Benim : " << myScore << "\nRakip : " << oponentScore << endl << endl<<endl;

			system("pause");
		} while (true);
	}

	void Bst::start() {
		system("cls");
		readOponentList();
		readMyList();
		control();
	}
	
	Bst::~Bst(){
		delete iter;
		delete iterParent;
		delete node;
		delete tempNode;
	}