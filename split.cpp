/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void push_back(Node*& lst, Node* val);

void split(Node*& in, Node*& odds, Node*& evens)
{
    // final recursive call to see if all values in input list are sorted
    if (in == nullptr) {
        return;
    }
    else {
        if (in -> value % 2 == 0) { // check if the input is even
            push_back(evens, in); // calls push back fn
        }
        else { // check if the input is odd
            push_back(odds, in);
        }
    }
    Node* temp = in -> next; // creates a temp ptr to store the next input ptr to be the head of next recursive call
    in -> next = nullptr; // deletes in->next for memory sake
    split(temp, odds, evens); // recursive call with temp as new head ptr
    in = nullptr; // cleans up the last of the input ptr after all recursive calls
}

/* If you needed a helper function, write it here */
void push_back(Node*& lst, Node* val) {
    if (lst == nullptr) { // checks for empty odds or evens list & sets first ptr to input ptr
        lst = val;
        return;
    }
    if (lst -> next == nullptr) { // final recursive call to find where to append the new value
        lst -> next = val;
        return;
    }
    else {
        push_back(lst->next, val); // recursive call until we find the end of list
    }
}
