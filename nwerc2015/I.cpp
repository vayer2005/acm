#include <bits/stdc++.h>


typedef long long ll;
using namespace std;

ll pw4[31];

int main() {
    string s;
    cin >> s;
    ll x = 0;
    ll y = 0;

    pw4[0] = 1;
    for (int i = 1; i < 31; i++) {
        pw4[i] = pw4[i-1] * 2;
    }   

    int zoom = s.size();
    int tile = zoom;
    zoom--;

    
    //cout << pw4[30] << endl;
    for (int i = 0; i < s.size(); i++) {
        int ind = zoom;
        ll offs = pw4[ind];

        if (s[i] == '1') {
           x += offs;
        } else if (s[i] == '2') {
            y += offs;
        } else if (s[i] == '3') {
            x += offs; y += offs;
        }
        zoom--;
    }   

    cout << tile << " " << x << " " << y << endl;
 
}