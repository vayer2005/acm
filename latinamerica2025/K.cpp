#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k; string s;
    cin >> k >> s;
    int n = s.size();
    if (k == 2) {
        //010101
        string s2 = s;
        int t1 = 0;
        if (s2[0] == '1') {
            t1++;
        }
        s2[0] = '0';
        for (int i = 1; i < n; i++) {
            if (s2[i] == s2[i-1]) {
                t1++;
            }
            if (s2[i-1] == '0') s2[i] = '1';
            else s2[i] = '0';
        }

        int t2 = 0;
        string s3 = s;
        if (s3[0] == '0') {
            t2++;
        }
        s3[0] = '1';
        for (int i = 1; i < n; i++) {
            if (s3[i] == s3[i-1]) {
                t2++;
            }
            if (s3[i-1] == '0') s3[i] = '1';
            else s3[i] = '0';
        }

        if (t1 < t2) {
            cout << t1 << " " << s2 << endl;
        } else {
            cout << t2 << " " << s3 << endl;
        }
        return 0;

    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && s[j] == s[i]) j++;
        j--;
        //cout << i << " " << j << endl;
        if (j-i+1 >= k) {
            int change = i + k - 1;
            //cout << change << endl;
            while (change < j) {
                if (s[change] == '0') s[change] = '1';
                else s[change] = '0';
                res++;
                change += k;
            } 
            if (change == j) {
                if (s[change-1] == '0') s[change-1] = '1';
                else s[change-1] = '0';
                res++;
            }
        }   
        i = j;
    }
    cout << res << " " << s << endl;


    
    
}