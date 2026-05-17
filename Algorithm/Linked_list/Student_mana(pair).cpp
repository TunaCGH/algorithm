#include <iostream>
#include <vector>       //to use vector class
#include <string>       //to use string class
using namespace std;


typedef struct {
    string name;
    int mark;
} Student;


void format_print(vector<pair<string, int>> &L){
    for(int i=0; i<L.size();i++){
        cout << L[i].first << ": " << L[i].second << endl;
    }
    cout<<"---END---"<<endl;
}

int main() {
    
    //1. Create a list L to store students using class vector< pair<string, int> >
    vector<pair<string, int> > L; //create an empty list to store Students
    
    //2. Insert 5 students into L in ordered of its occurrence
    L.push_back(make_pair("Harry Potter", 10));     //append {"Harry Potter", 10} to L
    L.push_back(make_pair("Hermione Granger", 8));
    L.push_back(make_pair("Draco Malfoy", 7));
    L.push_back(make_pair("Luna Lovegood", 8));
    L.push_back(make_pair("Ron Weasley", 9));
    //3. print the list
    format_print(L);

    //4. Insert a new student (Ginny Weasley, 6) at the 2nd position (1-based)
   
    L.insert(L.begin() + 1, {"Gini Weasley", 6});    
    //5. print the list
    format_print(L);
    //6. erase the component
    L.erase(L.begin() + 2);
    //7. print the list
    format_print(L);

    //8. Read a string s from stdin, print the mark of the student whose name is s to stdout. 
    string s;
    getline(cin, s);                        //read a line and assign to string s
    for (int i = 0; i < L.size(); i++)
        if (s == L[i].first)                //compare two strings
            cout << L[i].second << endl;

    return 0;
}