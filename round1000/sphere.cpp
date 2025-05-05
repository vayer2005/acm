#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int a; int b; int c;
    int x; int y; int z;
    cin >> a >> b >> c >> x >> y >> z;
    
    int incs = max(0, x-a) + max(0, y-b) + max(0, z-c);

    int decs = max(0, (a-x)/2) + max(0, (b-y)/2) + max(0, (c-z)/2);

    if (decs >= incs) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

}