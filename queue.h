#pragma once
#include <iostream>

using namespace std;
const int MAX_SIZE = 30;
template <typename E>

class Queue{
    public:
        Queue(){
            data = new E[MAX_SIZE];
            curr_value = data;
            size = 0;
        };
        ~Queue(){
            delete[] data;
            data = nullptr;
            curr_value = nullptr;
        }
        Queue(const Queue& other){
            data = new E[MAX_SIZE];
            curr_value = data;
            size = 0;
            for(int i = 0; i < other.size; i++){
                data[i] = other.data[i];
                size++;
            }
        }
        void insert(const E& item){
            try {
                if (size == MAX_SIZE) {
                    throw overflow_error("Queue is full!");
                }
                else {
                    data[size] = item;
                    size++;
                }
            }
            catch(const overflow_error& e){
                cout << e.what() << endl;
            }

        }
        E pop(){
            try {
                if (size == 0) {
                    throw out_of_range("Queue is empty!");
                }
                else {
                    curr_value += 1;
                    size--;
                    return *data;

                }
            }
            catch (const out_of_range& e){
                cout << e.what() << endl;
                return E();
            }

        }

        void clear(){
            while(size != 0){
                pop();
            }
            curr_value = data;
        }

        E front() const {
            return *curr_value;
        }

        Queue& operator=(const Queue& rhs){
            if(this->data == rhs.data){
                return *this;
            }
            clear();
            if(rhs.size == 0){
                return *this;
            }
            for(int i = 0; i < rhs.size; i++){
                data[i] = rhs.data[i];
                size++;
            }
            return *this;
        }

        E operator[](int arg) const {
            try {
                if (arg < 0 || arg >= size) {
                    throw out_of_range("Invalid Index!");
                }
                return data[arg];
            }
            catch(const out_of_range& e){
                cout << e.what() << endl;
            }
        }

        friend ostream& operator<<(ostream& out, const Queue& rhs){
            for(int i = 0; i < rhs.size; i++){
                out << rhs.data[i] << " ";
            }
            out << endl;
            return out;
        }

    private:
        E* data;
        E* curr_value;
        unsigned int size;

};