#include <iostream>
using namespace std;
// Define a structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to create a sample binary tree
TreeNode* createBinaryTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

// Function to perform an in-order traversal of the binary tree
void inOrderTraversal(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    inOrderTraversal(node->left);
   cout << node->data << " ";
    inOrderTraversal(node->right);
}


	
		
	




	
