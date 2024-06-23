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
Name        : middleNode()
Description : Finds the middle node of a linked list
Arguments   : Pointer to the head of the linked list
Return      : Pointer to the middle node of the linked list
*/
ListNode* middleNode(ListNode *head) {
   
    // Initialize the required local variables
    ListNode *slow = head, *fast = head;

    // Loop to find the middle node
    while(fast && fast->next) {
        fast = fast->next;
        if(fast)
            fast = fast->next;
        if(fast)
            slow = slow->next;
    }

    // Return the middle node of the linked list
    return slow;
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

    // Call the subroutine to find the middle node of the linked list
    ListNode* middle = middleNode(head);

    // Open the output file
    ofstream output;
    output.open("Output.txt");

    // Write the output to the output file
    output << middle->data;
    
    // Delete the linked list, close the output file and return
    deleteList(head);
    output.close();
    return 0;
}