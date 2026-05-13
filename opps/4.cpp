#include <iostream>
#include <vector>       //to use vector class
#include <string>       //to use string class
using namespace std;

//1. Define a structure Student to store basic informations of a student:
//  name: string
//  mark: integer
typedef struct {
    string name;
    int mark;
}Student;


void format_print(struct Student){
    
}

int main() {
    //2Create a list L to store students using vector<Student> class
    vector<Student> L; //create an empty list to store Students
    
    //3. Insert 5 students into L in ordered of its occurrence
    //for (int i = 0; i < 5; i++) {
    Student people;
    people.name = "Harry Potter";
    people.mark = 10;
    L.push_back(people);     //append {"Harry Potter", 10} to L

    Student people;
    people.name = "Hermione Granger";
    people.mark = 8;
    L.push_back(people);

    Student people;
    people.name = "Draco Malfoy";
    people.mark = 7;
    L.push_back(people);

    Student people;
    people.name = "Luna Lovegood";
    people.mark = 8;
    L.push_back(people);

    Student people;
    people.name = "Ron Weasley";
    people.mark = 9;
    L.push_back(people);



    //4.
    
    
    //5.
    
    //...


    //9. Read a string s from stdin, print the mark of the student whose name is s to stdout. 
    string s;
    getline(cin, s);
    for (int i = 0; i < L.size(); i++)
        if (s == L[i].name)
            cout << L[i].mark << endl;

    return 0;
}

/*
Write a C++ program to to following tasks:

Define a structure Student to store basic informations of a student:
name: string
mark: integer
Create a list L to store students using vector<Student> class
Insert 5 students into L in ordered of its occurrence
Print student List in format
Name 1: mark 1
Name 2: mark 2
...
---END---
Insert a new student (Ginny Weasley, 6) at the 2nd position (1-based)
Print the student list
Delete the 3rd element
Print the student list
Read a string s from stdin, print the mark of the student whose name is s to stdout. 

*/