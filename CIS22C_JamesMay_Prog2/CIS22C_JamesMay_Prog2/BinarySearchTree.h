#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <typename T>
class BinarySearchTree {

	//Simple struct for the binary nodes that will be used in this BST
	template <typename T>
	struct BinaryNode {
		T item;
		BinaryNode* parent;
		BinaryNode* leftChild;
		BinaryNode* rightChild;
		BinaryNode(){}
		BinaryNode(T item, BinaryNode* parent) {
			this->item = item;
			this->parent = parent;
		}
		BinaryNode(T item, BinaryNode* parent, BinaryNode* leftChild, BinaryNode* rightChild) {
			this->item = item;
			this->parent = parent;
			this->leftChild = leftChild;
			this->rightChild = rightChild;
		}
	};

	BinaryNode* root;
	int size;

public:
	//Constructors
	BinarySearchTree() { this->root = new BinaryNode(); }
	BinarySearchTree(T item) { this->root = new BinaryNode(item, nullptr); }

	//Accessors
	BinaryNode* getRoot() { return this->root; }
	int getSize() { return this->size; }

	BinaryNode* getParent(BinaryNode* node) { return node->parent; }
	BinaryNode* getLeftChild(BinaryNode* node) { return node->leftChild; }
	BinaryNode* getRightChild(BinaryNode* node) { return node->rightChild; }
	//Methods


	//Destructor
	~BinarySearchTree();
};

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {

}

#endif BINARYSEARCHTREE_H