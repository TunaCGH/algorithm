#include <iostream>
#include <list>       //to use list vector
using namespace std;

void printList(list<int>& L) {
    list<int>::iterator it = L.begin();
    cout << *it;
    for (it++; it != L.end(); it++)
        cout << ", " << *it;
    cout << endl;

}

int main() {
    int n;
    list<int> L; //create an empty list
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        L.push_back(x);
    }
    
    printList(L);

    list<int>::iterator it = L.begin();
    it = L.begin(); it++; it++; it++;
    L.insert(it, 20);
    
    printList(L);

    L.erase(L.begin());
    printList(L);
    
    int x;
    cin >> x;
    int p = L.size() + 1;
    it = L.begin();
    for (int i = 0; i < L.size(); i++) {
        if (x == *it) {
            p = i + 1;
            break;
        }
        it++;
    }
    
    cout << p << endl;

    return 0;
}