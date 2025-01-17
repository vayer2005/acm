#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int stops;
    ll on; ll off;
    cin >> stops;
    ll most = 0;
    ll curr = 0;
    for(int i =0; i < stops;i++) {
        cin >> off >> on;
        curr += on - off;
        most = max(most, curr);
    }
    cout << most << endl;
}