#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {

    ll n, m, x, y;
    cin >> n >> m >> x >> y;

    ll a[n];
    for (int i = 0; i<n; i++) {
        cin >> a[i];
    }

    ll b[m];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(b, b+m);
    reverse(b, b+m);
    sort(a, a+n);
    reverse(a, a+n);

    ll currInd = 0;
    ll shelf = 0;
    while (currInd < m) {
        if (shelf >= n) {
            cout << "impossible\n";
            return 0;
        }
        if (b[currInd] > a[shelf]) {
            cout << "impossible\n";
            return 0;
        }
        currInd += x;
        shelf +=1;
    }

    ll l = 0; ll r = shelf;

    while (l <= r) {
        ll mid = (l+r)/2;

        ll inda = mid;
        ll indb = x * mid;
        bool works=true;
        while (indb < m) {
            if (inda >= n) {
                works = false;
                break;
            }
            if (b[indb] > a[inda]) {
                works = false;
                break;
            }
            indb += y;
            inda += 1;
        }
        if (works) {
            r=mid-1;
        } else {
            l = mid+1;
        }
    }
    cout << n-l << endl;
}