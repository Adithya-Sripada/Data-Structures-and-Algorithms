#include <iostream>
#include "IntVector.h"
using namespace std;


void display(const IntVector& v){
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
}


int main(){
    IntVector v(10, 0);
    IntVector v2;
    
    display(v);

    cout << "Vector 1 size: " << v.size() << "\n";
    cout << "Vector 2 size: " << v2.size() << "\n";

    cout << "Is Vector 1 empty: "<< v.empty() << "\n";
    cout  << "Is Vector 2 empty: " << v2.empty() << "\n";

    cout << "Element at index 6: " << v.at(6) << "\n";
    //cout << "\nError: " << endl << v.at(93);

   // cout << "\nUndefined behavior (front): " << flush << v2->front();
   // cout << "\nUndefined behavior (back): " << flush << v2.back();

    // v2.push_back(10);
    // display(v2);
    // cout << v2.size() << "\n";
    // v2.insert(0, 423);
    // display(v2);

    v.insert(3, 10);
    display(v);
    v.insert(0, 10);
    display(v);
    v.erase(0);
   // v.insert(-1, 10);
    

    
    display(v);
    


    return 0;
}