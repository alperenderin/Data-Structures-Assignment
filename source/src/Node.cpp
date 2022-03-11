/**
* @file Veri_Yapıları_Ödevi
* @description 	.txt dosyası içerisinden çekilen dataları Binary Search Tree içerisinde sakalama ve soy sayıları değerlendirilerek kazanılan bir oyun yapma
* @date 14.12.2019
* @author Alperen Derin alperenderinn@gmail.com
*/

#include "Node.h"

	Node::Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

	Node::Node() {};

	//Calculating own children for node
	int Node::getChildCount(Node* node)
	{
		if (node == NULL)
			return 0;
		if (node->left == NULL && node->right == NULL)
			return 0;
		else if (node->left == NULL && node->right->right == NULL && node->right->left == NULL)
			return 1;
		else if (node->right == NULL && node->left->right == NULL && node->left->left == NULL)
			return 1;
		else if (node->left != NULL && node->right != NULL && node->left->left == NULL && node->left->right == NULL && node->right->right == NULL && node->right->left == NULL)
			return 2;
		else {	
		//Alt düğümlerin soylarını topla + hemen kendi altımda bulunan düğümler kendi soylarına dahil olmadıkları için onları da dahil et.
		//Yani aşağıda bulduğum i değerleri, düğümün hemen altındaki düğümleri temsil ediyor. Onların soy sayılarının içerisinde kendi sayıları yok.Bundan dolayı eğer varsa alt düğümleri de eklemek gerekiyor.
			int i = 0;
			if (node->left != NULL) i++;	
			if (node->right != NULL) i++;
			return getChildCount(node->left) + getChildCount(node->right) + i;
		}
	}
	
	int Node::getData() { return data; }

	void Node::setData(int data){ this->data = data; }

	int Node::getChildCount() { return childCount; }

	void Node::setChildCount(int childCount) { this->childCount = childCount; }