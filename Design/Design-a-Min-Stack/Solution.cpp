// Include the required header files
#include<iostream>
#include<fstream>
#include<stack>
#include<vector>
using namespace std;

// Define the class minStack
class minStack {

    // Declare the private variables
    private:
        stack<long long int> st;
        long long int min;
    
    // Define the public constructor and methods
    public:

        // Define the class constrcutor
        minStack() {
            while(!st.empty())
                st.pop();
            min = LLONG_MAX;
        }
        
        // Define the push method
        void push(int val) {
            if(st.empty()) {
                min = val;
                st.push(val);
            }
            else if(val < min) {
                st.push(2*(val*1LL) - min);
                min = val;
            }
            else
                st.push(val);
            return;
        }
        
        // Define the pop method
        void pop() {
            if(st.empty())
                return;
            long long int ele = st.top();
            st.pop();
            if(ele < min)
                min = 2 * min - ele;
            return;
        }
        
        // Define the top method
        int top() {
            long long ele = st.top();
            if(ele < min)
                return min;
            return ((int)ele);
        }
        
        // Define the getMin method
        int getMin() {
            return ((int)min);
        }
};

/*
Name        : process()
Description : Processes each query on the minStack data structure
Arguments   : A 2D vector denoting the queries
Return      : A vector of the outputs
*/
vector<int> process(vector<vector<int>> queries) {
    
    // Initialize the required local variables
    minStack st = minStack();
    vector<int> result;

    // Process the queries
    for(auto &query : queries) {
        
        // Select the operation
        switch(query[0]) {
            case 1:st.push(query[1]);
                    break;
            case 2:st.pop();
                    break;
            case 3:result.push_back(st.top());
                    break;
            case 4:result.push_back(st.getMin());
                    break;
            default:
                    break;
        }
    }

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

    // Declare the required variables and read the input
    int n, op, x;
    input >> n;
    vector<vector<int>> queries(n);
    for(int i = 0; i < n; i++) {
        input >> op;
        queries[i].push_back(op);
        if(op == 1) {
            input >> x;
            queries[i].push_back(x);
        }
    }

    // Close the input file
    input.close();

    // Call the subroutine to process the queries
    vector<int> result = process(queries);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    for(int i = 0; i < result.size(); i++)
        (i == 0) ? (output << result[i]) : (output << endl << result[i]);
    
    // Close the output file and return
    output.close();
    return 0;
}