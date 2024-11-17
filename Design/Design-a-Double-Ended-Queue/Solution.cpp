// Include the required header files
#include<iostream>
#include<fstream>
#include<stack>
#include<vector>
using namespace std;

// Define the Queue Node
typedef struct QueueNode {
    int data;
    struct QueueNode *next;
    struct QueueNode *prev;
    QueueNode(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
}QueueNode;

// Define the class deQueue
class deQueue {

    // Declare the private variables
    private:
        QueueNode *front;
        QueueNode *rear;
        int size;
    
    // Define the public constructor and methods
    public:

        // Define the class constrcutor
        deQueue() {
            front = NULL;
            rear = NULL;
            size = 0;
        }
        
        // Define the pushFront method
        void pushFront(int value) {
            QueueNode *newNode = new QueueNode(value);
            if(front == NULL) {
                front = newNode;
                rear = newNode;
            }
            else {
                newNode->next = front;
                front->prev = newNode;
                front = newNode;
            }
            size++;
            return;
        }

        // Define the pushRear method
        void pushRear(int value) {
            QueueNode *newNode = new QueueNode(value);
            if(front == NULL) {
                front = newNode;
                rear = newNode;
            }
            else {
                newNode->prev = rear;
                rear->next = newNode;
                rear = newNode;
            }
            size++;
            return;
        }
        
        // Define the popFront method
        void popFront() {
            if(front == NULL)
                return;
            if(front == rear) {
                delete front;
                front = NULL;
                rear = NULL;
            }
            else {
                QueueNode *cur = front;
                front = front->next;
                delete cur;
            }
            size--;
            return;
        }

        // Define the popRear method
        void popRear() {
            if(rear == NULL)
                return;
            if(front == rear) {
                delete rear;
                front = NULL;
                rear = NULL;
            }
            else {
                QueueNode *cur = rear;
                rear = rear->prev;
                delete cur;
            }
            size--;
            return;
        }
        
        // Define the getFront method
        int getFront() {
            return (front == NULL) ? -1 : front->data;
        }
        
        // Define the getRear method
        int getRear() {
            return (rear == NULL) ? -1 : rear->data;
        }
};

/*
Name        : process()
Description : Processes each query on the deQueue data structure
Arguments   : A 2D vector denoting the queries
Return      : A vector of the outputs
*/
vector<int> process(vector<vector<int>> queries) {
    
    // Initialize the required local variables
    deQueue dq = deQueue();
    vector<int> result;

    // Process the queries
    for(auto &query : queries) {
        
        // Select the operation
        switch(query[0]) {
            case 1:dq.pushFront(query[1]);
                    break;
            case 2:dq.pushRear(query[1]);;
                    break;
            case 3:dq.popFront();
                    break;
            case 4:dq.popRear();
                    break;
            case 5:result.push_back(dq.getFront());
                    break;
            case 6:result.push_back(dq.getRear());
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
        if(op == 2) {
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