#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

long long binary_search( vector<long long> A, int n, int T) {
    int L = 0;
    int R = n - 1;

    while (L <= R) {
        int m = (L + R) / 2;

        if (A[m] < T) {
            L = m + 1;
        } else if (A[m] > T) {
            R = m - 1;
        } else if(A[m]==T){
            return m;
        }
    }

    return -1;
}

int main() {
    vector<long long int>arr;

    for(ll i=0;i<10000000;i++)
    {
        long long k=(long long)(i);
        arr.push_back(k);
    }
    int target = arr[((1+arr.size())/4)];
    clock_t start, end;
    start=clock();

    long long result = binary_search(arr, arr.size(), target);
        end=clock();


    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

        cout<<"time is "<<setprecision(5)<<(double(end-start)/double(CLOCKS_PER_SEC))<<" SECONDS\n";

    return 0;
}