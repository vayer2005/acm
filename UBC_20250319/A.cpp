#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


int main() {
    int n; int c; 

    cin >> c >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = -50;
    int r = 50;

    while (l <= r) {
        //cout << l << " " << r << endl; 
        int mid = (l + r)/2;
        int ndays = 0;
        for(int i = 0; i < n; i++) {
            if (arr[i] < mid) {
                ndays += 1;
            } else {
                ndays = 0;
            }
            if (ndays > c) {
                r= mid-1;
                break;
            }
        }

        if (r != mid-1) {
            l = mid+1;
        }
    }

    int res = min(l, r);
    if (min(l, r) > 50) {
        res = 50;
    } else if (min(l,r) < -50) {
        res = -50;
    }
    cout << res << endl;
    

    

}