// Write an algorithm to find the 
//'next'node (i.e., in-order successor) of a given node in a binary search tree. 
// You may assume that each node has a link to its parent
#include<iostream>
#include<list>
using namespace std;
typedef struct tree{
	int key;
	tree* right;
	tree* left;
	tree* parent;
} node;

// Create tree from an sorted array
//input arr =  {1,2,3,4,5,6,7,8,9}, s = 0 , e =8
// output:           5
//                /   \
//				 2	   7
//				/ \	  / \
//			   1   3  6  8
//					\     \
//                   4     9
node* createTree(int arr[], int s, int e, node* parent)
{
	if (e < s)
	{
		return NULL;
	}
	int mid = (e + s) / 2;
	node *root = new node;
	root->key = arr[mid];
	root->left = createTree(arr, s, mid - 1, root);
	root->right = createTree(arr, mid + 1, e, root);
	root->parent = parent;
	return root;
}


// Print root in inorder (ascending order)
// input:           5
//                /   \
//				 2	   7
//				/ \	  / \
//			   1   3  6  8
//					\     \
//                   4     9
// output = 1,2,3,4,5,6,7,8,9
void inOrder(node *root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		cout << root->key << " ";
		inOrder(root->right);
	}
}

// Print level order traversal
// input:           5
//                /   \
//				 2	   7
//				/ \	  / \
//			   1   3  6  8
//					\     \
//                   4     9
// output:
//5
//2 7
//1 3 6 8
//4 9
void printBFS(node* root)
{
	list<node*> l1;
	list<node*> l2;
	l1.push_back(root);
	cout << endl;
	while (!l1.empty() || !l2.empty())
	{
		while (!l1.empty())
		{
			node * qFront = l1.front();
			l1.pop_front();
			cout << qFront->key << " ";
			if (qFront->left != NULL)
				l2.push_back(qFront->left);
			if (qFront->right != NULL)
				l2.push_back(qFront->right);
		}
		cout << endl;
		while (!l2.empty())
		{
			node * qFront = l2.front();
			l2.pop_front();
			cout << qFront->key << " ";
			if (qFront->left != NULL)
				l1.push_back(qFront->left);
			if (qFront->right != NULL)
				l1.push_back(qFront->right);
		}
		cout << endl;
	}
}

//Get the left most child
node* leftMostChild(node * root)
{
	if (root->left == NULL)
		return root;
	return leftMostChild(root->left);
}


// Find the next  in-order successor of a given node in BST
node * findSuccessor(node* root)
{
	if (root == NULL)
		return NULL;
	if (root->right != NULL)
	{
		return leftMostChild(root->right);
	}
	node* parent = root->parent;
	node* current = root;
	while (parent != NULL && parent->left != current)
	{
		current = parent;
		parent = current->parent;
	}
	return parent;
}



int main(int argc, char* argv[])
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	node* root = createTree(arr, 0, 8, NULL);
	cout << "inorder :" << endl;
	inOrder(root);
	cout << "BFS :" << endl;
	printBFS(root);

	node * successor = findSuccessor(root);
	cout << "successor of 5: " << successor->key << endl;
	successor = findSuccessor(root->left);
	cout << "successor of 2: " << successor->key << endl;
	successor = findSuccessor(root->right);
	cout << "successor of 7: " << successor->key << endl;
	successor = findSuccessor(root->left->left);
	cout << "successor of 1: " << successor->key << endl;
	successor = findSuccessor(root->left->right->right);
	cout << "successor of 4: " << successor->key << endl;
	successor = findSuccessor(root->right->right->right);
	if(successor == NULL)
		cout << "successor of 9: " << successor << endl;

}



/* Output:
inorder :
1 2 3 4 5 6 7 8 9 BFS :

5
2 7
1 3 6 8
4 9
successor of 5: 6
successor of 2: 3
successor of 7: 8
successor of 1: 2
successor of 4: 5
successor of 9: 00000000
Press any key to continue . . .
*/