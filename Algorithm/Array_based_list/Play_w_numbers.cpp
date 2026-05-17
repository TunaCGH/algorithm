#include <iostream>
#include <vector>       //to use vector class
using namespace std;

//print
void format_print(vector<int> &L)
{
      for (int i = 0; i < L.size(); i++){
        cout<<L[i];
        if( i != (L.size() -1))
        cout << ", ";
    }
    cout<<endl;
}

int main() {
    //1. Create an empty list L to store integer using vector<int> class.
    vector<int> L; //create an empty list


    //2. Read n integer from stdin and append them to L
    int n;
    cin >> n;
    int temp = 0;
    for (int i = 0; i < n; i++) {
        //read an integer and append it to L using push_back() function
        cin >> temp;
        L.push_back(temp); 
    }

    //3. Print elements of L in format: a1, a2, a3
    format_print(L);
    //4. Insert 20 at the 4th position on L
    L.insert(L.begin() + 3, 20);
    //5. Print elements of L
    format_print(L);
    //6. Delete the 1st element
    L.erase(L.begin());
    //7. print
    format_print(L);
    //8. Print the position of x (x is read from stdin)
    int x; // the position
    cin>>x;
    for (int i = 0; i < L.size(); i++) {
        if(L[i] == x){
            cout<< i+1;
            break;}

        else if(i == n-1)
            cout<< i+2;
    }
    return 0;
}