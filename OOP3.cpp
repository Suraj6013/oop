/*
OOP Assignment 03
Title:-Imagine a publishing company which does marketing for book and audiocassette versions.
Create a class publication that stores the title (a string) and price (type float) of a publication.
From this class derive two classes: book, which adds a page count (type int), and tape, which
adds a playing time in minutes (type float).Write a program that instantiates the book and tape
classes, allows user to enter data and displays the data members. If an exception is caught,
replace all the data member values with zero values.
****************************************************************************/

#include<iostream>
#include<exception>
using namespace std;

class Publication {
protected:
    string title;
    float price;
public:
    Publication(string t = "No title", float p = 0.0) : title(t), price(p) {}
    virtual void getData() = 0;  // Pure virtual function
    virtual void display() = 0;  // Pure virtual function
};

class Book : public Publication {
    int pages;
public:
    Book(string t="No title", float p= 0.0, int pa = 0) : Publication(t,p), pages(pa) {}
    void getData() override {
        cout << "Enter the title, price and pages of the book: ";
        cin >> title >> price >> pages;
    }
    void display() override {
        cout << "Book: " << title << ", Price: " << price << ", Pages: " << pages << endl;
    }
};

class Tape : public Publication {
    float min;
public:
    Tape(string t="No title", float p= 0.0, float m = 0.0) : Publication(t,p), min(m) {}
    void getData() override {
        cout << "Enter the title, price and playing time of the tape: ";
        cin >> title >> price >> min;
    }
    void display() override {
        cout << "Tape: " << title << ", Price: " << price << ", Time: " << min << endl;
    }
};

int main() {
    Book b;
    Tape t;
    int choice;
    cout << "Do you want to buy a book (Press 1) or a tape (Press 2): ";
    cin >> choice;
    switch(choice) {
        case 1: 
            b.getData();
            b.display();
            break;
        case 2: 
            t.getData();
            t.display();
            break;
        default:
            cout << "Invalid choice! Try again!" << endl;
    }
    return 0;
}