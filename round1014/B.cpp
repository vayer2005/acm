#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;

    string a; string b;
    cin >> a >>b;
    int aeven = 0;
    int beven = 0;
    int aodd = 0;
    int bodd = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            if (i%2 == 0){
                aeven += 1;
            } else {
                aodd +=1;
            }
        }

        if (b[i] == '0') {
            if (i%2 == 0){
                beven += 1;
            } else {
                bodd +=1;
            }
        }
    }

    if (beven >= aodd && bodd >= aeven) {
        cout << "YES\n";
        return;
    } 
    cout << "NO\n";
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