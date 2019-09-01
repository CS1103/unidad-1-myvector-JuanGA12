//
// Created by Juan Galvez on 2019-08-31.
//

#ifndef UNIDAD_1_MYVECTOR_JUANGA12_MYVECTOR_H
#define UNIDAD_1_MYVECTOR_JUANGA12_MYVECTOR_H

namespace UTEC{

    class MyVector {

    private:
        int *vector;
        int n_elementos;

    public:
        MyVector();
        MyVector(int);
        virtual ~MyVector();

        int size();
        void push_back(int);
        void insert(int,int);
        void pop_back();
        void erase(int);
        int operator[](int);
        MyVector operator+(const MyVector&);
        MyVector &operator=(const MyVector&);





    };
}





#endif //UNIDAD_1_MYVECTOR_JUANGA12_MYVECTOR_H
