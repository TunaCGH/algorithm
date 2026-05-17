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


void format_print(vector<Student> &L){
    for(int i=0; i<L.size();i++){
        cout<<L[i].name<<": "<<L[i].mark<<endl;
    }
    cout<<"---END---"<<endl;
}

int main() {
    //2Create a list L to store students using vector<Student> class
    vector<Student> L; //create an empty list to store Students
    
    //3. Insert 5 students into L in ordered of its occurrence
    //for (int i = 0; i < 5; i++) {
    //nguoi1
    Student people;
    people.name = "Harry Potter";
    people.mark = 10;
    L.push_back(people);     //append {"Harry Potter", 10} to L
    //nguoi2
    people.name = "Hermione Granger";
    people.mark = 8;
    L.push_back(people);
    //nguoi3
    people.name = "Draco Malfoy";
    people.mark = 7;
    L.push_back(people);
    //nguoi4
    people.name = "Luna Lovegood";
    people.mark = 8;
    L.push_back(people);
    //nguoi5
    people.name = "Ron Weasley";
    people.mark = 9;
    L.push_back(people);

    //4.print the list
    format_print(L);
    
    //5.
    //nguoi1
    people.name = "Gini Weasley";
    people.mark = 6;

     L.insert(L.begin() + 1, people);    
    //6. print the lít
    format_print(L);

    //7. erase 
    L.erase(L.begin() + 2);
    //8. print the lít
    format_print(L);



    //9. Read a string s from stdin, print the mark of the student whose name is s to stdout. 
    string s;
    getline(cin, s);
    for (int i = 0; i < L.size(); i++)
        if (s == L[i].name)
            cout << L[i].mark << endl;

    return 0;
}
