#include "list.h"
#include<iostream>
using namespace std;

LList::LList(LList& L) {
    if (L.myfirst == 0) myfirst = 0;
    else {
        myfirst = new node(L.myfirst->value);
        node* tempL = myfirst;
        node* tempR = L.myfirst;
        while (tempR->next != 0) {
            tempL->next = new node(tempR->next->value);
            tempR = tempR->next;
            tempL = tempL->next;
        }
    }
    mysize = L.mysize;
}
LList::~LList() {
    node* temp;
    while (myfirst != 0) {//1
        temp = myfirst; //2 
        myfirst = myfirst->next;
        delete temp;
    }
}
bool LList::isEmpty() { return (myfirst == 0); }
void LList::addAtEnd(int item) {
    if (isEmpty()) { myfirst = new node(item); }
    else {
        node* temp = myfirst;
        while (temp->next != 0) temp = temp->next;
        temp->next = new node(item);
    }
    mysize++;

}
void LList::addAtBeginning(int item) { //add item at the beginning of list
    node* temp = new node(item);
    if (myfirst == 0) myfirst = temp;
    else { temp->next = myfirst; myfirst = temp; }
    mysize++;

}
void LList::addAtIndex(int pos, int item) {
    if (!(pos < mysize && pos >= 0))cout << "invalid position" << endl;
    else {
        if (pos == 0) addAtBeginning(item);
        else {
            node* ptr = pos2ptr(pos);
            node* temp = new node(item);
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }
    mysize++;
}
void LList::eraseFirst() {
    if (!isEmpty()) {
        node* temp = myfirst;
        myfirst = myfirst->next;
        delete temp;
        mysize--;
    }
}
void LList::eraseEnd() {
    if (myfirst != 0) {
        if (myfirst->next == 0) { delete myfirst; myfirst = 0; }
        else {
            node* temp = myfirst;
            while (temp->next->next != 0) { temp = temp->next; }
            delete temp->next;
            temp->next = 0;
        }
        mysize--;
    }
    else cout << "Can not erase, the list is empty" << endl;
}
void LList::eraseAtIndex(int pos) {
    if (pos<0 || pos>mysize) {
        cout << "Invalid position!";
        return;
    }
    else {
        node* ptr;
        if (pos == 0) eraseFirst();
        else {
            node* prev = pos2ptr(pos);
            ptr = prev;
            prev = ptr->next;
            delete ptr;
        }
    }
    mysize--;
}
void LList::reverse() {
    if (isEmpty() || myfirst->next == 0) return;
    node* pre = 0;
    node* cur = myfirst;
    node* aff = 0;
    while (cur != 0) {
        aff = cur->next;
        cur->next = pre;
        pre = cur;
        cur = aff;
    }
    myfirst = pre;
}
bool LList::find(int item) {
    node* temp = myfirst;
    bool found = false;
    while (found == false && temp!=0) {
        if (temp->value == item) { found = true;}
        else temp = temp->next;
    }
    return found;
}
void LList::findToErase(int item) {
    if (!isEmpty()) {
        if (myfirst->value == item) {
            eraseFirst();
        }
        else {
            node* temp = myfirst;
            while (temp->next->value != item) {
                temp = temp->next;
            }
            node* tempD = temp->next;
            temp->next = temp->next->next;
            delete tempD;
        }
    }
    else
        cout << "List is empty";
}
int LList::size() { return mysize; }

LList::node* LList::pos2ptr(int pos) {
    node* temp = myfirst;
    int counter = 1;
    while (counter < pos) { temp = temp->next; counter++; }
    return temp;
}
LList LList::operator=(LList& L) {
    if (L.myfirst == 0) myfirst = 0;
    else {
        myfirst = new node(L.myfirst->value);
        node* tempL = myfirst;
        node* tempR = L.myfirst;
        while (tempR->next != 0) {
            tempL->next = new node(tempR->next->value);
            tempR = tempR->next;
            tempL = tempL->next;
        }
    }
    mysize = L.mysize;
    return *this;
}
ostream& operator<<(ostream& out, LList& L) {
    LList::node* temp = L.myfirst;
    while (temp != 0) {
        out << " " << temp->value;
        temp = temp->next;
    }
    cout << endl;
    return out;
}