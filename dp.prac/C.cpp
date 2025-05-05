#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;

    int arr[n+1];
    for(int i =0;i<n;i++){
        cin>>arr[i+1];
    }

    for(int i=n/2-1;i>=1;i--){
            if(arr[i]==arr[i+1] || arr[n-i+1]==arr[n-i]){
                swap(arr[i],arr[n-i+1]);
            }
        }
    int tot = 0;
    for(int i = 1; i < n; i++) {
        if (arr[i] == arr[i+1]) {
            tot+=1;
        }
    }

    cout << tot << endl;
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