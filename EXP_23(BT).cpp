#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node {
public:
	int data;
	node* left;
	node* right;
};

/* Compute the "maxDepth" of a tree -- the number of
	nodes along the longest path from the root node
	down to the farthest leaf node.*/
int maxDepth(node* node)
{
	if (node == NULL)
		return 0;
	else {
		/* compute the depth of each subtree */
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);

		/* use the larger one */
		if (lDepth > rDepth)
			return (lDepth + 1);
		else
			return (rDepth + 1);
	}
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

// Driver code
int main()
{
	node* root = newNode(1);

	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Height of tree is " << maxDepth(root);
	return 0;
}
//Diameter
#include <bits/stdc++.h>
using namespace std;

// A binary tree node has data, pointer to left child
// and a pointer to right child
struct node {
	int data;
	struct node *left, *right;
};

// function to create a new node of tree and returns pointer
struct node* newNode(int data);

// returns max of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// function to Compute height of a tree.
int height(struct node* node);

// Function to get diameter of a binary tree
int diameter(struct node* tree)
{
	// base case where tree is empty
	if (tree == NULL)
		return 0;

	// get the height of left and right sub-trees
	int lheight = height(tree->left);
	int rheight = height(tree->right);

	// get the diameter of left and right sub-trees
	int ldiameter = diameter(tree->left);
	int rdiameter = diameter(tree->right);

	// Return max of following three
	// 1) Diameter of left subtree
	// 2) Diameter of right subtree
	// 3) Height of left subtree + height of right subtree +
	// 1
	return max(lheight + rheight + 1,
			max(ldiameter, rdiameter));
}

// UTILITY FUNCTIONS TO TEST diameter() FUNCTION

// The function Compute the "height" of a tree. Height is
// the number f nodes along the longest path from the root
// node down to the farthest leaf node.
int height(struct node* node)
{
	// base case tree is empty
	if (node == NULL)
		return 0;

	// If tree is not empty then height = 1 + max of left
	// height and right heights
	return 1 + max(height(node->left), height(node->right));
}

// Helper function that allocates a new node with the
// given data and NULL left and right pointers.
struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

// Driver Code
int main()
{

	
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	// Function Call
	cout << "Diameter of the given binary tree is "
		<< diameter(root);

	return 0;
}
//LCA
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree node
struct Node {
	int key;
	struct Node *left, *right;
};

// Utility function creates a new binary tree node with
// given key
Node* newNode(int k)
{
	Node* temp = new Node;
	temp->key = k;
	temp->left = temp->right = NULL;
	return temp;
}

// Finds the path from root node to given root of the tree,
// Stores the path in a vector path[], returns true if path
// exists otherwise false
bool findPath(Node* root, vector<int>& path, int k)
{
	// base case
	if (root == NULL)
		return false;

	// Store this node in path vector. The node will be
	// removed if not in path from root to k
	path.push_back(root->key);

	// See if the k is same as root's key
	if (root->key == k)
		return true;

	// Check if k is found in left or right sub-tree
	if ((root->left && findPath(root->left, path, k))
		|| (root->right && findPath(root->right, path, k)))
		return true;

	// If not present in subtree rooted with root, remove
	// root from path[] and return false
	path.pop_back();
	return false;
}

// Returns LCA if node n1, n2 are present in the given
// binary tree, otherwise return -1
int findLCA(Node* root, int n1, int n2)
{
	// to store paths to n1 and n2 from the root
	vector<int> path1, path2;

	// Find paths from root to n1 and root to n2. If either
	// n1 or n2 is not present, return -1
	if (!findPath(root, path1, n1)
		|| !findPath(root, path2, n2))
		return -1;

	/* Compare the paths to get the first different value */
	int i;
	for (i = 0; i < path1.size() && i < path2.size(); i++)
		if (path1[i] != path2[i])
			break;
	return path1[i - 1];
}

// Driver program to test above functions
int main()
{
	// Let us create the Binary Tree shown in above diagram.
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
	cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
	cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
	cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
	return 0;
}
