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
Name        : add()
Description : Recursively moves in the linked list to perform addition
Arguments   : Pointer to the head of the linked list
Return      : Pointer to the head of the modified linked list
*/
int add(ListNode *head) {

    // Initialize the required local variables
    int carry = 0, sum;

    // Detect the end node and add accordingly
    if(head->next == NULL) {
        sum = (head->data) + 1;
        head->data = sum % 10;
        carry = sum / 10;
    }
    else {
        carry = add(head->next);
        sum = (head->data) + carry;
        head->data = sum % 10;
        carry = sum / 10;
    }

    // Return the new head node
    return carry;
}

/*
Name        : addOne()
Description : Adds one to the number represented by the linked list
Arguments   : Pointer to the head of the linked list
Return      : Pointer to the head of the modified linked list
*/
ListNode* addOne(ListNode *head) {

    // Initialize the required local variables
    int carry = 0;

    //Recursive function to add one
    carry = add(head);
    if(carry > 0) {
        ListNode *cur = new ListNode(carry);
        cur->next = head;
        head = cur;
    }

    // Return the new head node
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
    int n;
    char data;
    input >> n;
    ListNode *head = NULL, *tail = NULL;
    for(int i = 0; i < n; i++) {
        input >> data;
        if(!tail) {
            head = new ListNode(data - '0');
            tail = head;
        }
        else {
            tail->next = new ListNode(data - '0');
            tail = tail->next;
        }
    }

    // Close the input file
    input.close();

    // Call the subroutine to sort the linked list
    head = addOne(head);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    tail = head;
    while(tail) {
        output << tail->data;
        tail = tail->next;
    }
    
    // Delete the linked list, close the output file and return
    deleteList(head);
    output.close();
    return 0;
}