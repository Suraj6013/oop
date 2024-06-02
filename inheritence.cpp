#include<iostream>
using namespace std;

// Base class
class Animal {
public:
    virtual void eat() {
        cout << "Eating..." << endl;
    }
};

// First level derived class
class Mammal: public Animal {
public:
    virtual void breathe() {
        cout << "Breathing..." << endl;
    }
};

// Second level derived class
class Dog: public Mammal {
public:
    void bark() {
        cout << "Barking..." << endl;
    }
    void eat() override {
        cout << "Dog is eating..." << endl;
    }
    void breathe() override {
        cout << "Dog is breathing..." << endl;
    }
};

int main() {
    Dog d;
    d.eat();      // Calling overridden function
    d.breathe();  // Calling overridden function
    d.bark();     // Calling derived class function
    return 0;
}