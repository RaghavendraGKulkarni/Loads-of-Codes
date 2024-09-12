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
Name        : search()
Description : Recursively traverses through the tree to find the target node and its k distance nodes
Arguments   : A pointer to the root of the binary tree, the target node value, the current distance from target node, value of k and a vector to store the k distance nodes, in that order
Return      : True if the target node was found and false otherwise
*/
bool search(TreeNode *root, int target, int &time, int &maxTime) {
    
    // Handle the base case of null tree
    if(!root)
        return false;

    // Declare the required local variables
    bool leftSide, rightSide;

    // Check if target node is found
    if(root->data == target) {
        
        // Start burning the current subtree
        maxTime = 0;
        time = 1;
        leftSide = search(root->left, target, time, maxTime);
        rightSide = search(root->right, target, time, maxTime);
        
        // Set time to -1 for parent node
        time = -1;

        // Return true
        return true;
    }

    // Check if the fire is spreading in the target node subtree
    if(time > 0) {

        // Record the time and spread fire to child nodes
        maxTime = max(maxTime, abs(time));
        time++;
        leftSide = search(root->left, target, time, maxTime);
        rightSide = search(root->right, target, time, maxTime);

        // Restore back original value of time
        time--;

        // Return true
        return true;
    }

    // Check if the fire is spreading in the ancestor or sibling part of the target node
    if(time < 0) {
        
        // Record the time and spread fire to child nodes
        maxTime = max(maxTime, abs(time));
        time--;
        leftSide = search(root->left, target, time, maxTime);
        rightSide = search(root->right, target, time, maxTime);
        
        // Restore back original value of time
        time++;

        // Return true
        return true;
    }

    // Search for target node on left subtree
    leftSide = search(root->left, target, time, maxTime);

    // If target found on left, spread the fire to right part of the subtree
    if(leftSide) {
        maxTime = max(maxTime, abs(time));
        time--;
        rightSide = search(root->right, target, time, maxTime);
        return true;
    }

    // Search for target node on right subtree
    rightSide = search(root->right, target, time, maxTime);

    // If target found on left, spread the fire to left part of the subtree
    if(rightSide) {
        maxTime = max(maxTime, abs(time));
        time--;
        leftSide = search(root->left, target, time, maxTime);
        return true;
    }

    // Return false
    return false;
    }

/*
Name        : burnTree()
Description : Computes the time taken to burn a binary tree from a target node
Arguments   : A pointer to the root of the binary tree, and the target node value, in that order
Return      : An integer denoting the time taken
*/
int burnTree(TreeNode* root, int target) {
    
    // Declare the required local variables
    int time = 0, maxTime = 0;
    
    // Initiate the recursive function to burn the tree
    bool burn = search(root, target, time, maxTime);

    // Return the time taken
    return maxTime;
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
    int target;
    TreeNode *root = NULL;
    getline(input, nodes);
    root = buildTree(root, nodes);
    input >> target;

    // Close the input file
    input.close();

    // Call the subroutine to compute the time taken to burn the tree
    int result = burnTree(root, target);

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