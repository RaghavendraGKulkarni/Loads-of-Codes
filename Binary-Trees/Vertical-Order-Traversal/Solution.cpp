// Include the required header files
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
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
Name        : verticalOrder()
Description : Performs Vertical Order Traversal on a tree
Arguments   : The pointer to the root node of the tree
Return      : A vector denoting the traversal
*/
vector<int> verticalOrder(TreeNode *root) {
    
    // Declare and initialize the required local variables
    vector<int> traversal;
    map<int, map<int, multiset<int>>> mp;
    queue<pair<TreeNode*, pair<int, int>>> next;

    // Handle the base case of null tree
    if(!root)
        return traversal;
    
    // Push the root node to queue and start the traversal
    next.push({root, {0, 0}});
    while(!next.empty()) {
        auto ele = next.front();
        next.pop();
        TreeNode *cur = ele.first;
        int vert = ele.second.first, hori = ele.second.second;
        mp[vert][hori].insert(cur->data);
        if(cur->left)
            next.push({cur->left, {vert - 1, hori + 1}});
        if(cur->right)
            next.push({cur->right, {vert + 1, hori + 1}});
    }
    for(auto &it : mp) {
        vector<int> column;
        for(auto &node : it.second)
            column.insert(column.end(), node.second.begin(), node.second.end());
        for(auto &elements : column)
            traversal.push_back(elements);
    }

    // Return the traversal
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
    TreeNode *root = NULL;
    getline(input, nodes);
    root = buildTree(root, nodes);

    // Close the input file
    input.close();

    // Call the subroutine to compute the vertical order traversal
    vector<int> result = verticalOrder(root);

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