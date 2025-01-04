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
Name        : computePath()
Description : Recursively traverses tree to compute all paths from root to leaves
Arguments   : The pointer to the root node, a vector to store tha path and a 2D vector to store all paths, in that order
Return      : None
*/
void computePath(TreeNode *root, vector<int> &path, vector<vector<int>> &paths) {
    
    // Handle the base case of null tree
    if(!root)
        return;
    
    // Add the root node to path
    path.push_back(root->data);

    // Detect leaf node and add the path to paths
    if(!root->left && !root->right)
        paths.push_back(path);
    
    // If an internal node, continue the recursion
    else {
        computePath(root->left, path, paths);
        computePath(root->right, path, paths);
    }

    // Pop node from path for other paths and return
    path.pop_back();
    return;
}

/*
Name        : recursiveSymmetry()
Description : Checks if a tree is symmetric with respect to its root, recursively
Arguments   : The pointer to the root node of the tree
Return      : True if symmetric and False otherwise
*/
vector<vector<int>> recursiveAllPaths(TreeNode *root) {
    
    // Declare and initialize the required local variables
    vector<vector<int>> paths;
    vector<int> path;

    // Call the recursive function to compute all paths
    computePath(root, path, paths);

    // Return the paths
    return paths;
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

    // Call the subroutine to compute all paths from root to leaves
    vector<vector<int>> result = recursiveAllPaths(root);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < result.size(); i++) {
        if(i > 0)
            output << endl;
        for(int j = 0; j < result[i].size(); j++)
            (j == 0) ? (output << result[i][j]) : (output << ' ' << result[i][j]);
    }

    // Delete the Tree, close the output file and return
    root = deleteTree(root);
    output.close();
    return 0;
}