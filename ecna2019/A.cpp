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
    int n, m, p;
    cin >> n >> m >> p;
 
    pair<int,int> judge[n];
    pair<int,int> tar[m];
    pair<int,int> feat[p];
 
    for (int i = 0; i < n; i++) {
        cin >> judge[i].first >> judge[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin >> tar[i].first >> tar[i].second;
    }
    for (int i = 0; i < p; i++) {
        cin >> feat[i].first >> feat[i].second;
    }

    set<pair<int,pair<int,int>>> l1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int d = dist(judge[i].first, tar[j].first, judge[i].second, tar[j].second);
            l1.insert({d, {i,j}});
        }
    }

    set<int> seenj;
    set<int> seent;
    double total = 0;
    while (!l1.empty()) {
        auto x = *l1.begin();
        int jud = x.second.first;
        int tr = x.second.second;
        l1.erase(x);
        if (seenj.find(jud) != seenj.end() || seent.find(tr) != seent.end()) continue;
        total += sqrt(x.first);
        seenj.insert(jud);
        seent.insert(tr);

    }

    set<pair<int,pair<int,int>>> l2;
    seenj.clear();
    set<int> seenf;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            int d = dist(judge[i].first, feat[j].first, judge[i].second, feat[j].second);
            l2.insert({d, {i,j}});
        }
    }

    while (!l2.empty()) {
        auto x = *l2.begin();
        int jud = x.second.first;
        int fr = x.second.second;
        l2.erase(x);
        if (seenj.find(jud) != seenj.end() || seenf.find(fr) != seenf.end()) continue;
        total += sqrt(x.first);
        seenj.insert(jud); seenf.insert(fr);

    }

    
    cout << fixed << setprecision(10) << total << endl;
}