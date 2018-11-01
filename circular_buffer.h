#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H
#include <iostream>
using namespace std;

template<typename T>
class CiruclarBuffer{
    T * ptrArray;
    unsigned int read;
    unsigned int write;
    unsigned int size;
    bool isFull;
    bool isEmpty;

public:
    CiruclarBuffer(unsigned int size);
    ~CiruclarBuffer();
    void show();
    void push(T data);
    T pop();
};

template<typename T>
CiruclarBuffer<T>::CiruclarBuffer(unsigned int size){

    if(size<=1){   //buffer size must be greater than one
        exit (1);
    }

    this->ptrArray=new (nothrow) T[size];
    if (ptrArray == nullptr){
        // error assigning memory
        exit (1);
    }

    //initialize
    for (unsigned int i=0 ; i<size ;i++){
        ptrArray[i]=0;
    }

    read=0;
    write=0;
    this->size=size;
    isFull=false;
    isEmpty=true;

}

template<typename T>
CiruclarBuffer<T>::~CiruclarBuffer(){
    delete[] ptrArray ;
}

template<typename T>
void CiruclarBuffer<T>::show(){
    for (unsigned int i=0; i<size ;i++){
        cout << "position " << i << " = "<< ptrArray[i]<< endl;
    }
}

template<typename T>
void CiruclarBuffer<T>::push(T data){

    if(isFull){
        return;
    }

    ptrArray[write]=data;
    isEmpty=false;
    write++;

    if(write>=size){
        write=0;
    }

    if(write==read){
        isFull=true;
    }
}

template<typename T>
T CiruclarBuffer<T>::pop(){

    T value;

    if(isEmpty){
        return -1;
    }

    value=ptrArray[read];
    //ptrArray[read]='\0';    //reset pop values for char type, 0 for int type, etc.
    read++;

    if(read>=size){
        read=0;
    }

    if(write!=read){
        isFull=false;
    }else{
        isEmpty=true;
    }

    return  value;
}
#endif // CIRCULAR_BUFFER_H
