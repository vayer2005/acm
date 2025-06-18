#include <bits/stdc++.h>
 
typedef long long ll;
using namespace std;
 
const double EPS = 1e-9;



int dist(int x1, int x2, int y1, int y2) {
    int x = x1 - x2;
    int y = y1 - y2;
    return x * x + y * y;
}
 
int main() {
    int n;
    ll m, a, c, x;
    cin >> n >> m >> a >> c >> x;

    vector<ll> lst;

    while (lst.size() < n) {
        lst.push_back((a*x + c)%m);
        x = (a*x + c)%m;
    }

    int res = 0;
    for (ll v : lst) {
        int l = 0; int r = n-1;

        while (l <= r) {
            int mid=(l+r)/2;

            if (lst[mid] == v) {
                res++;
                break;
            } else if(lst[mid] > v) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }

    cout << res << endl; 


}