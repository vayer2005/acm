#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;  cin >> n;
    vector<int> a(n);
    vector<char> seen(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i]) seen[a[i]] = 1;
    }

    vector<int> nextNZ(n, n);        
    vector<int> prevNZ(n, -1);
    for (int i = n - 1; i >= 0; --i)
        nextNZ[i] = (a[i] ? i : (i + 1 < n ? nextNZ[i + 1] : n));

    for (int i = 0; i < n; ++i)
        prevNZ[i] = (a[i] ? i : (i ? prevNZ[i - 1] : -1));

    int L = 0, R = n - 1, cur = 1;

    while (L <= R) {
        if (a[L] == cur) { ++L; ++cur; continue;}
        if (a[R] == cur) { --R; ++cur; continue;}

        if (a[L] && a[R]) { cout << "*\n"; return 0;} 

        if (a[L]) {               
            if (seen[cur]) { cout << "*\n"; return 0;}
            a[R] = cur;  
            --R; ++cur; continue;
        }
        if (a[R]) {                 
            if (seen[cur]) { cout << "*\n"; return 0;}
            a[L] = cur;  
            ++L; ++cur; continue;
        }

        int pl = nextNZ[L];          
        int pr = prevNZ[R];        

        bool putLeft;
        if (pl > R || pr < L) {              
            putLeft = true;
        }else {
            int x = a[pl], y = a[pr];
            if      (x < y) putLeft = true;
            else if (y < x) putLeft = false;
            else {                          
                int gapL = pl - L;
                int gapR = R - pr;
                putLeft = (gapL <= gapR);
            }
        }
        if (putLeft) {
            a[L] = cur;   
            ++L;
        } else {
            a[R] = cur;  
            --R;
        }
        ++cur;
    }
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    return 0;
}