#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int a;
    set<int> vals;

    for(int i = 0; i < 4; i++) {
        cin >> a;
        vals.insert(a);
    }

    for (int i = 1;i<=5;i++) {
        if (vals.find(i) == vals.end()) {
            cout << i << endl;
        }
    }
}