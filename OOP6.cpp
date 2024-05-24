/*
OOP Assignment 06
Title: -Write C++ program using STL for sorting and searching user defined records such as Item
records
(Item code, name, cost, quantity etc) using vector container.
.
****************************************************************************/
#include <iostream>
#include<list>
using namespace std;

class record {
    list<string> name, dob, phone, ni, code;
    list<int> number;
    list<float> cost;

public:
    void getp();
    void display(list<string>&, list<string>&, list<string>&);
    void searchp(string);
    void sortp();
    void getlist();
    void displayit();
    void searchlist();
    void sortitem();
};

void record::getp() {
    int count;
    string n, d, p;
    cout << "Enter the number of members in record:\n";
    cin >> count;
    for (int i = 1; i <= count; i++) {
        cout << "Enter name:\n"; cin >> n; name.push_back(n);
        cout << "Enter date of birth:\n"; cin >> d; dob.push_back(d);
        cout << "Enter phone number:\n"; cin >> p; phone.push_back(p);
    }
}

void record::display(list<string>& l1, list<string>& l2, list<string>& l3) {
    auto it1 = l1.begin(), it2 = l2.begin(), it3 = l3.begin();
    while (it1 != l1.end()) {
        cout << *it1 << "\t" << *it2 << "\t" << *it3 << endl;
        it1++; it2++; it3++;
    }
}

void record::searchp(string data) {
    auto it1 = name.begin(), it2 = dob.begin(), it3 = phone.begin();
    while (it1 != name.end() && it2 != dob.end() && it3 != phone.end()) {
        if (*it1 == data || *it2 == data || *it3 == data) {
            cout << "Record found!\n";
            cout << "Corresponding name: " << *it1 << "\nCorresponding D.O.B: " << *it2 << "\nCorresponding phone number: " << *it3 << endl;
            return;
        }
        it1++; it2++; it3++;
    }
    cout << "Record not found.\n";
}

void record::sortp() {
    name.sort(); dob.sort(); phone.sort();
}

void record::getlist() {
    cout << "Enter the number of items:\n";
    int c, no; string n; float f;
    cin >> c;
    for (int i = 1; i <= c; i++) {
        cout << "Enter item name:\n"; cin >> n; ni.push_back(n);
        cout << "Enter item code:\n"; cin >> n; code.push_back(n);
        cout << "Enter cost:\n"; cin >> f; cost.push_back(f);
        cout << "Enter the quantity:\n"; cin >> no; number.push_back(no);
    }
}

void record::displayit() {
    display(code, ni, number);
}

void record::searchlist() {
    string key;
    cout << "Enter the item code:\n"; cin >> key;
    auto it = find(code.begin(), code.end(), key);
    if (it != code.end()) {
        cout << "Item available!\n";
        cout << "Item name: " << *it << "\nItem quantity: " << *it << "\nItem cost: " << *it << endl;
    }
}

void record::sortitem() {
    cost.sort(); code.sort(); ni.sort(); number.sort();
}

int main() {
    record obj;
    string key;
    int ch, chr;
    char x = 'y';
    do {
        cout << "1. Personal record\n2. Item record\nEnter choice:\n"; cin >> ch;
        do {
            cout << "1. Enter details\n2. Display\n3. Search entry\n4. Sort records\nEnter choice\n"; cin >> chr;
            if (ch == 1) {
                switch (chr) {
                case 1: obj.getp(); obj.display(); break;
                case 2: obj.display(); break;
                case 3: cout << "Enter either name, d.o.b or phone number you want to find\n"; cin >> key; obj.searchp(key); break;
                case 4: obj.sortp(); obj.display(); break;
                default: cout << "Wrong choice\n"; break;
                }
            }
            else if (ch == 2) {
                switch (chr) {
                case 1: obj.getlist(); obj.displayit(); break;
                case 2: obj.displayit(); break;
                case 3: obj.searchlist(); break;
                case 4: obj.sortitem(); obj.displayit(); break;
                default: cout << "Wrong choice\n"; break;
                }
            }
            else {
                cout << "Wrong choice\n"; break;
            }
            cout << "Do you wish to continue? Y or N\n"; cin >> x;
        } while (x == 'y' || x == 'Y');
        cout << "Do you wish to select another type of record? Y or N\n"; cin >> x;
    } while (x == 'y' || x == 'Y');
    return 0;
}