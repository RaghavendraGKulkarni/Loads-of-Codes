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
Name        : iterativeSymmetry()
Description : Checks if a tree is symmetric with respect to its root, iteratively
Arguments   : The pointer to the root node of the tree
Return      : True if symmetric and False otherwise
*/
bool iterativeSymmetry(TreeNode *root) {
    
    // Handle the base case of null tree
    if(!root)
        return true;

    // Declare and initialize the required local variables
    stack<TreeNode*> s1, s2;
    TreeNode *node1, *node2;
    s1.push(root->left);
    s2.push(root->right);
    bool symmetric = true;

    // Traverse the tree to check for symmetry
    while(symmetric && !s1.empty() && !s2.empty()) {
        node1 = s1.top();
        s1.pop();
        node2 = s2.top();
        s2.pop();
        if(!node1 && !node2)
            continue;
        if((!node1 && node2) || (node1 && !node2))
            symmetric = false;
        else if(node1->data != node2->data)
            symmetric = false;
        else {
            s1.push(node1->right);
            s1.push(node1->left);
            s2.push(node2->left);
            s2.push(node2->right);
        }
    }

    // Return the symmetric status
    return symmetric;
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
    bool result = iterativeSymmetry(root);

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