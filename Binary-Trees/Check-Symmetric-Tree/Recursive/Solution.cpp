// Include the required header files
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<queue>
#include<stack>
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
Name        : isMirror()
Description : Checks if one tree is mirror of another tree or not
Arguments   : The pointer to the root nodes of the first and second tree, in that order
Return      : True if mirror and False otherwise
*/
bool isMirror(TreeNode *root1, TreeNode *root2) {
    
    // Check if both are null trees
    if(!root1 && !root2)
        return true;
    
    // Check if exactly one is null tree
    if((!root1 && root2) || (root1 && !root2))
        return false;
    
    // Check if child trees are mirror images or not
    if(!isMirror(root1->left, root2->right))
        return false;
    if(!isMirror(root1->right, root2->left))
        return false;
    
    // Check if the node values are equal or not
    return (root1->data == root2->data);
}

/*
Name        : recursiveSymmetry()
Description : Checks if a tree is symmetric with respect to its root, recursively
Arguments   : The pointer to the root node of the tree
Return      : True if symmetric and False otherwise
*/
bool recursiveSymmetry(TreeNode *root) {
    
    // Handle the base case of null tree
    if(!root)
        return true;

    // Call the recursive function to check symmetry
    return isMirror(root->left, root->right);
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

    // Call the subroutine to check the symmetry
    bool result = recursiveSymmetry(root);

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