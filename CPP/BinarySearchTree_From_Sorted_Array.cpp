// Create Tree from sorted array and perform DFS andBFS
#include<iostream>
#include<list>
using namespace std;
typedef struct tree{
	int key;
	tree* right;
	tree* left;
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
node* createTree(int arr[], int s, int e)
{
	if (e < s)
	{
		return NULL;
	}
	int mid = (e + s) / 2;
	node * root = new node;
	root->key = arr[mid];
	root->left = createTree(arr, s, mid - 1);
	root->right = createTree(arr, mid + 1, e);
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
void printBFS (node* root)
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
int main(int argc, char* argv[])
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	node* root = createTree(arr, 0, 8);
	cout << "inorder :" << endl;
	inOrder(root);
	cout << "BFS :" << endl;
	printBFS(root);
}



/* Output:
inorder :
1 2 3 4 5 6 7 8 9 BFS :

5
2 7
1 3 6 8
4 9
*/