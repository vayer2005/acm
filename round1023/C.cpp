#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n; ll k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll arr[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            pos = i;
            arr[i] = -1e13;
        }
    }

    ll mx = 0;
    ll run = 0;

    for (int i = 0; i < n; i++) {
        run = max(run + arr[i], arr[i]);
        mx = max(mx, run);
    }

    if (mx > k || mx != k && pos == -1) {
        cout << "NO\n";
        return;
    }

    if (pos != -1){
            mx = 0, run = 0;
            ll L, R;
            
            for (int i = pos + 1; i < n; i++){
                run += arr[i];
                mx = max(mx, run);
            }
            L = mx;
            mx = 0;
            run = 0;
            for (int i = pos - 1; i >= 0; i--){
                run += arr[i];
                mx = max(mx, run);
            }
            R = mx;

            arr[pos] = k - L - R;

    }

    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    


    

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