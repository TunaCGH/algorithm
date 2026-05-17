#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int maxSum(vector<int> A, int i, int j) {
    //check the leave
    if (i == j)
        return A[i];  
    
    // divide 2 path
    int m = (i + j) / 2;
    
    // recrusive left side
    int left = maxSum(A, i, m);

    // recrusive right side
    int right = maxSum(A, m + 1, j);

    //find max mid
    //max left
    int sum_temp = 0;
    int max_left = A[m];
    for(int inde = m; inde >=i; inde--)
    {
        sum_temp += A[inde];
        if(max_left < sum_temp)
            max_left = sum_temp;
    }
    //max right
    sum_temp = 0;
    int max_right = A[m+1];
     for(int inde = m+1; inde <=j; inde++)
    {
        sum_temp += A[inde];
        if(max_right < sum_temp)
            max_right = sum_temp;
    }

    int middle = max_left + max_right;


    return max(max(left, right), middle);
}

int main(){
    // the number of elements
    int n; 
    cin >> n;

    // input bro
    vector<int> L;
    int temp;
    for(int i = 0; i< n;i++){
        cin >> temp;
        L.push_back(temp);
    }

    
    cout<< maxSum(L, 0, L.size()-1);


}