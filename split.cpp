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

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  if (in == NULL) { //base case
    return;
  }

  Node* current = in; //first node
  split(in->next, odds, evens); //recurse to tail, then move backwards

  if ( (current->value % 2) == 0) { //if current value is even
    //add to front of evens
    current->next = evens;
    evens = current;
  }
  else { //if current value is odd
    //add to front of odds
    current->next = odds;
    odds = current;
  }

  in = NULL; //clear original list nodes
}

/* If you needed a helper function, write it here */
