#include <bits/stdc++.h>

using namespace std;
int n;

int lis(vector<string>& vec, string order) {
    //ordering = "SWER";
    int s, w, e, r;
    int c=4;
    vector<int> ans;

    for (int i = 0; i < 4; i++) {
        char c = order[i];
        if (c == 'S') {
            s = i;
        } else if (c == 'W') {
            w = i;
        } else if (c == 'E') {
            e = i;
        } else {    
            r = i;
        }
    }

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        char c1 = vec[i][0];
        int ci1;
        int i1 = stoi(vec[i].substr(1));

        if (c1 == 'S') ci1 = s;
        else if (c1 == 'W') ci1= w;
        else if (c1 == 'E') ci1 = e;
        else if (c1 == 'R') ci1 = r;
        else ci1 = c;

        arr.push_back(ci1 * n + i1);
    }

    ans.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i] > ans.back()) {
            ans.push_back(arr[i]);
        }
        else {
            int low = lower_bound(ans.begin(), ans.end(),
                                  arr[i])
                      - ans.begin();
            ans[low] = arr[i];
        }
    }
    return ans.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<string> cards;

    string s;
    for (int i=0; i < n; i++) {
        cin >> s;
        cards.push_back(s);
    }

    int ans = 0;

    string st = "SWER";
    sort(st.begin(), st.end());

    vector<string> perm;

    do {
        perm.push_back(st);
    } while (next_permutation(st.begin(), st.end()));

    for (string x : perm) {
        ans=max(ans, lis(cards, x));
    }

    cout << n-ans << endl;





}