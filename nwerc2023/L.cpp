#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int grid[n+1][n+1];
    set<pair<int,int>> mark;
    for (int i = 1; i <= n; i++) {
        if ((i%5) == 1) {
            int x = i; int y = 1;
            while (x <= n && y <= n) {
                mark.insert({x,y});
                x+=1;
                y+=1;
            }
        }
    }

    for (int j = 2; j <= n; j++) {
        if ((j%5) == 1) {
            int x = 1; int y = j;
            while (x <= n && y <= n) {
                mark.insert({x,y});
                x+=1;
                y+=1;
            }
        }
    }

    

    int ct = 0;

    int seen[n+1][n+1];
    memset(seen, -1, sizeof(seen));

    for (auto p : mark) {
        if (seen[p.first][p.second] == 0) continue;
        string res = "hit";
        if (seen[p.first][p.second] == -1) {
            cout << p.first << " " << p.second << endl;
            cout.flush();
            cin >> res;
            seen[p.first][p.second] = (res == "hit" || res == "sunk") ? 1 : 0;
            
        }
        if (res == "sunk") ct++;
        if (ct == k) return 0;
        if (res == "hit") {
            //up
            int x = p.first;
            int y = p.second-1;
            
            while (y >= 1) {
                res = "hit";
                if (seen[x][y] == 0) break;
                if (seen[x][y] == -1) {
                    cout << x << " " << y << endl;
                    cout.flush();
                    cin >> res;
                    seen[x][y] = (res == "hit" || res == "sunk") ? 1 : 0;
                }
                if (res == "sunk") ct++;
                if (ct == k) return 0;
                if (res != "hit") break;
                y--;
            }

            x = p.first;
            y = p.second+1;
            while (y <= n) {
                res = "hit";
                if (seen[x][y] == 0) break;
                if (seen[x][y] == -1) {
                    cout << x << " " << y << endl;
                    cout.flush();
                    cin >> res;
                    seen[x][y] = (res == "hit" || res == "sunk") ? 1 : 0;
                }
                if (res == "sunk") ct++;
                if (ct == k) return 0;
                if (res != "hit") break;
                y++;
            }
            
            x = p.first-1;
            y = p.second;
            while (x >= 1) {
                res = "hit";
                if (seen[x][y] == 0) break;
                if (seen[x][y] == -1) {
                    cout << x << " " << y << endl;
                    cout.flush();
                    cin >> res;
                    seen[x][y] = (res == "hit" || res == "sunk") ? 1 : 0;
                }
                if (res == "sunk") ct++;
                if (ct == k) return 0;
                if (res != "hit") break;
                x--;
            }

            x = p.first+1;
            y = p.second;
            while (x <= n) {
                res = "hit";
                if (seen[x][y] == 0) break;
                if (seen[x][y] == -1) {
                    cout << x << " " << y << endl;
                    cout.flush();
                    cin >> res;
                    seen[x][y] = (res == "hit" || res == "sunk") ? 1 : 0;
                }
                if (res == "sunk") ct++;
                if (ct == k) return 0;
                if (res != "hit") break;
                x++;
            }
        }
    }



    
}