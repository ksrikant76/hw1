#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
  if (tail_ == NULL) { //linked list empty
    //make new head and tail
    tail_ = new Item();
    head_ = tail_;
  }
  else if (tail_->last == ARRSIZE) { //no room at back
    //make new tail
    Item* i = new Item();
    tail_->next = i;
    i->prev = tail_;
    tail_ = i;
  }

  //put val into the last position
  tail_->val[tail_->last] = val;
  ++tail_->last;
  ++size_;
}

void ULListStr::pop_back()
{
  if (size_ == 0) { //do nothing if empty
    return;
  }

  //remove last element
  --tail_->last;
  --size_;

  //if the Item became empty, delete it
  if (tail_->first == tail_->last) {
    Item* i = tail_;
    tail_ = tail_->prev;
    if (tail_ == NULL) { //list became empty
      head_ = NULL;
    }
    else {
      tail_->next = NULL;
    }
    delete i;
  }
}

void ULListStr::push_front(const std::string& val)
{
  if (head_ == NULL) { //linked list empty
    //make new head and tail
    head_ = new Item();
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
    tail_ = head_;
  }
  else if (head_->first == 0) { //no room at front
    //make new head
    Item* i = new Item();
    i->first = ARRSIZE;
    i->last = ARRSIZE;
    head_->prev = i;
    i->next = head_;
    head_ = i;
  }

  //put val into first position
  --head_->first;
  head_->val[head_->first] = val;
  ++size_;
}

void ULListStr::pop_front()
{
  if (size_ == 0) { //do nothing if empty
    return;
  }

  //remove first element
  ++head_->first;
  --size_;

  //if the Item became empty, delete it
  if (head_->first == head_->last) {
    Item* i = head_;
    head_ = head_->next;
    if (head_ == NULL) { //list became empty
      tail_ = NULL;
    }
    else {
      head_->prev = NULL;
    }
    delete i;
  }
}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) { //loc is invalid
    return NULL;
  }

  //go through the Items and find the string at loc
  Item* i = head_;
  while (i != NULL) {
    size_t depth = i->last - i->first; //depth of current Item's array
    if (loc < depth) { //if loc is in this array
      return const_cast<std::string*>(&(i->val[i->first + loc]));
    }
    //loc is not in this array
    loc -= depth;
    i = i->next;
  }
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
