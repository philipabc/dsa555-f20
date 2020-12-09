#include "arrqueue.h"
#include <iostream>

template <typename T>

class BST{
	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		Node(const T& data=T{},Node* left=nullptr, Node* right=nullptr){
			data_=data;
			left_=left;
			right_=right;
		}
	};

	Node* root_;
	//this print function prints in sorted(inorder)
	//manner
	//stroot - sub tree root
	void print(const Node* stroot) const{
		//base case is to do nothing... 
		//if no tree do nothing, exit function
		if(stroot){
			//print left subtree (every smaller value)
			print(stroot->left_);
			//print node
			std::cout << stroot->data_ << std::endl;
			//print right subtree (every biggervale)
			print(stroot->right_);
		}
	}
	//this function destroys the subtree
	//with root stroot
	void clear(Node* stroot){
		if(stroot){

			clear(stroot->left_);
			clear(stroot->right_);
			delete stroot
		}
	}


	//recursive insert function
	//insert the data into the subtree with root
	//stroot
	void insert(Node*& stroot, const T& data){
		if(stroot==nullptr){
			stroot=new Node(data);
		}
		else{
			if(data < stroot->data_){
				insert(stroot->left_,data);
			}
			else{
				insert(stroot->right_,data);
			}
		}
	}

	bool isEqual(const Node* lhs,const Node* rhs){
		if(lhs == nullptr && rhs == nullptr){
			return true;
		}
		else if(lhs == nullptr && rhs != nullptr){
			return false;
		}
		else if(rhs == nullptr && lhs!=nullptr){
			return false;
		}
		else{
			if(lhs->data_ != rhs->data_){
				return false;
			}
			else{
				return isEqual(lhs->left_,rhs->left_) &&
					isEqual(lhs->right_, rhs->right_);
			}
		}
	}

public:
	//creates empty BST
	BST(){
		root_=nullptr;
	}  
	//insert data into the BST
	void insertRecursive(const T& data){
		//insert data into the tree with root
		//root_
		insert(root_,data);
	}

	//insert data into the BST
	void insertIterative(const T& data){
		if(root_== nullptr){
			root_=new Node(data);
		}
		else{
			bool inserted=false;
			Node* curr=root_;
			while(!inserted){
				if(data < curr->data_){
					if(curr->left_==nullptr){
						curr->left_=new Node(data);
						inserted=true;
					}
					else{
						curr=curr->left_;
					}
				}
				else{

					if(curr->right_==nullptr){
						curr->right_=new Node(data);
						inserted=true;
					}
					else{
						curr=curr->right_;
					}
				}
			}

		}
	}

	//this function returns true, if data is in the tree
	bool isPresent(const T& data){}

	//this function prints values from
	//smallest to biggest
	void inOrderPrint() const{
		print(root_);
	}


	//print the tree in a breadthfirst manner, using
	//queue to track what to print
    //method one.. allow nullptrs to be added to queue
    //when we dequeue we have to check that its not nullptr
    //method two ... only allow non-pointers into the queue
    //must check that pointer isn't null before
    //each enqueue.  
    //We are doing method two
	void breadthFirstPrint() const{
		Queue<Node*> q;
		if(root_){
			q.enqueue(root_);
			while(!q.isEmpty()){
				Node* curr=q.front();
				q.dequeue();
				std::cout << curr->data_ << std::endl;
				if(curr->left_){
					q.enqueue(curr->left_);
				}
				if(curr->right_){
					q.enqueue(curr->right_);
				}
			}

		}
		else{
			std::cout << "tree is empty" << std::endl;
		}

	}

	~BST(){
		//post order tree traversal
		clear(root_);

	}

	bool operator==(const BST& rhs) const{
		return isEqual(root_,rhs.root_);
	}


};