// Include the required header files
#include<iostream>
#include<fstream>
#include<unordered_map>
#include<vector>
using namespace std;

// Define the class LRUCache
class LRUCache {

    // Declare the private variables
    private:
        typedef struct node {
            int key;
            int value;
            struct node *next;
            struct node *prev;
            node(int k, int v) {
                key = k;
                value = v;
                next = NULL;
                prev = NULL;
            }
        }node;
        node *head;
        node *tail;
        int size;
        int capacity;
        unordered_map<int, node*> mp;
    
    // Define the public constructor and methods
    public:

        // Define the class constrcutor
        LRUCache(int capacity) {
            size = 0;
            this->capacity = capacity;
            head = NULL;
            tail = NULL;
        }
        
        // Define the get method
        int get(int key) {

            // Check if the key exists
            if(mp.find(key) == mp.end())
                return -1;
            
            // Relocate the corresponding node according to order of access
            node *cur = mp[key];
            if(cur->next == NULL)
                return cur->value;
            if(cur == head)
                head = head->next;
            if(cur->prev)
                (cur->prev)->next = cur->next;
            if(cur->next)
                (cur->next)->prev = cur->prev;
            cur->prev = tail;
            tail->next = cur;
            cur->next = NULL;
            tail = cur;

            // Return the mapped value
            return cur->value;
        }
        
        // Define the put method
        void put(int key, int value) {

            // If the key already exists, update the value
            if(mp.find(key) != mp.end()) {
                mp[key]->value = value;
                int value = get(key);
                return;
            }

            // If the key does not exist, add it to the cache
            node *cur = new node(key, value);
            mp.insert({key, cur});
            if(!head) {
                head = cur;
                tail = cur;
            }
            else {
                tail->next = cur;
                cur->prev = tail;
                tail = cur;
            }
            size++;

            // If overflow, remove the least recently accessed key
            if(size > this->capacity) {
                node *temp = head;
                head = head->next;
                mp.erase(temp->key);
                head->prev = NULL;
                delete temp;
                size--;
            }
            return;
        }
};

/*
Name        : process()
Description : Processes each query on the LRUCache data structure
Arguments   : A positive integer denoting the capacity, and a 2D vector denoting the queries, in that order
Return      : A vector of the outputs
*/
vector<int> process(int capacity, vector<vector<int>> queries) {
    
    // Initialize the required local variables
    LRUCache cache = LRUCache(capacity);
    vector<int> result;

    // Process the queries
    for(auto &query : queries) {
        
        // Select the operation
        switch(query[0]) {
            case 1:cache.put(query[1], query[2]);
                    break;
            case 2:result.push_back(cache.get(query[1]));
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
    int n, q, op, k, v;
    input >> n >> q;
    vector<vector<int>> queries(q);
    for(int i = 0; i < q; i++) {
        input >> op >> k;
        queries[i].push_back(op);
        queries[i].push_back(k);
        if(op == 1) {
            input >> v;
            queries[i].push_back(v);
        }
    }

    // Close the input file
    input.close();

    // Call the subroutine to process the queries
    vector<int> result = process(n, queries);

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