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
Name        : find()
Description : Recursively finds the kth smallest element in a binary search tree
Arguments   : The pointer to the root node of the tree, an integer denoting current index to in search, a double pointer to stre the result, and the value of k, in that order
Return      : None
*/
void find(TreeNode *root, int &place, TreeNode **result, int k) {
    
    // Check if the kth smallest element is already found
    if(place > k)
        return;
    
    // Handle the base case of null tree
    if(!root)
        return;
    
    // Search for smaller elements in left subtree
    find(root->left, place, result, k);

    // Record the current element
    if(place <= k) {
        (*result) = root;
        place++;
    }

    // Search for smaller elements in right subtree
    find(root->right, place, result, k);

    // Return
    return;
}

/*
Name        : kthSmallest()
Description : Initiates the recursion to find the kth smallest element in a binary search tree
Arguments   : The pointer to the root node of the tree and the value of k, in that order
Return      : A pointer to the kth smallest element node
*/
TreeNode* kthSmallest(TreeNode* root, int k) {
    
    // Declare the required local variables
    int place = 1;
    TreeNode *result = NULL;

    // Initiate the recursion to find the kth smallest element
    find(root, place, &result, k);
    
    // Return the result
    return result;
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
    int k;
    TreeNode *root = NULL;
    getline(input, nodes);
    root = buildTree(root, nodes);
    input >> k;

    // Close the input file
    input.close();

    // Call the subroutine to find the kth smallest
    TreeNode* result = kthSmallest(root, k);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    (result) ? (output << result->data) : (output << "None");

    // Delete the Tree, close the output file and return
    root = deleteTree(root);
    output.close();
    return 0;
}