#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSort(vector<int> A) {
    int n = A.size();
    if (n <= 1)
        return A;
    
    int m = n/2;
    vector<int> L = mergeSort(vector<int>(A.begin(), A.begin() + m));
    vector<int> R = mergeSort(vector<int>(A.begin() + m, A.end()));
    vector<int> K;
    //Trộn 2 danh sách L và R thành danh sách K
        size_t indeL = 0;
        size_t indeR = 0;
        while (indeL < L.size() && indeR <R.size())
        {   
            if(L[indeL] < R[indeR]){
                K.push_back(L[indeL]);
                indeL ++;
            }    
            else{
                K.push_back(R[indeR]);
                indeR ++;
            }
        }
        while (indeL < L.size()){
            K.push_back(L[indeL]);
            indeL ++;}
        while (indeR < R.size()){
            K.push_back(R[indeR]);
            indeR ++;}
    
    
        //nếu inde của R valid thì...
    //ko thì return

    return K;
}


int main(){
    int n;
    cin>>n;
    vector<int> A;
    for(int i =0;i<n;i++){
        int temp;
        cin>> temp ;
        A.push_back(temp);
    }   
    vector<int> K = mergeSort(A);
    for (int j = 0; j < n; j++)
        cout << K[j] <<' ';
    cout<<endl;
    return 0;
}