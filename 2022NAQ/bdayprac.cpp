#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mod = 1e9+7;

void multiply(vector<vector<int> >& A,
              vector<vector<int> >& B) {
    // Matrix to store the result
    vector<vector<int>> C(90, vector<int>(90));

    for (int i = 0; i < 90; i++) {
        for (int j = 0; j < 90; j++) {
            for (int k = 0; k < 90; k++) {
                C[i][j] = (C[i][j] + (((A[i][k]) * (B[k][j])) % mod))% mod;
            }
        }
    }

    // Copy the result back to the first matrix
    for (int i = 0; i < 90; i++) {
        for (int j = 0; j < 90; j++) {
            A[i][j] = C[i][j];
        }
    }
}

vector<vector<int>> power(vector<vector<int>> M, int expo) {
    // Initialize result with identity matrix
    vector<vector<int>> ans(90, vector<int>(90,0));
    for (int i = 0; i < 90; i++) {
        for (int j = 0; j < 90; j++) {
            if (i == j) ans[i][j] = 1;
        }
    }

    // Fast Exponentiation
    while (expo) {
        if (expo & 1)
            multiply(ans, M);
        multiply(M, M);
        expo >>= 1;
    }

    return ans;
}



signed main() {
    int len; int rem;
    cin >> len >> rem;

    int m9 = rem%9;
    int m25 = rem%25;
    if (len == 1) {
        if (rem > 9) {
            cout << "0\n";return 0;
        } else {
            cout << "1\n";
            return 0;
        }
    } else if (len == 2) {
        if (rem >= 10 && rem % 11 != 0 && rem < 100) {
            cout << "1\n";
            return 0;
        } else {
            cout << "0\n";
            return 0;
        }
    }

    vector<int> start;
    for (int i = 0; i <= 99; i++) {
        if (i%11 == 0) continue;
        if (i%25 == m25) {
            start.push_back(i);
        }
    }

    //90x90
    vector<vector<int>> matrix(90, vector<int>(90,0));

    for (int i = 0; i < 90; i++) {
        int sum9 = i/10;
        int lastdig = i%10;
        for (int j = 0; j <= 9; j++) {
            if (j == lastdig) continue;
            int news9 = (sum9 + j) % 9;
            int newlastd = j;
            matrix[i][news9*10 + newlastd] = 1;
        }
    }

    vector<vector<int>> res = power(matrix, len-2);
    int fin = 0;
    for (int val : start) {
        int tens = val / 10;         // A
        int ones = val % 10;         // B

        int currSum = (tens + ones) % 9;       
        int src = currSum * 10 + tens;    

        for (int first = 1; first <= 9; ++first) { 
            int dst = m9 * 10 + first;            
            fin += res[src][dst];
            fin %= mod;
        }
    }

    cout << fin << endl;
}
