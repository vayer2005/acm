#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const double EPS = 1e-9;
const double PI = 3.141592653589793;



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double theta; int n;
    cin >> theta >> n;

    theta = (theta)*(PI/180);
    double tanth = tan(theta);
    vector<pair<double, double>> pos;

    int x, h;
    for (int i = 0; i < n; i++) {
        cin >> x >> h;

        double len = (double)h/tanth;
        pos.push_back({(double)x, x+len}); 
    }

    sort(pos.begin(), pos.end());
    double prev = -1e9;

    double total = 0;
    for (auto x : pos) {
        double start = x.first;
        double enp = x.second;
        if (start < prev) {
            if (enp <= prev) {
                //nth;
            } else {
                total += enp-prev;
            }
        } else {
            total += enp - start;
        }
        prev = max(prev, enp);
    }
    cout << fixed << setprecision(10) << total << endl;
}