#include <iostream>
#include "MyVector.h"
#include "cassert"

using namespace UTEC;
using namespace std;

int main() {

    MyVector v1;

    assert(v1.size() == 0);

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    assert(v1.size() == 3);

    MyVector v2;

    v2.push_back(20);
    v2.push_back(40);
    v2.push_back(60);
    cout << "V1: "<<endl;
    for (int j = 0; j < v1.size(); ++j) {
        cout << v1[j]<<" ";
    }
    cout << endl;
    cout << endl;

    cout << "V2: "<<endl;
    for (int d = 0; d < v2.size(); ++d) {
        cout << v2[d]<<" ";
    }
    cout << endl;
    cout << endl;


    MyVector v3;

    v3 = v1 + v2;
    assert(v3.size() == 3);

    cout <<"SUMA V1 + V2: "<<endl ;
    for (int j = 0; j < v3.size(); ++j) {
        cout << v3[j]<<" ";
    }

    cout <<endl;
    cout <<endl;
    cout << "pop_back de V1 "<<endl;
    v1.pop_back();
    for (int j = 0; j < v1.size(); ++j) {
        cout << v1[j]<<" ";
    }

    cout <<endl;
    cout <<endl;
    cout << "insert de V1 (valor 100 posicion 1): "<<endl;
    v1.insert(100,1);
    for (int j = 0; j < v1.size(); ++j) {
        cout << v1[j]<<" ";
    }

    cout <<endl;
    cout <<endl;
    cout << "erase de V1 posicion 0 (10): "<<endl;
    v1.erase(0);
    for (int j = 0; j < v1.size(); ++j) {
        cout << v1[j]<<" ";
    }

    cout <<endl;
    cout <<endl;


}