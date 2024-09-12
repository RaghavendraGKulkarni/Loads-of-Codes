// Include the required header files
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
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
Name        : inOrder()
Description : Performs Inorder Traversal on a tree recursively
Arguments   : The pointer to the root node of the tree and a vector to store the tarversal, in that order
Return      : None
*/
void inOrder(TreeNode *root, vector<int> &traversal) {
    
    // Handle the base case of null tree
    if(!root)
        return;
    
    // Perform preorder traversal
    inOrder(root->left, traversal);
    traversal.push_back(root->data);
    inOrder(root->right, traversal);

    // Return
    return;
}

/*
Name        : insert()
Description : Inserts a node with given key in a binary search tree, recursively
Arguments   : The pointer to the root node of the tree and the key, in that order
Return      : The pointer to the root of the modified tree
*/
TreeNode* insert(struct TreeNode* root, int key) {
    
    // Handle the base case of null tree
    if(!root)
        return new TreeNode(key);
    
    // Check if key already exists
    if(root->data == key)
        return root;
    
    // Compare current node value to key and move left or right accordingly
    if(root->data < key)
        root->right = insert(root->right, key);
    else
        root->left = insert(root->left, key);
    
    // Return the root
    return root;
}

/*
Name        : recursiveInsert()
Description : Initiates the recursion to insert a node with given key in a binary search tree
Arguments   : The pointer to the root node of the tree and the key, in that order
Return      : A vector denoting the Inorder traversal of the modified tree
*/
vector<int> recursiveInsert(TreeNode* root, int key) {
    
    // Declare the required local variables
    vector<int> traversal;

    // Initiate the recursion to insert the new node, if it does not exist
    root = insert(root, key);

    // Perform Inorder traversal on the modified tree
    inOrder(root, traversal);

    // Return the Inorder traversal
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
    string nodes;
    int key;
    TreeNode *root = NULL;
    getline(input, nodes);
    root = buildTree(root, nodes);
    input >> key;

    // Close the input file
    input.close();

    // Call the subroutine to insert the node value
    vector<int> result = recursiveInsert(root, key);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < result.size(); i++)
        (i == 0) ? (output << result[i]) : (output << ' ' << result[i]);

    // Delete the Tree, close the output file and return
    root = deleteTree(root);
    output.close();
    return 0;
}