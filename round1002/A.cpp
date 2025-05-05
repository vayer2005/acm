#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n; 
    cin >> n;
    int a[n];
    int b[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    set<int> top;
    set<int> bot;

    for(int i = 0; i < n; i++) {
        top.insert(a[i]);
        bot.insert(b[i]);
    }

    if ((top.size() >= 2 && bot.size() >= 2 )|| top.size() >= 3 || bot.size() >= 3) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    top.clear();
    bot.clear();
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