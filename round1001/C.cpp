#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n; 
    cin >> n;
    vector<ll> nums;
    ll num;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
        sum += num;
    }
    ll maxsum = sum;
    ll sum2;
    while (nums.size() > 1) {
        vector<ll> newnums = {};
        sum = 0;
        sum2 =0;
        
        for(int i = nums.size()-1; i >= 1; i--) {
            newnums.push_back((ll)(nums[i-1] - nums[i]));
            sum += (ll)(nums[i-1] - nums[i]);
            sum2 += (ll)(nums[i] - nums[i-1]);
        }
        maxsum = max({maxsum, sum, sum2});
        nums.clear();
        nums = newnums;
    }

    cout << max(maxsum, nums[0]) << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}