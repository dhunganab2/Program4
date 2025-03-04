#include "mySet.h"
#include <algorithm>
#include <iomanip>

// Constructor
mySet::mySet() : size(0) {}

// Getters
std::vector<int>& mySet::getelts() {
    return elts;
}

int mySet::getsize() const {
    return size;
}

// Setters
void mySet::setelts(const std::vector<int>& newElts) {
    elts = newElts;
    size = elts.size();
}

void mySet::setsize(int newSize) {
    size = newSize;
}

// Check if set is empty
bool mySet::isempty() const {
    return size == 0;
}

// Check if an element exists in the set
bool mySet::isfound(int x) const {
    return std::find(elts.begin(), elts.end(), x) != elts.end();
}

// Add an element if it's not already present
bool mySet::addelt(int x) {
    if (!isfound(x)) {
        elts.push_back(x);
        size++;
        return true;
    }
    return false;
}

// Delete an element if it exists
bool mySet::deleteelt(int x) {
    auto it = std::find(elts.begin(), elts.end(), x);
    if (it != elts.end()) {
        elts.erase(it);
        size--;
        return true;
    }
    return false;
}

// Union of two sets
mySet mySet::operator+(const mySet& S) const {
    mySet result = *this;  // Copy current set
    for (int val : S.elts) {
        result.addelt(val); // Add elements from S (ensuring no duplicates)
    }
    return result;
}

// Intersection of two sets
mySet mySet::operator*(const mySet& S) const {
    mySet result;
    for (int val : elts) {
        if (S.isfound(val)) {
            result.addelt(val);
        }
    }
    return result;
}

// Difference of two sets (friend function)
mySet operator-(const mySet& left, const mySet& right) {
    mySet result;
    for (int val : left.elts) {
        if (!right.isfound(val)) {
            result.addelt(val);
        }
    }
    return result;
}

// Overloaded output stream operator
std::ostream& operator<<(std::ostream& ost, const mySet& S) {
    ost << "{ ";
    for (size_t i = 0; i < S.elts.size(); i++) {
        ost << S.elts[i];
        if ((i + 1) % 10 == 0 || i == S.elts.size() - 1) {
            ost << " \n";
        } else {
            ost << ", ";
        }
    }
    ost << "}";
    return ost;
}

// Equivalence operator
bool mySet::operator==(const mySet& other) const {
    if (size != other.size) return false;
    std::vector<int> sortedA = elts;
    std::vector<int> sortedB = other.elts;
    std::sort(sortedA.begin(), sortedA.end());
    std::sort(sortedB.begin(), sortedB.end());
    return sortedA == sortedB;
}
