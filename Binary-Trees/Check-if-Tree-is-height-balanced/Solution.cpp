// Include the required header files
#include<iostream>
#include<fstream>
#include<sstream>
#include<queue>
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
Name        : buildTree()
Description : Builds a Tree from the given input string
Arguments   : A pointer to the root node and the input string, in that order
Return      : The pointer to the root node
*/
TreeNode* buildTree(TreeNode* root, string input) {
    
    // Initialize the required local variables
    stringstream stream(input);
    queue<TreeNode*> next;
    string node;

    // Scan the string stream and build the tree
    stream >> node;
    if(node == "null")
        return NULL;
    root = new TreeNode(stoi(node));
    next.push(root);
    while(!next.empty()) {
        TreeNode *cur = next.front();
        next.pop();
        stream >> node;
        if(node == "null")
            cur->left = NULL;
        else {
            cur->left = new TreeNode(stoi(node));
            next.push(cur->left);
        }
        stream >> node;
        if(node == "null")
            cur->right = NULL;
        else {
            cur->right = new TreeNode(stoi(node));
            next.push(cur->right);
        }
    }

    // Return the root node pointer
    return root;
}

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
Name        : height()
Description : Computes the height of the binary tree
Arguments   : The pointer to the root node of the tree
Return      : An integer denoting the height of the tree
*/
int height(TreeNode *root) {

    // Handle the base case of null tree
    if(!root)
        return 0;
    
    // Find the subtree heights and return the max after subtracting the sub
    return 1 + max(height(root->left), height(root->right));
}

/*
Name        : isBalanced()
Description : Checks if the binary tree is height balanced
Arguments   : The pointer to the root node of the tree
Return      : True if the tree is height balanced and False otherwise
*/
bool isBalanced(TreeNode *root) {

    // Handle the base case of null tree
    if(!root)
        return true;
    
    // Check if the child trees are balanced
    if(!isBalanced(root->left))
        return false;
    if(!isBalanced(root->right))
        return false;
    
    // Compute the left and right subtree and heights and check for balance
    int l = height(root->left), r = height(root->right);
    return (abs(r - l) <= 1);
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
    string nodes;
    TreeNode *root = NULL;
    getline(input, nodes);
    root = buildTree(root, nodes);

    // Close the input file
    input.close();

    // Call the subroutine to check if the binary tree is balanced
    bool result = isBalanced(root);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    (result) ? (output << "Yes") : (output << "No");

    // Delete the Tree, close the output file and return
    root = deleteTree(root);
    output.close();
    return 0;
}