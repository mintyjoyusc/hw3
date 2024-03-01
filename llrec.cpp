#include "llrec.h"


//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
    //base case: end of list
    if(head == NULL){
      smaller = NULL;
      larger = NULL;
      return;
    }
    Node* nextNode = head->next; // Save the next node to continue recursion

    if (head->val <= pivot) {
        // Add the current node to the smaller list
        smaller = head;
        head = head -> next;
        smaller -> next = NULL; // Point the current node to the head of the smaller list
        llpivot(head, smaller->next, larger, pivot);
       // Update the head of the smaller list to the current node
    } 
    else {
        // Add the current node to the larger list
        larger = head;
        head = head->next;
        larger->next = NULL;
    llpivot(head, smaller, larger->next, pivot);
      // Update the head of the larger list to the current node
    }


}


