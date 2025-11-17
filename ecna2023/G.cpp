#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double

signed main() {
    int nt, ns, rmax;

    cin >> nt >> ns >> rmax;

    vector<int> tx(nt);
    vector<int> ty(nt);

    set<pair<int,int>> trees;

    vector<int> sx(ns);
    vector<int> sy(ns);

    set<tuple<int, int, int>> soln;

    for (int i = 0; i < nt; i++) {
        cin >> tx[i] >> ty[i];
        trees.insert({tx[i], ty[i]});
    }

    for (int i = 0; i < ns; i++) {
        cin >> sx[i] >> sy[i];
    }
    
    for (int i = 0; i < ns; i++) {
        if (sx[i] == 0 && sy[i] == 0) {
            cout << "Impossible\n";
            return 0;
        }
    }

    // NORTH
    for (int i = 0; i < nt; i++) {
        set<pair<int,int>> used;
        int xd = tx[i] - sx[0];
        int yd = ty[i] - sy[0];

        used.insert({tx[i], ty[i]});

        bool res = true;
        for (int j = 1; j < ns; j++) {
            int currx = xd + sx[j];
            int curry = yd + sy[j];
            if (trees.find({currx, curry}) != trees.end()) {
                used.insert({currx, curry});
            } else {
                res = false;
                break;
            }
        }

        for (int j = 0; j < nt; j++) {
            int currx = abs(tx[j] - xd);
            int curry = abs(ty[j] - yd);
            if (currx + curry <= rmax && used.find({tx[j], ty[j]}) == used.end()) {
                res = false;
                break;
            }
        }

        if (res == true) {
            soln.insert({xd, yd, 1});
        }

    }


    // EAST
    for (int i = 0; i < nt; i++) {
        set<pair<int,int>> used;
        int xd = tx[i] - sy[0];
        int yd = ty[i] + sx[0];

        used.insert({tx[i], ty[i]});

        bool res = true;
        for (int j = 1; j < ns; j++) {
            int currx = xd + sy[j];
            int curry = yd - sx[j];
            if (trees.find({currx, curry}) != trees.end()) {
                used.insert({currx, curry});
            } else {
                res = false;
                break;
            }
        }

        for (int j = 0; j < nt; j++) {
            int currx = abs(tx[j] - xd);
            int curry = abs(ty[j] - yd);
            if (currx + curry <= rmax && used.find({tx[j], ty[j]}) == used.end()) {
                res = false;
                break;
            }
        }

        if (res == true) {
            soln.insert({xd, yd, 2});
        }

    }

    //SOUTH

     for (int i = 0; i < nt; i++) {
        set<pair<int,int>> used;
        int xd = tx[i] + sx[0];
        int yd = ty[i] + sy[0];

        used.insert({tx[i], ty[i]});

        bool res = true;
        for (int j = 1; j < ns; j++) {
            int currx = xd - sx[j];
            int curry = yd - sy[j];
            if (trees.find({currx, curry}) != trees.end()) {
                used.insert({currx, curry});
            } else {
                res = false;
                break;
            }
        }

        for (int j = 0; j < nt; j++) {
            int currx = abs(tx[j] - xd);
            int curry = abs(ty[j] - yd);
            if (currx + curry <= rmax && used.find({tx[j], ty[j]}) == used.end()) {
                res = false;
                break;
            }
        }

        if (res == true) {
            soln.insert({xd, yd, 3});
        }

    }

    // WEST

      for (int i = 0; i < nt; i++) {
        set<pair<int,int>> used;
        int xd = tx[i] + sy[0];
        int yd = ty[i] - sx[0];

        used.insert({tx[i], ty[i]});

        bool res = true;
        for (int j = 1; j < ns; j++) {
            int currx = xd - sy[j];
            int curry = yd + sx[j];
            if (trees.find({currx, curry}) != trees.end()) {
                used.insert({currx, curry});
            } else {
                res = false;
                break;
            }
        }

        for (int j = 0; j < nt; j++) {
            int currx = abs(tx[j] - xd);
            int curry = abs(ty[j] - yd);
            if (currx + curry <= rmax && used.find({tx[j], ty[j]}) == used.end()) {
                res = false;
                break;
            }
        }

        if (res == true) {
            soln.insert({xd, yd, 4});
        }

    }

    if (soln.size() == 0) {
        cout << "Impossible\n";
    } else if (soln.size() == 1) {
        cout << get<0>(*soln.begin()) << " " << get<1>(*soln.begin()) << endl;
    } else {
        cout << "Ambiguous\n";
    }

}
