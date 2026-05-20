#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    //nhập vào #n số phần từ, k là tổng 
    int n, k;
    cin >> n >> k;

    vector<long long> count_freq(1000003, 0);
    
    long long pair_count = 0;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        int target = k - abs(val); // phần tử mong đợi

        // tăng theo lịch sử mong đợi
        if (target >= 0 && target <= 1000000) {
            pair_count += count_freq[target];
        }

        // tăng lịch sử mong đợi của nó 
        if (abs(val) <= 1000000) {
            count_freq[abs(val)]++;
        }
    }

    cout << pair_count << "\n";

    return 0;
}