#include <iostream>
#include <fstream>
#include "mySet.h"
#include "OrderedSet.h"

using namespace std;

// Function to read integers from a file into a mySet
void readFromFile(const string& filename, mySet& S) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }
    int num;
    while (file >> num) {
        S.addelt(num);
    }
    file.close();
}

// Function to read integers from a file and attempt to add them to a set
void addElementsFromFile(const string& filename, mySet& S) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }
    int num;
    while (file >> num) {
        if (S.addelt(num)) {
            cout << num << " was successfully added to S1" << endl;
        } else {
            cout << num << " ALREADY PRESENT IN S1" << endl;
        }
    }
    file.close();
}

// Function to read integers from a file and attempt to delete them from a set
void deleteElementsFromFile(const string& filename, mySet& S) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }
    int num;
    while (file >> num) {
        if (S.deleteelt(num)) {
            cout << num << " was successfully deleted from S1" << endl;
        } else {
            cout << num << " NOT FOUND" << endl;
        }
    }
    file.close();
}

int main() {
    mySet S1, S2, S3, S4, S5, S6;
    OrderedSet OS1, OS2, OS3, OS4, OS5, OS6;
    string filename;

    // Read S1 from file
    cout << "Please enter a path to an input file: ";
    cin >> filename;
    readFromFile(filename, S1);

    // Read S2 from file
    cout << "Please enter a path to a second input file: ";
    cin >> filename;
    readFromFile(filename, S2);

    // Display sets before operations
    cout << "\nBEFORE OPERATIONS\n";
    cout << "MySet S1 Contents\n----------------\n" << S1 << endl;
    cout << "MySet S2 Contents\n----------------\n" << S2 << endl;
    cout << "MySet S3 Contents\n----------------\nSet is EMPTY\n" << endl;

    // Union operation
    S3 = S1 + S2;
    cout << "After UNION Operation of S1 and S2\n";
    cout << "MySet S3 Contents\n----------------\n" << S3 << endl;

    // Intersection operation
    S4 = S1 * S2;
    cout << "After INTERSECTION Operation of S1 and S2\n";
    cout << "MySet S4 Contents\n----------------\n" << S4 << endl;

    // Difference operation
    S5 = S1 - S2;
    cout << "After DIFFERENCE Operation of S1 and S2\n";
    cout << "MySet S5 Contents\n----------------\n" << S5 << endl;

    // Equivalence check
    S6 = S1 + S3;
    cout << (S3 == S6 ? "S3 and S6 ARE EQUAL\n" : "S3 and S6 ARE NOT EQUAL\n");
    cout << (S1 == S6 ? "S1 and S6 ARE EQUAL\n" : "S1 and S6 ARE NOT EQUAL\n");

    // Add elements from file
    cout << "\nPlease enter a path to a third input file: ";
    cin >> filename;
    addElementsFromFile(filename, S1);
    cout << "\nS1 AFTER ADDITION of elements\nMySet S1 Contents\n----------------\n" << S1 << endl;

    // Delete elements from file
    cout << "\nPlease enter a path to a fourth input file: ";
    cin >> filename;
    deleteElementsFromFile(filename, S1);
    cout << "\nS1 AFTER DELETION of elements\nMySet S1 Contents\n----------------\n" << S1 << endl;

    // Repeat for OrderedSet
    cout << "\nProcessing Ordered Sets...\n";

    // Read OS1 and OS2
    cout << "Please enter a path to an input file: ";
    cin >> filename;
    readFromFile(filename, OS1);

    cout << "Please enter a path to a second input file: ";
    cin >> filename;
    readFromFile(filename, OS2);

    // Display sets before operations
    cout << "\nBEFORE OPERATIONS\n";
    cout << "OrderedSet OS1 Contents\n----------------\n" << OS1 << endl;
    cout << "OrderedSet OS2 Contents\n----------------\n" << OS2 << endl;
    cout << "OrderedSet OS3 Contents\n----------------\nOrdered Set is EMPTY\n" << endl;

    // Union operation
    OS3 = OS1 + OS2;
    cout << "After UNION Operation of OS1 and OS2\n";
    cout << "OrderedSet OS3 Contents\n----------------\n" << OS3 << endl;

    // Intersection operation
    OS4 = OS1 * OS2;
    cout << "After INTERSECTION Operation of OS1 and OS2\n";
    cout << "OrderedSet OS4 Contents\n----------------\n" << OS4 << endl;

    // Difference operation
    OS5 = OS1 - OS2;
    cout << "After DIFFERENCE Operation of OS1 and OS2\n";
    cout << "OrderedSet OS5 Contents\n----------------\n" << OS5 << endl;

    // Equivalence check
    OS6 = OS1 + OS3;
    cout << (OS3 == OS6 ? "OS3 and OS6 ARE EQUAL\n" : "OS3 and OS6 ARE NOT EQUAL\n");
    cout << (OS1 == OS6 ? "OS1 and OS6 ARE EQUAL\n" : "OS1 and OS6 ARE NOT EQUAL\n");

    // Add elements to OrderedSet from file
    cout << "\nPlease enter a path to a third input file: ";
    cin >> filename;
    addElementsFromFile(filename, OS1);
    cout << "\nOS1 AFTER ADDITION of elements\nOrderedSet OS1 Contents\n----------------\n" << OS1 << endl;

    // Delete elements from OrderedSet from file
    cout << "\nPlease enter a path to a fourth input file: ";
    cin >> filename;
    deleteElementsFromFile(filename, OS1);
    cout << "\nOS1 AFTER DELETION of elements\nOrderedSet OS1 Contents\n----------------\n" << OS1 << endl;

    cout << "\nPROGRAM COMPLETE\n";

    return 0;
}
