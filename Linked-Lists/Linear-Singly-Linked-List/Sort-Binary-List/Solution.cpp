// Include the required header files
#include<iostream>
#include<fstream>
using namespace std;

// Define the linked list data type
typedef
    struct ListNode {
        int data;
        struct ListNode *next;
        ListNode(int x) {
            data = x;
            next = NULL;
        }
    }
ListNode;

/*
Name        : sortBinaryList()
Description : Sorts the binary linked list
Arguments   : Pointer to the head of the linked list
Return      : Pointer to the head of the modified linked list
*/
ListNode* sortBinaryList(ListNode *head) {

    // Handle the base case
    if(!head->next)
        return head;
    
    // Initialize the required local variables
    ListNode *h0 = NULL, *t0 = NULL, *h1 = NULL, *t1 = NULL, *t;
    
    // Start the traverse and segregate distinct elements
    t = head;
    while(t) {

        // Select the operation based on the element value
        switch(t->data) {
            case 0:if(!t0)
                        h0 = t;
                    else
                        t0->next = t;
                    t0 = t;
                    break;
            default:if(!t1)
                        h1 = t;
                    else
                        t1->next = t;
                    t1 = t;
                    break;
        }
        t = t->next;
    }

    // Arrange the two segregated sub-lists according to the order
    head = NULL;
    if(t0) {
        head = h0;
        t0->next = h1;
    }
    if(t1) {
        if(!head)
            head = h1;
        t1->next = NULL;
    }

    // Return the head
    return head;
}

/*
Name        : deleteList()
Description : Deletes the Linked List
Arguments   : Pointer to the head of the Linked List
Return      : None
*/
void deleteList(ListNode *head) {

    // Initialize the required local variables
    ListNode *cur;

    // Loop to delete the linked list
    while(head) {
        cur = head->next;
        delete head;
        head = cur;
    }

    // Return
    return;
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
    int n, data;
    input >> n;
    ListNode *head = NULL, *tail = NULL;
    for(int i = 0; i < n; i++) {
        input >> data;
        if(!tail) {
            head = new ListNode(data);
            tail = head;
        }
        else {
            tail->next = new ListNode(data);
            tail = tail->next;
        }
    }

    // Close the input file
    input.close();

    // Call the subroutine to sort the binary linked list
    head = sortBinaryList(head);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    tail = head;
    while(tail) {
        (tail == head) ? (output << tail->data) : (output << ' ' << tail->data);
        tail = tail->next;
    }
    
    // Delete the linked list, close the output file and return
    deleteList(head);
    output.close();
    return 0;
}