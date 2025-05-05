#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n; 
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxVal=0;
    int maxIndex=-1;

    for(int i = 0; i < n; i++) {
        if(arr[i] > maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
    }
    
    if(maxIndex == n-1) {
        maxVal = 0;
        maxIndex = -1;
        for(int i = 0; i < n-1; i++) {
            if(arr[i] > maxVal) {
            maxVal = arr[i];
            maxIndex = i;
            }
        }
        cout << arr[n-1] + maxVal << endl;
        return;
    } else {
        cout << maxVal + arr[n-1] << endl;
        return;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}