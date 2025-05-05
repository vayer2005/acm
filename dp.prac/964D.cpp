#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;
ll MAX = 200007;
ll arr[200007];
ll pref[200007];

void solve() {
    int l; int r;
    cin >> l >> r;

    int x = l;
    int tmp = 0;
    while (x) {
		x /= 3;
		tmp++;
	}

    int val = (int)pow(3, tmp);


    ll total = pref[r] - pref[l-1] + tmp;

    cout << total << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    for(int i = 0; i < MAX; i++) {
        int cnt = 0;
        int x = i;
	    while (x) {
		    x /= 3;
		    cnt++;
	    }
	    arr[i] = cnt;
    }
    pref[0] = 0;
    for(int i = 1; i < MAX; i++) {
        pref[i] = pref[i-1] + arr[i];
    }

    while (t--) {
        solve();
    }

}