#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<string> days;
int d, h;
int sol = 0;

void dfs(vector<int> used, int ind) {
    
    if (used.size() == d) {
        vector<int> app(24,0);
        for (int i : used) {
            for (int j = 0; j < 24; j++) {
                if (days[i][j] == '.') app[j]+=1;
            }
        }
        sort(app.begin(), app.end());
        int num = 0;
        reverse(app.begin(), app.end());
        for (int i = 0; i < h; i++) {
            num += app[i];
        }
        sol = max(sol, num);
    } else {
        if (ind >= 7) return;
        dfs(used, ind+1);
        used.push_back(ind);
        dfs(used, ind+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    for (int i = 0; i < 7;i++) {
        cin >> s;
        days.push_back(s);
    }

    cin >> d >> h;

    dfs({}, 0);

    double fin = (double)(sol)/(double)(h*d);
    cout << fixed << setprecision(10) << fin << endl;
}