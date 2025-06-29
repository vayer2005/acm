#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n; double f;
    cin >> n >> f;

    vector<pair<double,double>> cars(n);
    for (int i = 0; i < n; i++) {
        cin >> cars[i].first >> cars[i].second;
    }

    double mintime = 1e9;
    int mincar;
    for (int i = 0; i < n; i++) {
        double time = (f-cars[i].first)/(cars[i].second * 1.0);
        if (time < mintime) {
            mintime = time;
            mincar = i+1;
        }
    }

    cout << mincar << endl;
}