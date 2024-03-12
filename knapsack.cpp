#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    else
        return max(
            val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

int main() {
    vector<int> profit = {60, 100,110, 120, 200, 250,300,320};
    vector<int> weight = {10, 20,25, 30, 40, 50,55,60};
    int W = 200;
    int n = profit.size();
    clock_t t = clock();
    cout << knapSack(W, weight, profit, n);
    t = clock() - t;
    float time_taken = (float)t / CLOCKS_PER_SEC;
    cout << endl << "Time taken by algorithm is: " << time_taken << endl;
    return 0;
}
