#include <bits/stdc++.h>
 
using namespace std; 
#define int long long
#define double long double


struct Group {
    int weight;
    int num;
    double pos;
    int nxt;
    int prev;

    Group(int w, int n, double p) {
        weight = w;
        num = n;
        pos = p;
        nxt = -1;
        prev = -1;
    }
};


void solve() {
    int n;
    cin >> n;
    int torq = 0;

    vector<int> p(n);
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> w[i];

        torq += p[i] * w[i];
    }

    if (torq > 0) {
        torq = -torq;

        for (int i = 0; i < n; i++) {
            p[i] = -p[i];
        }
        reverse(p.begin(), p.end());
        reverse(w.begin(), w.end());
    }   

    priority_queue<pair<double, int>> pq; //weighted av, group idx 

    map<int, Group*> grp;

    for (int i = 0; i < n; i++) {
        grp[i] = new Group(w[i], 1, p[i]);
        pq.push({w[i] * 1.0, i});
    }

    for (int i = 0; i < n-1; i++) {
        grp[i]->nxt = i+1;
    }
    for (int i = 1; i < n; i++) {
        grp[i]->prev = i-1;
    }

    double tor = torq;
    double ans = 0.0;

    while (tor < 0.0) {
        auto cp = pq.top();
        double w = cp.first;
        pq.pop();

        Group* g1 = grp[cp.second];
        
        cout << g1->weight << " " << g1->num << " " << g1->nxt << " " << g1->pos << endl;
        if (g1->nxt == -1) {
            //move this group indefinetly
            //cout << "raj\n";
            double nd = (-1.0 * tor)/w;
            ans += nd * g1->num;
            tor += nd * w;

        } else {
            //merge to par
            double g1p = g1->pos;
            Group* g2 = grp[g1->nxt];

            double g2p = g2->pos;
            double dhave = g2p - g1p;
            double dneed = tor/g1->weight;
            if (dneed > dhave) {
                ans += dhave * g1->num;
                tor += dhave * w;
                g2->weight += g1->weight;
                g2->num += g1->num;
                if (g1->prev != -1) {
                    Group* prv = grp[g1->prev];
                    prv->nxt = g1->nxt;
                    
                }
                g2->prev = g1->prev;
                double ncomp = (double)g2->weight/g2->num;
                pq.push({ncomp, g1->nxt});
            } else {
                ans += dneed * g1->num;
                tor += dneed * g1->weight;
            }
            
        }
    }

    cout << fixed << setprecision(10) << ans << endl;





}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    
    return 0;
 
}