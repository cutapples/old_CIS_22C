#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <typename T>
class BinarySearchTree {

	//Simple struct for the binary nodes that will be used in this BST
	template <typename T>
	struct BinaryNode {
		T item;
		BinaryNode<T>* parent;
		BinaryNode<T>* leftChild;
		BinaryNode<T>* rightChild;
		bool hasItem;

		BinaryNode<T>() { this->hasItem = false; }
		BinaryNode<T>(T item, BinaryNode<T>* parent) {
			this->item = item;
			this->parent = parent;
			this->leftChild = new BinaryNode<T>();
			this->rightChild = new BinaryNode<T>();
			this->hasItem = true;
		}
		BinaryNode<T>(T item, BinaryNode<T>* parent, BinaryNode<T>* leftChild, BinaryNode<T>* rightChild) {
			this->item = item;
			this->parent = parent;
			this->leftChild = leftChild;
			this->rightChild = rightChild;
			this->hasItem = true;
		}
	};

	BinaryNode<T>* root;
	int size;

public:
	//Constructors
	BinarySearchTree<T>() { this->root = new BinaryNode(); ++this->size; }
	BinarySearchTree<T>(T item) { this->root = new BinaryNode(item, nullptr); }

	//Accessors
	BinaryNode<T>* getRoot() { return this->root; }

	BinaryNode<T>* getParent(BinaryNode<T>* node) { return node->parent; }
	BinaryNode<T>* getLeftChild(BinaryNode<T>* node) { return node->leftChild; }
	BinaryNode<T>* getRightChild(BinaryNode<T>* node) { return node->rightChild; }
	//Methods
	bool isInternal(BinaryNode<T>*); //Returns true if the given node is an internal node
	bool isExternal(BinaryNode<T>*); //Returns true if the given node is an external node
	BinaryNode<T>* search(T, BinaryNode<T>*); //Searches for and returns a node that contains the given item under the initial given tree root. If not found returns a nullptr. (Uses the is external function) (Is recursive)
	BinaryNode<T>* searchSpot(T, BinaryNode<T>*); //Returns a position where a node can be added (Based on search function)
	void insert(T); //Takes an item and inserts a node with that item into the tree (Uses node constructor,search, and is internal functions)
	void deleteNode(BinaryNode<T>*);


	//Destructor
	~BinarySearchTree();
};

template <typename T>
bool BinarySearchTree<T>::isInternal(BinaryNode<T>* node) {
	return ((node->leftChild->hasItem) || (node->rightChild->hasItem));
}

template <typename T>
bool BinarySearchTree<T>::isExternal(BinaryNode<T>* node) {
	return (!(node->leftChild->hasItem) && !(node->rightChild->hasItem));
}

template <typename T>
BinarySearchTree<T>::BinaryNode<T>* BinarySearchTree<T>::search(T item, BinaryNode<T>* currentNode) {
	if (item == currentNode->item) {
		return currentNode;
	} else if (isExternal(currentNode)) {
		return nullptr;
	} else if (item <= currentNode->item) {
		search(item, currentNode->leftChild);
	} else if (item > currentNode->item) {
		search(item, currentNode->rightChild);
	}
}

template <typename T>
BinarySearchTree<T>::BinaryNode<T>* BinarySearchTree<T>::searchSpot(T item, BinaryNode<T>* currentNode) {
	if (isExternal(currentNode)) {
		return currentNode;
	} else if (item <= currentNode->item) {
		if (currentNode->leftChild->hasitem) {
			search(item, currentNode->leftChild);
		} else {
			return currentNode;
		}
	} else if (item > currentNode->item) {
		if (currentNode->rightChild->hasItem) {
			search(item, currentNode->rightChild);
		} else {
			return currentNode;
		}
	}
}

template <typename T>
void BinarySearchTree<T>::insert(T item) {
	BinaryNode<T>* currentNode = searchSpot(item, this->root);
	if (item <= currentNode->item) {
		delete currentNode->leftChild;
		currentNode->leftChild = new BinaryNode<T>(item, currentNode);
	} else {
		delete currentNode->rightChild;
		currentNode->rightChild = new BinaryNode<T>(item, currentNode);
	}
}

template <typename T>
void BinarySearchTree<T>::deleteNode(BinaryNode<T>* node) {
	if (node != this->root) {
		if (isExternal(node)) {
			delete node->leftChild;
			delete node->rightChild;
			delete node;
		} else {
			if (!node->rightChild->hasItem) {
				delete node->rightChild;
				node->leftChild->parent = node->parent;
				node->parent->leftChild = node->leftChild;
				delete node;
			} else if (!node->leftChild->hasItem) {
				delete node->leftChild;
				node->rightChild->parent = node->parent;
				node->parent->leftChild = node->rightChild;
				delete node;
			} else {
				BinaryNode<T>* tempPtr = node->rightChild;
				while (tempPtr->leftChild->hasitem) {
					tempPtr = tempPtr->leftChild;
				}
				node->leftChild->parent = tempPtr;
				node->rightChild->parent = node->parent;
				node->parent->leftChild = node->rightChild;
				delete node;
			}
		}
	}
}

template <typename T>
void BinarySearchTree<T>::deleteItem(T item) {
	BinaryNode<T>* node = search(item, this->root);
	if (node != nullptr) {
		deleteNode(node);
	}
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {

}

#endif BINARYSEARCHTREE_H
