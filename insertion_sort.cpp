#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 1; i < n; i++) {
        int key = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }
}

int main() {
    int size ;
    cout<<"enter the size of array\n";
    cin>>size ;
    vector<int> vec(size);

    for (int i = 0; i < size; i++) {
        vec[i] = size - i ; 
    }

    clock_t start = clock();
    insertionSort(vec);
    clock_t end = clock();

    
    double time_taken = double(end - start) / CLOCKS_PER_SEC;



    cout << "Time taken by insertionSort function: " << time_taken << " seconds" << endl;

    return 0;
}
