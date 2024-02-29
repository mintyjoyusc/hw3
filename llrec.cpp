#include "llrec.h"


//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
    //base case: end of list
    if(head == NULL){
        return;
    }
    Node* nextNode = head->next; // Save the next node to continue recursion

    if (head->val <= pivot) {
        // Add the current node to the smaller list
        head->next = smaller; // Point the current node to the head of the smaller list
        smaller = head;       // Update the head of the smaller list to the current node
    } 
    else {
        // Add the current node to the larger list
        head->next = larger; // Point the current node to the head of the larger list
        larger = head;       // Update the head of the larger list to the current node
    }

    // Recursively process the rest of the list
    llpivot(nextNode, smaller, larger, pivot);
    
    // Ensure the original list head is nullified
    head = NULL;

}


