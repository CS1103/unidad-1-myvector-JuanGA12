//
// Created by Juan Galvez on 2019-08-31.
//

#include <stdexcept>
#include "MyVector.h"
#include <iostream>

UTEC::MyVector::MyVector(): vector{nullptr}, n_elementos{0} {
}

UTEC::MyVector::MyVector(int n): n_elementos{n} {

    vector = new int[n_elementos];
    delete[] vector;


}

UTEC::MyVector::~MyVector() {
   std::cout<<"Eliminando Objeto "<<vector<<std::endl;
}

int UTEC::MyVector::size() {

    return n_elementos;
}

void UTEC::MyVector::push_back(int valor) {

    // 1. Crear temporal
    int *temp = new int[n_elementos + 1];

    // 2. Transferir los datos a temp
    for(int i = 0; i < n_elementos; ++i)
        temp[i] = vector[i];

    // 3. Borrar memoria anterior
    delete [] vector;

    // 4. Apuntando a memoria actual
    vector = temp;

    // 5. Actualizando valor
    vector[n_elementos] = valor;

    // 6. Actualizando valor
    n_elementos++;

}

void UTEC::MyVector::insert(int valor, int posicion) {
    try{
        if ( posicion > n_elementos || posicion < 0){
            throw std::runtime_error("Fuera de límite");
        }
    }
    catch (std::exception& e){
        std::cout << e.what()<<std::endl;
    }

    int *tmp = new int[n_elementos + 1];

    for (int i = 0; i < n_elementos ; ++i) {
        tmp[i] = vector[i];

    }

    n_elementos++;

    for (int j = 0; j < n_elementos ; ++j) {
        if( j < posicion){
            tmp[j] = vector[j] ;
        }
        else if( j == posicion){
            tmp[j] = valor;
        }
        else if( j > posicion){
            tmp[j] = vector[j-1]  ;
        }
    }

    delete[] vector;

    vector = tmp;

}

void UTEC::MyVector::pop_back() {

    // 1. Crear temporal
    int *tmp = new int[n_elementos - 1];

    // 2. Transferir los datos a tmp
    for (int i = 0; i < n_elementos; ++i) {
        tmp[i] = vector[i];
    }

    // 3. Borrar memoria anterior
    delete[] vector;

    // 4. Apuntando a memoria actual
    vector = tmp;

    // 6. Actualizando valor
    n_elementos--;
}

void UTEC::MyVector::erase(int posicion) {

    try {
        if( posicion > n_elementos){
            throw std::runtime_error("Fuera de límite");
        }
    }
    catch (std::exception& e){
    std::cout << e.what();
    }

    int *tmp = new int [n_elementos -1];

    n_elementos--;

    for (int i = 0; i < n_elementos ; ++i) {
        if( i < posicion){
            tmp[i] = vector[i];
        }
        else if ( i >= posicion){
            tmp[i] = vector[i + 1];
        }
    }

    delete[] vector;

    vector = tmp;

    }

int UTEC::MyVector::operator[](int posicion) {
    try {
        if ( posicion > n_elementos){
            throw std::runtime_error("Fuerda de límite");
        }
    }

    catch (std::exception& e){
        std::cout << e.what();
    }

    return vector[posicion];
}

UTEC::MyVector UTEC::MyVector::operator+(const UTEC::MyVector &V) {

    MyVector tmp(V);
    for(int i = 0; i < V.n_elementos;i++){
        tmp.vector[i] += this->vector[i];
    }

    return tmp;

}

UTEC::MyVector &UTEC::MyVector::operator=(const UTEC::MyVector &V) {

    if( this-> n_elementos != 0){
        delete[] this->vector;
    }
    this->n_elementos = V.n_elementos;
    this->vector = new int[this->n_elementos];
    for(int i = 0; i < this->n_elementos; i++){
        this->vector[i] = V.vector[i];
    }
    return *this;

}
