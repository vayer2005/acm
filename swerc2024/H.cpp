#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


int main() {
    int n;
    cin >> n;

    map<string,int> v;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v[s]++;
    }

    int m = 0;
    string w;
    for (auto &it : v) {
        if (it.second > m) {
            w = it.first;
            m = it.second;

        }
    }
    cout << w << endl;
}


