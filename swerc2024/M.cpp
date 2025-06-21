#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


int main() {
    string w;
    cin >> w;
    int i = 0;

    while (i < w.size()) {
        if (w.substr(i,1) == "O") {
            cout << ".-.-";
            i += 1;
        } else {
            cout << ".-";
            i+=1;
        }
    }
    cout << endl;
}


