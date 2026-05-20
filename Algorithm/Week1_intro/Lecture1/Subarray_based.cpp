
#include <iostream>
#include <vector>
using namespace std;


int find_pair(vector<int>arr, int sochia, int n)
{   
    vector<int> hash_table(sochia); // mảng k ptu giá trị 0
    for(int i =0; i < n; i++){
        int temp = 0;
        temp = (arr[i]%sochia + sochia)%sochia; //số dư khi arr[i] / k
        hash_table[temp] ++;                    // tăng 1 đơn vị theo số dư
    }

    int count = 0;
    //chọn 2 số trong n số tại ô thứ i
    int first_has = (hash_table[0] * (hash_table[0] - 1) ) /2 ;
    int half_has = (sochia %2 == 0 ) ? (hash_table[sochia / 2] * (hash_table[sochia / 2] - 1)) /2 : 0;

    // lặp mảng đã xử lí mảng chẳn
    for(int i=1;i<= (float(sochia )/2 - 0.5) ; i++){
        int temp =  hash_table[i] * hash_table[sochia - i];
        count += temp;
    }

    return count + half_has +first_has;
}

int main(){
    int n, k;
    // n : số phần tử 
    // k : số chia
    //-> tìm cặp số trong n số, chia hết cho k
    cin>> n >> k;
    vector<int> arr;

    //push #n elements into array
    for(int i = 0;i < n; i++)
    {   
        int temp;
        cin >> temp ;
        arr.push_back(temp);    
    }

    //find pair
    cout << find_pair(arr, k, n);
    return 0;
    
}

