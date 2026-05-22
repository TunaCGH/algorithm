#include <iostream>
using namespace std;


//Cài đặt thuật toán sắp xếp xen
void insertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        //Xen phần tử A[i] vào vị trí thích hợp
        
        //xét mảng ở trước đó
        int current = A[i];
        //xét mảng trước đó
        int inde;
        for(inde = i - 1; inde>=0;inde--){
            //nếu phần tử trước đó > current thì dời sang phải 1 đơn vị
            if (A[inde] > current)
            { 
                A[inde + 1] = A[inde];
                 
            }
            else
                break;
        }
            A[inde + 1] = current; 
        for (int j = 0; j < n; j++)
                    cout << A[j] <<' ';
        cout<<endl;

    }
       
    
}


int main(){
    int n;
    cin>>n;
    int A[100];
    for(int i =0;i<n;i++){
        cin>> A[i];
    }   
    insertionSort(A,n);
    return 0;
}