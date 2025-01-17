#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {

}

int main() {
    int n;
    cin >> n;
    int arr[n-1];
    int currNum = n;
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }

    vector<int> rev;
    rev.push_back(currNum);
    while (arr[currNum-2] != 1) {
        rev.push_back(arr[currNum-2]);
        currNum = arr[currNum-2];
    }
    rev.push_back(1);
    reverse(rev.begin(), rev.end());
    for(int i = 0; i < rev.size(); i++){
        cout << rev[i] << " ";
    }
    cout << endl;

}