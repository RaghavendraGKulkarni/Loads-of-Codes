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
Description : Builds a Tree from the given PreOrder and Inorder traversals
Arguments   : A pointer to store the root node, the preorder traversal, and the inorder traversal, in that order
Return      : The pointer to the root node
*/
TreeNode* buildTree(TreeNode *root, vector<int>& preorder, vector<int>& inorder) {
    
    // Handle the base case of empty tree
    if(preorder.size() == 0)
        return NULL;

    // Declare and initialize the required local variables
    int n = preorder.size(), rootIndex, rootValue = preorder[0];
    root = new TreeNode(rootValue);

    // Handle the base case of single node tree
    if(n == 1)
        return root;
    
    // Find the index of the root node in the Inorder traversal
    for(rootIndex = 0; rootIndex < n; rootIndex++)
        if(inorder[rootIndex] == rootValue)
            break;
    
    // Compute the Preorder and Inorder traversals of left and right subtrees
    vector<int> preLeft, preRight, inLeft, inRight;
    for(int i = 0; i < n; i++) {
        if(i < rootIndex)
            inLeft.push_back(inorder[i]);
        else if(i > rootIndex)
            inRight.push_back(inorder[i]);
    }
    for(int i = 1; i < n; i++) {
        if(i <= inLeft.size())
            preLeft.push_back(preorder[i]);
        else
            preRight.push_back(preorder[i]);
    }

    // Recursively build the left and right subtrees
    root->left = buildTree(root->left, preLeft, inLeft);
    root->right = buildTree(root->right, preRight, inRight);

    // Return the root
    return root;
}

/*
Name        : postOrder()
Description : Performs Postorder Traversal on a tree recursively
Arguments   : The pointer to the root node of the tree and a vector to store the tarversal, in that order
Return      : None
*/
void postOrder(TreeNode *root, vector<int> &traversal) {
    
    // Handle the base case of null tree
    if(!root)
        return;
    
    // Perform preorder traversal
    postOrder(root->left, traversal);
    postOrder(root->right, traversal);
    traversal.push_back(root->data);

    // Return
    return;
}

/*
Name        : printPostorder()
Description : Computes the postorder traversal given the preorder and inorder traversals
Arguments   : The Preorder traversal and the Inorder traversal, in that order
Return      : A vector denoting the Inorder traversal
*/
vector<int> printPostorder(vector<int> preorder, vector<int> inorder) {
    
    // Build the tree using Preorder and Inorder traversals
    TreeNode *root = NULL;
    vector<int> traversal;
    root = buildTree(root, preorder, inorder);

    // Compute the Postorder traversal
    postOrder(root, traversal);

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
    vector<int> preorder(n), inorder(n);
    for(int i = 0; i < n; i++)
        input >> preorder[i];
    for(int i = 0; i < n; i++)
        input >> inorder[i];

    // Close the input file
    input.close();

    // Call the subroutine to compute the Postorder traversal
    vector<int> result = printPostorder(preorder, inorder);

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