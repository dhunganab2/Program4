#ifndef MYSET_H
#define MYSET_H

#include <vector>
#include <iostream>

class mySet {
protected:
    std::vector<int> elts;
    int size;

public:
    // Constructor
    mySet();

    // Getters
    std::vector<int>& getelts();
    int getsize() const;

    // Setters
    void setelts(const std::vector<int>& newElts);
    void setsize(int newSize);

    // Utility functions
    bool isempty() const;
    bool isfound(int x) const;
    virtual bool addelt(int x);
    bool deleteelt(int x);

    // Operator overloads
    mySet operator+(const mySet& S) const;  // Union
    mySet operator*(const mySet& S) const;  // Intersection

    // Friend function for difference
    friend mySet operator-(const mySet& left, const mySet& right);

    // Overloaded output stream operator
    friend std::ostream& operator<<(std::ostream& ost, const mySet& S);

    // Equivalence operator
    bool operator==(const mySet& other) const;
};

#endif
