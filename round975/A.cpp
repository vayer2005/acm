#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    int arr[n];

    for(int i =0; i < n; i++) {
         cin >> arr[i];
    }

    int max1 = 0; int num1 = 0;
    for (int i = 0; i < n; i+=2) {
        num1+=1;
        max1 = max(max1, arr[i]);
    }

    int max2 = 0; int num2 = 0;
    for (int i = 1; i < n; i+=2) {
        num2+=1;
        max2 = max(max2, arr[i]);
    }

    cout << max(max1 + num1, max2 + num2) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}