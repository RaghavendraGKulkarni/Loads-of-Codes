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
Name        : mergeLists()
Description : Merges two sorted linked list into one sorted linked list
Arguments   : Pointer to the heads of the first and second linked list, in that order
Return      : Pointer to the head of the merged linked list
*/
ListNode* mergeLists(ListNode *head1, ListNode *head2) {

    // Initialize the required local variables
    ListNode *head, *t1, *t2, *t;

    // Manually set the head node comparing the first elements
    if(head1->data <= head2->data) {
        head = head1;
        t1 = head1->next;
        t2 = head2;
    }
    else {
        head = head2;
        t1 = head1;
        t2 = head2->next;
    }
    t = head;
    
    // Compare front elements one by one and merge
    while(t1 && t2) {
        if(t1->data <= t2->data) {
            t->next = t1;
            t1 = t1->next;
        }
        else {
            t->next = t2;
            t2 = t2->next;
        }
        t = t->next;
    }

    // Append the remaining part of the list
    if(t1)
        t->next = t1;
    else
        t->next = t2;
    
    // Return the head node of the merged list
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
    int m, n, data;
    input >> m >> n;
    ListNode *head1 = NULL, *head2 = NULL, *tail = NULL;
    for(int i = 0; i < m; i++) {
        input >> data;
        if(!tail) {
            head1 = new ListNode(data);
            tail = head1;
        }
        else {
            tail->next = new ListNode(data);
            tail = tail->next;
        }
    }
    tail = NULL;
    for(int i = 0; i < n; i++) {
        input >> data;
        if(!tail) {
            head2 = new ListNode(data);
            tail = head2;
        }
        else {
            tail->next = new ListNode(data);
            tail = tail->next;
        }
    }

    // Close the input file
    input.close();

    // Call the subroutine to merge the linked lists
    ListNode *head = mergeLists(head1, head2);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    tail = head;
    while(tail) {
        (tail == head) ? (output << tail->data) : (output << ' ' << tail->data);
        tail = tail->next;
    }
    
    // Delete the merged linked list, close the output file and return
    deleteList(head);
    output.close();
    return 0;
}