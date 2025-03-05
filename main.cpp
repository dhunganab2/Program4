#include <iostream>
#include <fstream>
#include <string>
#include "mySet.h"
#include "OrderedSet.h"
using namespace std;

// Helper function to print mySet objects with title and formatting.
void printMySet(const string& title, mySet &S) {
    cout << title << "\n----------------\n";
    cout << S << "\n\n";
}

// Helper function to print OrderedSet objects with title and formatting.
void printOrderedSet(const string& title, OrderedSet &OS) {
    cout << title << "\n----------------\n";
    cout << OS << "\n\n";
}

int main() {
    mySet S1, S2, S3, S4, S5, S6;
    OrderedSet OS1, OS2, OS3, OS4, OS5, OS6;
    string filePath;
    int num;


    cout << "Please enter a path to an input file : ";
    getline(cin, filePath);
    ifstream inFile1(filePath);
    if (!inFile1) {
        cerr << "Error opening file: " << filePath << endl;
        return 1;
    }
    while (inFile1 >> num) {
        S1.addelt(num);
    }
    inFile1.close();

    cout << "Please enter a path to a second input file : ";
    getline(cin, filePath);
    ifstream inFile2(filePath);
    if (!inFile2) {
        cerr << "Error opening file: " << filePath << endl;
        return 1;
    }
    while (inFile2 >> num) {
        S2.addelt(num);
    }
    inFile2.close();

    cout << "\nBEFORE OPERATIONS\n\n";
    printMySet("MySet S1 Contents", S1);
    printMySet("MySet S2 Contents", S2);
    cout << "MySet S3 Contents\n----------------\n";
    if (S3.isempty())
        cout << "Set is EMPTY\n\n";
    else
        cout << S3 << "\n\n";


    S3 = S1 + S2;
    cout << "After UNION Operation of S1 and S2 \n";
    printMySet("MySet S3 Contents", S3);
    printMySet("MySet S1 Contents", S1);
    printMySet("MySet S2 Contents", S2);


    S4 = S1 * S2;
    cout << "After INTERSECTION Operation of S1 and S2 \n\n";
    printMySet("MySet S4 Contents", S4);
    printMySet("MySet S1 Contents", S1);
    printMySet("MySet S2 Contents", S2);


    S5 = S1 - S2;
    cout << "After DIFFERENCE Operation of S1 and S2 \n\n";
    printMySet("MySet S5 Contents", S5);
    printMySet("MySet S1 Contents", S1);
    printMySet("MySet S2 Contents", S2);


    S6 = S1 + S3;
    if (S3 == S6)
        cout << "S3 and S6 ARE EQUAL\n";
    else
        cout << "S3 and S6 ARE NOT EQUAL\n";

    if (S1 == S6)
        cout << "S1 and S6 ARE EQUAL\n";
    else
        cout << "S1 and S6 ARE NOT EQUAL\n";


    cout << "\nPlease enter a path to a third input file : ";
    getline(cin, filePath);
    ifstream inFile3(filePath);
    if (!inFile3) {
        cerr << "Error opening file: " << filePath << endl;
        return 1;
    }
    while (inFile3 >> num) {
        if (S1.addelt(num))
            cout << num << " was successfully added to S1\n";
        else
            cout << num << " ALREADY PRESENT IN S1\n";
    }
    inFile3.close();

    cout << "\nS1 AFTER ADDITION of elements\n\n";
    printMySet("MySet S1 Contents", S1);


    cout << "Please enter a path to a fourth input file : ";
    getline(cin, filePath);
    ifstream inFile4(filePath);
    if (!inFile4) {
        cerr << "Error opening file: " << filePath << endl;
        return 1;
    }
    while (inFile4 >> num) {
        if (S1.deleteelt(num))
            cout << num << " was successfully deleted from S1\n";
        else
            cout << num << " NOT FOUND\n";
    }
    inFile4.close();

    cout << "\nS1 AFTER DELETION of elements\n\n";
    printMySet("MySet S1 Contents", S1);


    cout << "\nOUTPUT FOR ORDERED SETS\n\n";
    cout << "Please enter a path to an input file : ";
    getline(cin, filePath);
    ifstream inFile5(filePath);
    if (!inFile5) {
        cerr << "Error opening file: " << filePath << endl;
        return 1;
    }
    while (inFile5 >> num) {
        OS1.addelt(num);
    }
    inFile5.close();

    cout << "Please enter a path to a second input file : ";
    getline(cin, filePath);
    ifstream inFile6(filePath);
    if (!inFile6) {
        cerr << "Error opening file: " << filePath << endl;
        return 1;
    }
    while (inFile6 >> num) {
        OS2.addelt(num);
    }
    inFile6.close();

    cout << "\nBEFORE OPERATIONS\n\n";
    printOrderedSet("OrderedSet OS1 Contents", OS1);
    printOrderedSet("OrderedSet OS2 Contents", OS2);
    cout << "OrderedSet OS3 Contents\n----------------\n";
    if (OS3.isempty())
        cout << "Ordered Set is EMPTY\n\n";
    else
        cout << OS3 << "\n\n";


    OS3 = OS1 + OS2;
    cout << "After UNION Operation of OS1 and OS2 \n\n";
    printOrderedSet("OrderedSet OS3 Contents", OS3);
    printOrderedSet("OrderedSet OS1 Contents", OS1);
    printOrderedSet("OrderedSet OS2 Contents", OS2);


    OS4 = OS1 * OS2;
    cout << "After INTERSECTION Operation of OS1 and OS2 \n\n";
    printOrderedSet("OrderedSet OS4 Contents", OS4);
    printOrderedSet("OrderedSet OS1 Contents", OS1);
    printOrderedSet("OrderedSet OS2 Contents", OS2);


    OS5 = OS1 - OS2;
    cout << "After DIFFERENCE Operation of OS1 and OS2 \n\n";
    cout << "MySet OS5 Contents\n----------------\n" << OS5 << "\n\n";
    printOrderedSet("MySet OS1 Contents", OS1);
    printOrderedSet("MySet OS2 Contents", OS2);


    OS6 = OS1 + OS3;
    if (OS3 == OS6)
        cout << "OS3 and OS6 ARE EQUAL\n";
    else
        cout << "OS3 and OS6 ARE NOT EQUAL\n";

    if (OS1 == OS6)
        cout << "OS1 and OS6 ARE EQUAL\n";
    else
        cout << "OS1 and OS6 ARE NOT EQUAL\n";


    cout << "\nPlease enter a path to a third input file : ";
    getline(cin, filePath);
    ifstream inFile7(filePath);
    if (!inFile7) {
        cerr << "Error opening file: " << filePath << endl;
        return 1;
    }
    while (inFile7 >> num) {
        if (OS1.addelt(num))
            cout << num << " was successfully added to OS1\n";
        else
            cout << num << " ALREADY PRESENT IN OS1\n";
    }
    inFile7.close();

    cout << "\nOS1 AFTER ADDITION of elements\n\n";
    printOrderedSet("OrderedSet OS1 Contents", OS1);


    cout << "Please enter a path to a fourth input file : ";
    getline(cin, filePath);
    ifstream inFile8(filePath);
    if (!inFile8) {
        cerr << "Error opening file: " << filePath << endl;
        return 1;
    }
    while (inFile8 >> num) {
        if (OS1.deleteelt(num))
            cout << num << " was successfully deleted from OS1\n";
        else
            cout << num << " NOT FOUND\n";
    }
    inFile8.close();

    cout << "\nOS1 AFTER DELETION of elements\n\n";
    printOrderedSet("OrderedSet OS1 Contents", OS1);

    cout << "PROGRAM COMPLETE\n";

    return 0;
}
