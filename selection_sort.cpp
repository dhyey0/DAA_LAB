#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void selectionSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (vec[j] < vec[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(vec[i], vec[minIndex]);
        }
    }
}

int main() {
    int size; 
    cout << "Enter the size of array: ";
    cin >> size;
    vector<int> vec(size);

    for (int i = 0; i < size; i++) {
        vec[i] = size - i; 
    }

    
    clock_t start = clock();
    selectionSort(vec);
    clock_t end = clock();

    
    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    
    cout << "Time taken by selectionSort function: " << time_taken << " seconds" << endl;

    return 0;
}
