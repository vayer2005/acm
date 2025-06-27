#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    string names[n];

    map<string, int> ln;
    string st;
    vector<string> sur;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, st);
        names[i] = st;
    }

    
    for (int i = 0; i < n; i++) {
        string s = names[i];
        int start;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '\'' || s[i] == ' ') continue;
            if ((s[i]-'A' >= 0) && (s[i] - 'A' < 26)) {
                start = i;
                break;
            }
        }
        string lastN = s.substr(start);
        //cout << lastN << endl;
        sur.push_back(lastN);
        ln[lastN] = i;

    }

    sort(sur.begin(), sur.end());

    for (string x : sur) {
        //cout << st << endl;
        cout << names[ln[x]] << endl;
    }
    cout << endl;
    

}