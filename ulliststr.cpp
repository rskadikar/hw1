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
    if (empty()) { // checks if there are any items & creates a new one if not
        head_ = tail_ = new Item();
        head_ -> val[0] = val;
        head_ -> last = 1;
    }
    else if (tail_ -> last == ARRSIZE) { // if the array doesn't have anymore room at the back, create a new item and link it to the current
        Item* newItem = new Item();
        newItem -> prev = tail_;
        tail_ -> next = newItem;
        tail_ = newItem;
        tail_ -> val[0] = val;
        tail_ -> last = 1;
    }
    else { // if not either of the previous scenarios, simply add the value in the current array
        tail_ -> val[tail_ -> last] = val;
        tail_ -> last += 1;
    }
    size_++;
}

void ULListStr::pop_back()
{
    if (empty()) { // if no items/arrays, nothing to pop so return immediately
        return;
    }
    else if (tail_ -> last == 1) { // if only one item at the front of an array in the tail item, delete the tail item and reorganize
        Item* tailStore = tail_;
        if (tail_ -> prev == NULL) {
            tail_ = head_ = NULL;
        }
        else {
            tail_ = tail_ -> prev;
            tail_ -> next = NULL;
        }
        delete tailStore;
    }
    else { // otherwise, move the last value to the left by decrementing the number by 1
        tail_-> last--;
    }
    size_--; // decrement size regardless
}

void ULListStr::push_front(const std::string& val)
{
    if (empty()) { // checks if there are any items & creates a new one if not
        head_ = tail_ = new Item();
        head_ -> val[0] = val;
        head_ -> last = 1;
    }
    else if (head_ -> first == 0) { // if the array doesn't have anymore room at the front, create a new item and link it to the current
        Item* newItem = new Item();
        newItem -> next = head_;
        head_ -> prev = newItem;
        head_ = newItem;
        head_ -> val[ARRSIZE - 1] = val;
        head_ -> last = ARRSIZE;
        head_ -> first = ARRSIZE - 1;
    }
    else { // if not either of the previous scenarios, simply add the value in the current array
        head_ -> val[head_ ->first - 1] = val;
        head_ -> first -= 1;
    }
    size_++; // increment size regardless
}

void ULListStr::pop_front()
{
    if (empty()) { // if no items/arrays, nothing to pop so return immediately
        return;
    }
    else if (head_ -> first == head_-> last - 1) { // if only one item at the back of an array in the head item, delete the head item and reorganize
        Item* headStore = head_;
        if (head_ -> next == NULL) {
            tail_ = head_ = NULL;
        }
        else {
            head_ = head_ -> next;
            head_ -> prev = NULL;
        }
        delete headStore;
    }
    else {
        head_ -> first++; // otherwise, move the first value to the right by incrementing the number by 1
    }
    size_--; // decrement size regardless
}

std::string const & ULListStr::back() const
{
    if (empty()) { // checks if there is an item at all
        return NULL;
    }
    return tail_ -> val[tail_ -> last - 1]; // returns the last item of the tail
}

std::string const & ULListStr::front() const
{
    if (empty()) { // checks if there's an item at all
        return NULL;
    }
    return head_ -> val[head_ -> first]; // returns the first item of the head
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
    if (loc >= size_) { // checks for an invalid loc by seeing if it's larger than the size_
        return NULL;
    }
    else {
        Item* temp = head_;
        int ct = 0; // counts how far we've gone in the array
        while (temp != NULL) {
            int current_ct = temp -> last - temp -> first; // calculates how many spots filled in each item
            if (loc < (ct + current_ct)) { // checks if the location is within the current item
                int array_loc = temp -> first + (loc - ct);
                return &(temp -> val[array_loc]); // returns the exact reference to the requested location
            }
            ct += current_ct; // increments the count by however many items in current array
            temp = temp -> next; // moves item until we find the one the loc is within
        }
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
