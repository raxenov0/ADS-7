// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>

template<typename T>
class TPQueue {
 private:
  struct ITEM {
    value;
    ITEM* next;
    ITEM* last;
  };
  ITEM* first, *last;
 public:
  TPQueue() {
    first = nullptr;
    last = nullptr;
  }
  ~TPQueue() {
    while ( first ) {
      ITEM* current = first;
      first = (*first).next;
      delete current;
    }
    bool isEmpty() {
      if (first == nullptr) return true;
      else
        return false;
    }
    void push(T element) {
      ITEM* elem = new ITEM;
      (*elem).value = element;
      (*elem).next = nullptr;
      if (isEmpty()) {
        first = last = elem;
        (*first).next = nullptr;
        (*first).last = nullptr;
      } else {
        ITEM* current = first;
        while (current != nullptr) {
          if ((*current).value.prior < (*elem).value.prior) {
            if (current == first) {
              (*elem).last = nullptr;
              first = elem;
            }
            if ((*current).last != nullptr) {
              std::cout << (*elem).value.ch << (*current).value.ch<< std::endl;
              (*elem).next = current;
              current = (*current).last;
              (*current).next = elem;
              (*elem).last = current;
              current = (*(*current).next).next;
            }
            (*elem).next = current;
            (*current).last = elem;
            return;
          }
          current = (*current).next;
        }
        (*last).next = elem;
        (*elem).next = nullptr;
        (*elem).last = last;
        last = elem;
      }
    }
    T& pop() {
      ITEM* current = first;
      first = (*first).next;
      T val = (*current).value;
      delete current;
      return val;
    }
    void print() {
      ITEM* current = first;
      while (current) {
        std::cout << (*current).value.ch << std::endl;
        current = (*current).next;
      }
    }
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
