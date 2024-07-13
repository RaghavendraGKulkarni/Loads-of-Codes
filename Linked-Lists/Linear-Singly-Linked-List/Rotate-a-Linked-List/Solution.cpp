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
Name        : rotateList()
Description : Rotates the list either left or right by k units
Arguments   : Pointer to the head of the linked list
Return      : Pointer to the head of the modified linked list
*/
ListNode* rotateList(ListNode *head, int dir, int k) {
   
    // Handle the case of only one element
    if(!head->next)
        return head;
    
    // Compute the size of the linked list
    ListNode *cur = head;
    int count = 1;
    while(cur->next) {
        cur = cur->next;
        count++;
    }

    // Handle redundant rotations
    k = k % count;
    
    // Convert the left rotation problem to right rotation
    if(dir == -1) {
        k = (count - k) % count;
    }

    // Handle zero rotation case
    if(k == 0)
        return head;

    // Right rotate the list by required units
    ListNode *newHead = head, *prev = NULL;
    while(count > k) {
        prev = newHead;
        newHead = newHead->next;
        count--;
    }
    cur = newHead;
    while(cur->next)
        cur = cur->next;
    cur->next = head;
    prev->next = NULL;

    // Return the head of the modified list
    return newHead;
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
    int n, k, dir, data;
    input >> n >> dir >> k;
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

    // Call the subroutine to find the rotate the linked list
    head = rotateList(head, dir, k);

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