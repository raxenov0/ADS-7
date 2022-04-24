// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>

template <typename T>
class TPQueue {
 private:
    struct ITEM {
        T value;
        ITEM* next;
        ITEM* last;
    };
    ITEM* last;
    ITEM* first;

 public:
    TPQueue() {
        first = last = nullptr;
    }
    ~TPQueue(){
     while(first){
       ITEM* current = first;
       first = first->next;
       delete current;
       }
    }
    void push(T element) {
        ITEM* item_ = new ITEM;
        item_->value = element;
        item_->next = item_->last = nullptr;
        ITEM* current = first;
        while (current && current->value.prior >= item_->value.prior)
            current = current->next;
       if (current == nullptr && first == nullptr) {
            first = last = item_;
        } else if (current == nullptr && first) {
            last->next = item_;
            item_->last = last;
            last = item_;
        } else if (current->last == nullptr) {
              first->last = item_;
              item_->next = first;
              first = item_;
        } else {
            current->last->next = item_;
            item_->last = current->last;
            item_->next = current;
            current->last = item_;
        }
    }
    T pop() {
        ITEM* current = first;
        if (first->next == nullptr) first = nullptr;
        else
            {first = first->next;
            first->last = nullptr;}
        T value_ = current->value;
        delete current;
        return value_;
    }
    void print() {
        ITEM* current = first;
        while (current != nullptr) {
            std::cout << current->value.ch << std::endl;
            current = current->next;
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
