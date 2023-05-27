#pragma once
#include<iostream>
using namespace std;

class LList {
private:
    class node {
    public:
        int value;
        node* next;
        node() :value(0), next(0) {}
        node(int item) : value(item), next(0) {}
    };
    int mysize;
public:
    node* myfirst;
    LList() :myfirst(0), mysize(0) {}
    LList(LList&);
    ~LList();
    void addAtEnd(int);
    void addAtBeginning(int);
    void addAtIndex(int, int);
    void eraseFirst();
    void eraseEnd();
    void eraseAtIndex(int);
    void reverse();
    node* pos2ptr(int);
    bool isEmpty();
    bool find(int);
    void findToErase(int);
    int size();
    LList operator=(LList&);
    friend ostream& operator<<(ostream&, LList&);
};

