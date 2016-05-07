// Design an algorithm and write code to find the 
// first common ancestor of two nodes in a binary tree. 
// Avoid storing additional nodes in a data structure. 
// NOTE: This is not necessarily a binary search tree.
// Each node contains lisnk to its parent
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

// Find the common ancestor of a given node in BST
node * findCommonAncestor(node* n1, node* n2)
{
	if (n1 == NULL || n2 == NULL)
		return NULL;
	if (n1 == n2)
		return NULL;
	while (n1->parent != NULL || n2->parent != NULL)
	{
		if (n1->parent != NULL)
			n1 = n1->parent;
		if (n2->parent != NULL)
			n2 = n2->parent;
		if (n1 == n2)
		{
			return n1;
		}
	}
}


int main(int argc, char* argv[])
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	node* root = createTree(arr, 0, 8, NULL);
	cout << "inorder :" << endl;
	inOrder(root);
	cout << "BFS :" << endl;
	printBFS(root);

	node * ancestor = findCommonAncestor(root, root->right);
	cout << "ancestor of 5 and 7: " << ancestor->key << endl;
	ancestor = findCommonAncestor(root->left, root->right);
	cout << "ancestor of 2 and 7: " << ancestor->key << endl;
	ancestor = findCommonAncestor(root->left,root->right->right->right);
	cout << "ancestor of 2 and 9: " << ancestor->key << endl;
	ancestor = findCommonAncestor(root->left->right, root->right->left);
	cout << "ancestor of 3 and 6: " << ancestor->key << endl;
	ancestor = findCommonAncestor(root,root);
	if (ancestor == NULL)
		cout << "ancestor of 5 and 5: " << ancestor << endl;
	ancestor = findCommonAncestor(root, NULL);
	if (ancestor == NULL)
		cout << "ancestor of 5 and NULL: " << ancestor << endl;

}



/* Output:
inorder :
1 2 3 4 5 6 7 8 9 BFS :

5
2 7
1 3 6 8
4 9
ancestor of 5 and 7: 5
ancestor of 2 and 7: 5
ancestor of 2 and 9: 5
ancestor of 3 and 6: 5
ancestor of 5 and 5: 00000000
ancestor of 5 and NULL: 00000000
Press any key to continue . . .
*/