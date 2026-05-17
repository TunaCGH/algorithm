#include <iostream>
#include <vector>
using namespace std;


int factorial(int n) {
    //1. Kiểm tra n == 0
    if (n == 0)
        return 1;  //Trả về 1
        
    //2. Tính (n - 1)! và lưu lại trong n_1
    
    int n_1 = factorial(n - 1);
    //3. Trả về tích của n_1 và n hay (n - 1)! * n
    return n_1 * n;
}

    

int main(){
    vector<int> L;
    int n; //the number of properities to be implemented
    cin >> n;

    int temp;
    // push into list
    for (int i=0;i<n;i++)
    {
        cin >> temp;
        L.push_back(temp);
    }


    
    // we have a list A[n] = [1,2,3,4....]
    // we need to find the greatest sum of each elements in a sublist of list 
  

    

}