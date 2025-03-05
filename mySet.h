#ifndef MYSET_H
#define MYSET_H

#include <vector>
#include <iostream>
using namespace std;

class mySet {
protected:
    vector<int> elts;
    int size;
public:
    mySet();
    vector<int>& getelts();
    int getsize();

    void setelts(const vector<int>& newElts);
    void setsize(int newSize);

    bool isempty();
    bool isfound(int x)const;
    bool addelt(int x);
    bool deleteelt(int x);

    mySet operator+(mySet &S);
    mySet operator*(mySet &S);
    bool operator==(mySet &other);

    friend mySet operator-(const mySet &left, const mySet &right);
    friend ostream& operator<<(ostream &ost, mySet &S);
};

mySet operator-(const mySet &left, const mySet &right);

#endif
