//
//  Header.hpp
//  lab7
//
//  Created by Jacky on 5/20/15.
//  Copyright (c) 2015 lab7. All rights reserved.
//

#ifndef lab7_Header_hpp
#define lab7_Header_hpp
template <class T>
class vector {
private:
    T *v;
    int s;
public:
    vector(vector<T> &other){
        //vector<int> *other new vector(v);
        other = new vector<int>(v);
    }
    void operator=(vector<T> &other){
        }
    vector(){
        v=nullptr;
        s=0;
    }
    ~vector(){
        delete [] v;
    }
    int size(){
        return s;
    }
    T operator[](int); //Only perform address arithmetic
    void resize();
    T at(int); //Check to make sure not out of bounds
    void push_back(T ele) {
        T *temp=new T[s];
        for(int i=0; i<s; i++)
            temp[i]=v[i];
        delete [] v;
        s++;
        v=new T[s];
        for(int i=0; i<s-1; i++)
            v[i]=temp[i];
        v[s-1]=ele;
        delete [] temp;
    }
};

#endif
