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
Name        : allTraversals()
Description : Performs all Three Traversals on a tree in a single pass
Arguments   : The pointer to the root node of the tree
Return      : A 2D vector denoting the traversals
*/
vector<vector<int>> allTraversals(TreeNode *root) {
    
    // Declare and initialize the required local variables
    vector<vector<int>> traversals(3, vector<int>());
    stack<pair<TreeNode*, int>> st;

    // Handle the base case of null tree
    if(!root)
        return traversals;
    
    // Push the root node to stack and start the traversals
    st.push({root, 1});
    while(!st.empty()) {
        auto it = st.top();
        st.pop();
        switch(it.second) {
            case 1:traversals[0].push_back(it.first->data);
                    it.second = 2;
                    st.push(it);
                    if(it.first->left)
                        st.push({it.first->left, 1});
                    break;
            case 2:traversals[1].push_back(it.first->data);
                    it.second = 3;
                    st.push(it);
                    if(it.first->right)
                        st.push({it.first->right, 1});
                    break;
            case 3:traversals[2].push_back(it.first->data);
                    break;
            default:
                    break;
        }
    }

    // Return the traversal
    return traversals;
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

    // Call the subroutine to compute all the traversals
    vector<vector<int>> result = allTraversals(root);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < result[0].size(); i++)
        (i == 0) ? (output << result[0][i]) : (output << ' ' << result[0][i]);
    output << endl;
    for(int i = 0; i < result[1].size(); i++)
        (i == 0) ? (output << result[1][i]) : (output << ' ' << result[1][i]);
    output << endl;
    for(int i = 0; i < result[2].size(); i++)
        (i == 0) ? (output << result[2][i]) : (output << ' ' << result[2][i]);

    // Delete the Tree, close the output file and return
    root = deleteTree(root);
    output.close();
    return 0;
}