// Include the required header files
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

// Declare the required data types
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
}TreeNode;

/*
Name        : deleteTree()
Description : Deletes a Tree given the pointer to root node, recursively
Arguments   : A pointer to the root node of the tree to be deleted
Return      : NULL pointer
*/
TreeNode* deleteTree(TreeNode *root) {
    
    // Handle the base case
    if(!root)
        return root;
    
    // Delete the child subtrees first
    root->left = deleteTree(root->left);
    root->right = deleteTree(root->right);
    
    // Delete the root node and return NULL
    delete root;
    return NULL;
}

/*
Name        : buildTree()
Description : Builds a Tree from the given InOrder and Postorder traversals
Arguments   : A pointer to store the root node, the inorder traversal, and the postorder traversal, in that order
Return      : The pointer to the root node
*/
TreeNode* buildTree(TreeNode *root, vector<int>& inorder, vector<int>& postorder) {
    
    // Handle the base case of empty tree
    if(inorder.size() == 0)
        return NULL;

    // Declare and initialize the required local variables
    int n = inorder.size(), rootIndex, rootValue = postorder[n - 1];
    root = new TreeNode(rootValue);

    // Handle the base case of single node tree
    if(n == 1)
        return root;
    
    // Find the index of the root node in the Inorder traversal
    for(rootIndex = 0; rootIndex < n; rootIndex++)
        if(inorder[rootIndex] == rootValue)
            break;
    
    // Compute the Inorder and Postorder traversals of left and right subtrees
    vector<int> postLeft, postRight, inLeft, inRight;
    for(int i = 0; i < n; i++) {
        if(i < rootIndex)
            inLeft.push_back(inorder[i]);
        else if(i > rootIndex)
            inRight.push_back(inorder[i]);
    }
    for(int i = 0; i < n - 1; i++) {
        if(i < inLeft.size())
            postLeft.push_back(postorder[i]);
        else
            postRight.push_back(postorder[i]);
    }

    // Recursively build the left and right subtrees
    root->left = buildTree(root->left, inLeft, postLeft);
    root->right = buildTree(root->right, inRight, postRight);

    // Return the root
    return root;
}

/*
Name        : preOrder()
Description : Performs Preorder Traversal on a tree recursively
Arguments   : The pointer to the root node of the tree and a vector to store the tarversal, in that order
Return      : None
*/
void preOrder(TreeNode *root, vector<int> &traversal) {
    
    // Handle the base case of null tree
    if(!root)
        return;
    
    // Perform preorder traversal
    traversal.push_back(root->data);
    preOrder(root->left, traversal);
    preOrder(root->right, traversal);

    // Return
    return;
}

/*
Name        : printPreorder()
Description : Computes the preorder traversal given the inorder and postorder traversals
Arguments   : The Inorder traversal and the Postorder traversal, in that order
Return      : A vector denoting the Preorder traversal
*/
vector<int> printPreorder(vector<int> inorder, vector<int> postorder) {
    
    // Build the tree using Preorder and Inorder traversals
    TreeNode *root = NULL;
    vector<int> traversal;
    root = buildTree(root, inorder, postorder);

    // Compute the Preorder traversal
    preOrder(root, traversal);

    // Delete the tree and return the traversal
    root = deleteTree(root);
    return traversal;
}

/*
Name        : main()
Description : Handles I/O and calls the required subroutines
Arguments   : None
Return      : Integer 0
*/
int main() {

    // Open the input file and handle the exception
    ifstream input;
    input.open("Input.txt");
    if(input.fail()) {
        cerr << "Please provide the correct Input File...!!!" << endl;
        exit(0);
    }

    // Declare the required local variables and read the input
    int n;
    input >> n;
    vector<int> inorder(n), postorder(n);
    for(int i = 0; i < n; i++)
        input >> inorder[i];
    for(int i = 0; i < n; i++)
        input >> postorder[i];

    // Close the input file
    input.close();

    // Call the subroutine to compute the Preorder traversal
    vector<int> result = printPreorder(inorder, postorder);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < result.size(); i++)
        (i == 0) ? (output << result[i]) : (output << ' ' << result[i]);

    // Close the output file and return
    output.close();
    return 0;
}