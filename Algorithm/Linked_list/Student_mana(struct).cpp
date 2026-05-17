#include <iostream>
#include <list>       //to use class vector
#include <string>       //to use class string
using namespace std;


typedef struct {
    string name;
    int mark;
} Student;


void printList(list<Student>& L) {
    list<Student>::iterator it;
    for (it = L.begin(); it != L.end(); it++)
        cout << it->name << ": " << it->mark << endl;
    cout << "---END---" << endl;

}

int main() {
    list<Student> L; //create an empty list to store Students
    
    Student harry = {"Harry Potter", 10};
    Student hermione = {"Hermione Granger", 8};
    Student draco = {"Draco Malfoy", 7};
    Student luna = {"Luna Lovegood", 8};
    Student ron = {"Ron Weasley", 9};

    L.push_back(harry);     //append {"Harry Potter", 10} to L
    L.push_back(hermione);
    L.push_back(draco);
    L.push_back(luna);
    L.push_back(ron);


    printList(L);
    
    list<Student>::iterator p;

    p = L.begin();
    p++;
    Student gini = {"Gini Weasley", 6};

    L.insert(p, gini);
    
    printList(L);

    p = L.begin();
    p++; p++;
    L.erase(p);
    
    printList(L);

    string s;
    getline(cin, s);
    list<Student>::iterator it;
    for (it = L.begin(); it != L.end(); it++)
        if (s == it->name)
            cout << it->mark << endl;

    return 0;
}