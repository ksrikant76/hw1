#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr L;

  //make a new tail node
  for (int i = 0; i < ARRSIZE + 4; ++i) {
    L.push_back(std::to_string(i));
  }

  //make a new head node
  for (int i = 0; i < ARRSIZE + 3; ++i) {
    L.push_front(std::to_string(i));
  }

  std::cout << "front = " << L.front() << std::endl;
  std::cout << "back = " << L.back() << std::endl;

  //pop_back across a boundary
  for (int i = 0; i < ARRSIZE + 1; ++i) {
    L.pop_back();
  }

  std::cout << "back now = " << L.back() << std::endl;

  //pop_front across a boundary
  for (int i = 0; i < ARRSIZE; ++i) {
    L.pop_front();
  }

  std::cout << "front now = " << L.front() << std::endl;

}
