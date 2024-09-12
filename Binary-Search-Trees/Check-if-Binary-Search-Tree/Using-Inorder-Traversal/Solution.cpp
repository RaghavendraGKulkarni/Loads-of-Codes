// Include the required header files
#include<iostream>
#include<fstream>
#include<sstream>
#include<stack>
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
Name        : inOrderCheckBST()
Description : Checks whether a binary tree is a BST or not using Inorder traversal
Arguments   : The pointer to the root node of the tree
Return      : "Yes" if the tree is a BST and "No" otherwise
*/
string inOrderCheckBST(TreeNode* root) {
    
    // Declare and initialize the required local variables
    vector<int> traversal;
    stack<TreeNode*> st;
    TreeNode *cur = root;

    // Peform the Inorder traversal iteratively
    while(cur || !st.empty()) {
        if(cur) {
            st.push(cur);
            cur = cur->left;
        }
        else {
            cur = st.top();
            traversal.push_back(st.top()->data);
            cur = st.top()->right;
            st.pop();
        }
    }

    // Handle base case of null tree and single element tree
    if(traversal.size() < 2)
        return "Yes";
    
    // Check for non-decreasing property in the traversal
    for(int i = 1; i < traversal.size(); i++)
        if(traversal[i] < traversal[i - 1])
            return "No";

    // Return the result
    return "Yes";
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
    string result = inOrderCheckBST(root);

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