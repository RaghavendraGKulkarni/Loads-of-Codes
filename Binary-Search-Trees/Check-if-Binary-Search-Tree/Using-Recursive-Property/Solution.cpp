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
Name        : check()
Description : Recursively checks whether a tree is a BST or not
Arguments   : The pointer to the root node of the tree, and two pointers to store the range of the tree, in that order
Return      : True if the tree is a BST and False otherwise
*/
bool check(TreeNode *root, long long int &max, long long int &min) {
    
    // Handle the base case of null tree
    if(!root)
        return true;
    
    // Declare the required local variables
    long long int max1 = LLONG_MIN, min1 = LLONG_MAX;

    // Check if left subtree is a BST
    if(!check(root->left, max1, min1) || max1 >= root->data)
        return false;
    
    // Record the range
    if(max < max1)
        max = max1;
    if(min > min1)
        min = min1;
    
    // Re-initialize the range variables
    max1 = LLONG_MIN;
    min1 = LLONG_MAX;

    // Check if right subtree is a BST
    if(!check(root->right, max1, min1) || min1 <= root->data)
        return false;

    // Record the range
    if(max < max1)
        max = max1;
    if(min > min1)
        min = min1;
    if(max < root->data)
        max = root->data;
    if(min > root->data)
        min = root->data;
    
    // Return true
    return true; 
}

/*
Name        : recursiveCheckBST()
Description : Initiates the recursion to check if a binary tree is a BST or not
Arguments   : The pointer to the root node of the tree
Return      : "Yes" if the tree is a BST and "No" otherwise
*/
string recursiveCheckBST(TreeNode* root) {
    
    // Declare the required local variables
    long long int max = LLONG_MIN, min = LLONG_MAX;
    
    // Initiate the recursion to check if the tree is a BST
    if(check(root, max, min))
        return "Yes";
    
    // Return the result
    return "No";
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

    // Call the subroutine to check for Binary Search Tree
    string result = recursiveCheckBST(root);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << result;

    // Delete the Tree, close the output file and return
    root = deleteTree(root);
    output.close();
    return 0;
}