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
Name        : reverse()
Description : Reverses the link of a node in the linked list
Arguments   : Pointer to the node and a pointer to store the new head, in that order
Return      : Pointer to the modified node
*/
ListNode* reverse(ListNode* node,ListNode** newhead) {
    
    // Handle the base case
    if(node->next == NULL)
        *newhead = node;
    
    // Reverse the next nodes
    else
        reverse(node->next, newhead)->next = node;
    
    // Return the modified node
    return node;
}

/*
Name        : recursiveReverseLinkedList()
Description : Reverses the linked list recursively
Arguments   : Pointer to the head of the linked list
Return      : Pointer to the head of the reversed linked list
*/
ListNode* recursiveReverseLinkedList(ListNode* head) {
    
    // Declare the required local variables
    ListNode *node, *newhead;

    // Recursively reverse the list
    node = reverse(head, &newhead);

    // Point the next of old head to NULL and return the new head
    node->next = NULL;
    return newhead;
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

    // Call the subroutine to reverse the linked list
    head = recursiveReverseLinkedList(head);

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