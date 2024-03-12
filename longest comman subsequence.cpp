#include <bits/stdc++.h>
using namespace std;

int lcs(const string& X, const string& Y, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string S1 = "ILOVEDAA";
    string S2 = "ILOVECODE";
    int m = S1.size();
    int n = S2.size();

    clock_t t = clock();
    cout << "Length of LCS is " << lcs(S1, S2, m, n);
    t = clock() - t;
    float time_taken = (float)t / CLOCKS_PER_SEC;
    cout << endl << "Time taken by algorithm is: " << time_taken << endl;
    return 0;
}
