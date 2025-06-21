#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    int n;
    cin >> n;

    vector<pair<int,int>> pt;
    int minY = 1e9+100;
    int minX = 1e9+100;
    int x,y;
    bool diffX = false;
    bool diffY = false;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        pt.push_back({x,y});
        minY = min(minY, y);
        minX = min(minX, x);
    }

    sort(pt.begin(), pt.end());

    int seenX = pt[0].first; int seenY = pt[0].second;
    for (int i = 1; i < n; i++) {
        if (pt[i].first != seenX) diffX = true;
        if (pt[i].second != seenY) diffY = true;
    }


    //EDGE Cases
    if (!diffX) {
        if (seenX == 1) {
            //Vertical @ X = 1
            cout << n+1 << endl;
            cout << "2 1\n";
            for (auto v : pt) {
                cout << v.first << " " << v.second << endl;
            }
            return 0;
        }
    }
    if (!diffY) {
        if (seenY == 1000000000) {
            //Horiz @ Y = 1e9
            cout << n+1 << endl;
            cout << "1 999999999\n";
            for (auto v : pt) {
                cout << v.first << " " << v.second << endl;
            }
            return 0;
        }
    }


    int i = 0;

    stack<pair<int,int>> added;
    vector<pair<int,int>> rest;
    int prev = -100;

    pair<int,int> breakpt;
    pair<int,int> last = {-100, -100};

    while (i<n) {
        int currX = pt[i].first;
        vector<int> ys;
        while (i < n && pt[i].first == currX) {
            ys.push_back(pt[i].second);
            i++;
        }
        
        if (i >= n) {
            if (prev != currX -1) {
                added.push({currX-1, minY+1});
            } else {
                added.pop();
            }

            reverse(ys.begin(), ys.end());
            for (int v : ys) {
                added.push({currX, v});
            }

            added.push({currX, minY});
            continue;
        }
    
        added.push({currX, minY+1});

        for (int v : ys) {
            added.push({currX,v});
        }
        added.push({currX + 1, minY+1});

        prev = currX;
        
    }

    vector<pair<int, int>> fin;
   
    while (added.size() != 0) {
        pair<int,int> curr = added.top();
        if (curr.second == minY) {
            rest.push_back(curr);
            added.pop();
            continue;
        }
        added.pop();
        if (curr.first == last.first && curr.second == last.second) continue;
        last = curr;
        fin.push_back({curr.first,curr.second});
    }

    //cout << "REST\n";
    sort(rest.begin(), rest.end());
    
    fin.push_back({minX,minY});

    last = {minX,minY};
    for (auto v : rest) {
        if (v.first == last.first && v.second == last.second) continue;
        last = v;
        fin.push_back({v.first, v.second});
    }

    cout << fin.size() <<endl;

    for (auto r : fin) {
        cout << r.first << " " << r.second << endl;
    }
    

}