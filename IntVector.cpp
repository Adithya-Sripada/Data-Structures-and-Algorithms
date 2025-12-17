#include "IntVector.h"
#include <stdexcept>
using namespace std;

void IntVector::expand(){
    int* newArray = nullptr;
    if(_capacity == 0){
        _capacity++;
        newArray = new int[_capacity];
    }
    else{
        _capacity *= 2;
        newArray = new int[_capacity];
    
        for(int i = 0; i < _size; i++){
            newArray[i] = _data[i];
        }
    }
    delete[] _data;
    _data = newArray;
    newArray = nullptr;
    

}

void IntVector::expand(unsigned amount){
    _capacity += amount;
    int* newArray = new int[_capacity];
    for(int i = 0; i < _size; i++){
        newArray[i] = _data[i];
    }
    delete[] _data;
    _data = newArray;
    newArray = nullptr;

}


IntVector::IntVector(unsigned capacity, int value){
    _capacity = capacity;
    _size = 0;
    _data = new int[capacity];
    if(capacity > 0){
        for(unsigned i = 0; i < capacity; i++){
            _data[i] = value;
            _size++;
        }
    }
}

IntVector::~IntVector(){
    delete[] _data;
}

unsigned IntVector::size() const {
    return _size;
}

unsigned IntVector::capacity() const {
    return _capacity;
}

bool IntVector::empty() const {
    return _size == 0;
}

const int& IntVector::at(unsigned index) const {
    if(index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

int& IntVector::at(unsigned index){
    if(index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

const int& IntVector::front() const {
    return _data[0];
}

const int& IntVector::back() const {
    return _data[_size-1];
}

int& IntVector::front(){
    return _data[0];
}

int& IntVector::back(){
    return _data[_size-1];
}

void IntVector::insert(unsigned index, int value){
    int j = 0;
    if(index > _size){
        throw out_of_range("IntVector::insert_range_check");
    }
    if(_size == _capacity){
        expand();
    }
    if(index == _size-1){
        _size++;
        _data[_size-1] = _data[index];
        _data[index] = value;
        return;
    }

    for(int i = _size; i > index; i--){
        _data[i] = _data[i-1];
    }
    _data[index] = value;
    _size++;   
}

void IntVector::erase(unsigned index){
    if(index >= _size){
        throw out_of_range("IntVector::erase_range_check");
    }
    if(index == _size){
        _size--;
        return;
    }

    for(int i = index; i < _size-1; i++){
        _data[i] = _data[i+1];
    }
    _size--;
}

void IntVector::push_back(int value){
    if(_size == _capacity){expand();}
    _size++;
    _data[_size-1] = value;
}

void IntVector::pop_back(){
    _size--;
}

void IntVector::clear(){
    _size = 0;
}

void IntVector::resize(unsigned size, int value){
    if(size <= _size){
        _size = size;
        return;
    }
    if(size > _capacity){
        if(_capacity*2 >= size){
            expand();
        }
        else{
            expand(size-_capacity);
        }
    }

    for(int i = _size; i < size; i++){
        _data[i] = value;
    }
    _size = size;
}

void IntVector::reserve(unsigned n){
    if(_capacity < n){
        expand(n-_capacity);
    }
}

void IntVector::assign(unsigned n, int value){
    if(n > _capacity){
        if(_capacity*2 >= n){
            expand();
        }
        else{
            expand(n-_capacity);
        }
    }
    _size = n;
    for(int i = 0; i < _size; i++){
        _data[i] = value;
    }
}