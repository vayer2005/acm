#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


signed main() {
    int n, k;
    cin >> k >> n;

    for (int i = 1; i <= n; i++) {
        int opt = (i+1)/2;
        int nop=(n-i)/3;
        if ((n-i)%3==2) {
            nop++;
        }
        if (opt + nop == k) {
            if (i%2 == 0) {
                for (int j = 0; j < opt; j++) {
                    cout << "-X";
                }
            } else {
                for (int j = 0; j < opt-1; j++) {
                    cout << "X-";
                }
                cout << "X";
            }

            int spaces = n-i;
            for (int j = 0; j+3 <= spaces; j+=3) {
                cout << "--X";
            }
            
            if ((n-i)%3==2) {
                cout << "-X";
            } else if ((n-i)%3 ==1) {
                cout << "-";
            }
            cout << endl;
            return 0;
        }
    }

    cout << "*\n";
}