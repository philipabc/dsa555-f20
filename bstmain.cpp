#include "bst.h"

int main(void){
	BST<int> tree;


	tree.insertRecursive(10);
	tree.insertRecursive(15);
	tree.insertRecursive(5);
	tree.insertRecursive(8);
	tree.insertRecursive(25);
	tree.insertRecursive(21);
	tree.insertRecursive(4);
	tree.breadthFirstPrint();

	std::cout << "sorted: " << std::endl;
	tree.inOrderPrint();
}