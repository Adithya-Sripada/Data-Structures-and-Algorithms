#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}

IntList::IntList(const IntList& copy){
    if(copy.empty()){
        head = nullptr;
        tail = nullptr;
    }
    else{
        IntNode* n = copy.head;
        while(n){
            push_back(n->value);
            n = n->next;
        }
    }
}

IntList::~IntList(){
    clear();
}

void IntList::push_front(int value){
    IntNode* n = new IntNode(value);
    if(empty()){
        n->next= head;
        head = n;
        tail = n;
        return;
    }
    
    n->next = head;
    head = n;

}

bool IntList::empty() const {
    return head == nullptr;
}

const int& IntList::front() const{
    return head->value;
}

const int& IntList::back() const {
    return tail->value;
}

void IntList::pop_front(){
    if(empty()){
        return;
    }
    IntNode* n = head->next;
    delete head;
    head = n;
    if(head == nullptr){
        tail = nullptr;
    }
}
void IntList::clear(){
    if(empty()){
        return;
    }
    while(head){
        IntNode* next = head->next;
        delete head;
        head = next;

    }
    head = nullptr;
    tail = nullptr;
}

void IntList::push_back(int value){
    IntNode* n = new IntNode(value);
    if(empty()){
        head = n;
        tail = n;
        return;
    }
    tail->next = n;
    tail = n;
}

void IntList::insert_ordered(int value){
    if(empty()){
        IntNode* n = new IntNode(value);
        head = n;
        tail = n;
        return;
    }
    if(value <= head->value){
        push_front(value);
        return;
    }
    if(value >= tail->value){
        push_back(value);
        return;
    }
    IntNode* n = new IntNode(value);
    IntNode* i = head;
    while(i){
        if(i->next == nullptr){
            if(value > i->value){
                i->next = n;
                return;
            }
        }
        if((i->value <= value) && (i->next->value > value)){
            n->next = i->next;
            i->next = n;
            return;
        }
        i = i->next;
    }
}

void IntList::remove_duplicates(){
    if(empty()){
        return;
    }
    if(head == tail){
        return;
    }
    IntNode* previous;
    for(IntNode* i = head; i != nullptr; i = i->next){
        previous = i;
        for(IntNode* j = i->next; j != nullptr; j = previous->next){
            if(j->value == i->value){
                IntNode* del = j;
                if(j->next == nullptr){
                    previous->next = nullptr;
                    tail = previous;
                    delete del;
                    del = nullptr;
                    return;
                }
                else{
                    previous->next = j->next;
                    delete del;
                    del = nullptr;
                }
                
            }
            else{
                previous = previous->next;
            }

        }
        if(i->next == nullptr){
            previous = nullptr;
        }
    }
}

void IntList::selection_sort(){
    if(empty()){
        return;
    }
    if(head == tail){
        return;
    }
    int min = head->value;
    IntNode* temp = head;
    int t;
    for(IntNode* i = head; i != nullptr; i = i->next){
        min = i->value;
        for(IntNode* j = i->next; j != nullptr; j = j->next){
            if(j->value <= min){
                min = j->value;
                temp = j;
                //cout << "temp " << temp->value << endl;
            }
        }
        if(temp != nullptr){
            t = i->value;
            i->value = temp->value;
            temp->value = t;
            temp = nullptr;
        }
        
        //cout << *this << endl;
    }
}

IntList& IntList::operator=(const IntList& rhs){
    if(rhs.head == this->head){
        return *this;
    }
    clear();
    if(rhs.empty()){
        return *this;
    }

    IntNode* n = rhs.head;
    while(n){
        push_back(n->value);
        n = n->next;
    }
    return *this;
}

ostream& operator<<(ostream& out, const IntList& list){
    if(list.empty()){
        return out;
    }
    IntNode* n = list.head;
    while(n->next){
        out << n->value << " ";
        n = n->next;
    }
    out << n->value;
    return out;

}