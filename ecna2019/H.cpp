#include <bits/stdc++.h>
 
typedef long long ll;
using namespace std;
 

int main() {
 
    ll a, b;
    ll c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;

    ll h = 1;

    vector<ll> vol;

    while (true) {
        ll w = a - 2*h;
        ll l = b - 2*h;

        if (w <= 0) {
            break;
        }

        vol.push_back(w * h * l);
        h++;
    }

    sort(vol.begin(), vol.end());
    reverse(vol.begin(), vol.end());

    
    for (int i = 0; i < vol.size(); i++) {
        cout << vol[i] << " ";
    }
    
    

    ll start = vol[0] * (f/vol[0]) + c;

    if (start < f) start += vol[0];

    while (start <= g) {
        if (start % vol[1] == d && start % vol[2] == e) {
            cout << start << endl;
            return 0;
        }
        start += vol[0];
    }




}