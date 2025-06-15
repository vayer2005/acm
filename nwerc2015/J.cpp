#include <bits/stdc++.h>


typedef long long ll;
using namespace std;



int main() {

    int n; cin >> n;

    int a; 
    for (int i = 0; i < n; i++) {
        cin >> a;
        int val = 0;
        int prev = 0;
        int curr;

        for (int i = 0; i < 8; i++) {
            if ((a >> i) & 1) { //res bit is 1
                curr = !prev;
            } else {
                curr = prev;
            }
            val |= (curr << i);
            prev = curr;
        }

        cout << val << " ";
    }
    cout << endl;
}