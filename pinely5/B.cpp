#include <bits/stdc++.h>
 
 
#define int long long
 
using namespace std;
 
 
 
void solve() {
    
    int n;
    cin >> n;
 
    vector<string> grid;
 
    string s1;
 
    queue<vector<int>> q;
    for (int i = 0; i < n; i++) {
        cin >> s1;
        grid.push_back(s1);
    }
 
    
 
    for (int j = 0; j < n; j++) {
        vector<string> b1;
        for (int i = 0; i < n; i++) {
            string s(n,'.');
            if (i + j < n) s[i+j] = '#';
            if (i+j < n-1) s[i+j+1] = '#';
            b1.push_back(s);
        }
 
        bool works = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '#' && b1[i][j] == '.') {
                    works = false;
                    break;
                }
            }
        }
        
        if (works) {
            cout << "YES\n";
            return;
        }
    }
 
    for (int j = 0; j < n; j++) {
        vector<string> b1;
        for (int i = 0; i < n; i++) {
            string s(n,'.');
            if (n-i-j-1 >= 0) s[n-i-j-1] = '#';
            if (n-i-j >= 0 && n-i-j < n) s[n-i-j] = '#';
            b1.push_back(s);
        }
 
        bool works = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '#' && b1[i][j] == '.') {
                    works = false;
                    break;
                }
            }
        }
        
        if (works) {
            cout << "YES\n";
            return;
        }
    }
 
    for (int j = 0; j < n; j++) {
        vector<string> b1;
        for (int i = 0; i < n; i++) {
            string s(n,'.');
            if (n-i-j-1 >= 0) s[i+j] = '#';
            if (n-i-j-2 >= 0) s[n-i-j-2] = '#';
            b1.push_back(s);
        }
 
        bool works = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '#' && b1[i][j] == '.') {
                    works = false;
                    break;
                }
            }
        }
        
        if (works) {
            cout << "YES\n";
            return;
        }
    }
 
    for (int j = 0; j < n; j++) {
        vector<string> b1;
        for (int i = 0; i < n; i++) {
            string s(n,'.');
            if (i + j < n) s[i+j] = '#';
            if (i+j-1 < n && i+j-1 >= 0) s[i+j-1] = '#';
            b1.push_back(s);
        }
 
        bool works = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '#' && b1[i][j] == '.') {
                    works = false;
                    break;
                }
            }
        }
        
        if (works) {
            cout << "YES\n";
            return;
        }
    }
    
    int used = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (grid[i][j] == '#') used++;
    }
 
 
    if (used <= 4) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int h = 0;
                if (grid[i][j] == '#') h++;
                if (i + 1 < n && grid[i+1][j] == '#') h++;
                if (j + 1 < n && grid[i][j+1] == '#') h++;
                if (i + 1 < n && j + 1 < n && grid[i+1][j+1] == '#') h++;
                if (h == used) {
                    cout << "YES\n";
                    return;
                }
            }
            
        }
    }
 
    cout << "NO\n";
 
 
 
 
 
 
 
}
 
signed main() {
    int t;
    cin >> t;
 
    while(t--) {
        solve();
    }
}