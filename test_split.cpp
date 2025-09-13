/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>

void printList(Node* head) {
  if (head == NULL) {
    std::cout << std::endl;
    return;
  }
  else {
    std::cout << head->value << " ";
    printList(head->next);
  }
}

int main(int argc, char* argv[])
{
  //Test 1: empty input
  Node* in1 = NULL;
  Node* odds1 = NULL;
  Node* evens1 = NULL;
  split(in1, odds1, evens1);
  std::cout << "Odds: ";
  printList(odds1);
  std::cout << "Evens: ";
  printList(evens1);
  std::cout << "In: ";
  printList(in1);

  //Test 2: odds and evens
  Node* six = new Node(6, NULL);
  Node* five = new Node(5, six);
  Node* four = new Node(4, five);
  Node* three = new Node(3, four);
  Node* two = new Node(2, three);
  Node* one = new Node(1, two);

  Node* in2 = one;
  Node* odds2 = NULL;
  Node* evens2 = NULL;
  split(in2, odds2, evens2);
  std::cout << "Odds: ";
  printList(odds2);
  std::cout << "Evens: ";
  printList(evens2);
  std::cout << "In: ";
  printList(in2);

  //Test 3: only odds
  one->next = three;
  three->next = five;
  five->next = NULL;
  Node* in3 = one;
  Node* odds3 = NULL;
  Node* evens3 = NULL;
  split(in3, odds3, evens3);
  std::cout << "Odds: ";
  printList(odds3);
  std::cout << "Evens: ";
  printList(evens3);
  std::cout << "In: ";
  printList(in3);
}
