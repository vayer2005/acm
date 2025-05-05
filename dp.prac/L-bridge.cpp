#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    int n25 = n;
    int n21 = n;
    int n18 = n;

    int total = 0;
    while (n25 > 1) {
        n25 -= 2;
        total += 1;
    }
    if (n25 == 1) {
        total += 1;
        n21-=1;
    }

    while (n18 > 0 && n21 > 1) {
        total += 1;
        n18 -= 1;
        n21 -=2;
    }

    if (n21 == 1) {
        total += 1;
        n21-=1;
        n18 -= 2;
    }

    while (n18 > 0) {
        n18 -= 3;
        total += 1;
    }

    cout << total <<endl;
    

}