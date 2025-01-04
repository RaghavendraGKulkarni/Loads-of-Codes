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
bool search(TreeNode *root, int target, int &distance, int k, vector<int> &result) {
    
    // Handle the base case of null tree
    if(!root)
        return false;

    // Declare the required local variables
    bool leftSide, rightSide;

    // Check if target node is found
    if(root->data == target) {
        
        // Start finding k distance node in the current subtree
        distance++;
        leftSide = search(root->left, target, distance, k, result);
        rightSide = search(root->right, target, distance, k, result);
        
        // Set distance to -1 for parent node
        distance = -1;
        
        // Return true
        return true;
    }

    // Check if the search is inside the subtree of target node
    if(distance > 0) {

        // Check if current node is at distance k
        if(distance == k)
            result.push_back(root->data);
        
        // Extend function call to child nodes by incrementing distance
        else if(distance < k) {
            distance++;
            leftSide = search(root->left, target, distance, k, result);
            rightSide = search(root->right, target, distance, k, result);

            // Restore back original value of distance
            distance--;
        }

        // Return true
        return true;
    }

    // Check if the search is in the ancestor or sibling part of the target node
    if(distance < 0) {

        // Check if current node is at distance k
        if(distance == -k)
            result.push_back(root->data);
        
        // Extend function call to child nodes by decrementing distance
        else if(distance > -k) {
            distance--;
            leftSide = search(root->left, target, distance, k, result);
            rightSide = search(root->right, target, distance, k, result);
            
            // Restore back original value of distance
            distance++;
        }

        // Return true
        return true;
    }

    // Search for target node on left subtree
    leftSide = search(root->left, target, distance, k, result);
    
    // If target found on left, search for k distance nodes on right subtree
    if(leftSide) {
        if(distance == -k) {
            result.push_back(root->data);
            distance--;
        }
        else if(distance > -k) {
            distance--;
            rightSide = search(root->right, target, distance, k, result);
        }
        return true;
    }

    // Search for target node on left subtree
    rightSide = search(root->right, target, distance, k, result);

    // If target found on right, search for k distance nodes on left subtree
    if(rightSide) {
        if(distance == -k) {
            result.push_back(root->data);
            distance--;
        }
        else if(distance > -k) {
            distance--;
            leftSide = search(root->left, target, distance, k, result);
        }
        return true;
    }

    // Return false
    return false;
}

/*
Name        : kDistanceNodes()
Description : Computes the k distance nodes from a target node in a binary tree
Arguments   : A pointer to the root of the binary tree, the target node value and value of k, in that order
Return      : A vector denoting the k distance node values
*/
vector<int> kDistanceNodes(TreeNode* root, int target, int k) {
    
    // Declare the required local variables
    vector<int> result;

    // Handle the base case of k = 0
    if(k == 0) {
        result.push_back(target);
        return result;
    }

    // Initiate the recursive function to compute k distance nodes
    int distance = 0;
    search(root, target, distance, k, result);

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
    int k, target;
    TreeNode *root = NULL;
    getline(input, nodes);
    root = buildTree(root, nodes);
    input >> target >> k;

    // Close the input file
    input.close();

    // Call the subroutine to compute the k-distance nodes
    vector<int> result = kDistanceNodes(root, target, k);

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