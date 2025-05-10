#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n,m;cin>>n>>m;
    map<ll,ll>cnt;


    vector<ll>a(n),r(n);
    for(ll&i:a)cin>>i;
    for(ll&i:r)cin>>i;

    for(int i=0;i<n;i++)
    {
        ll aa=a[i],rr=r[i];
        for(ll x=aa-rr;x<=aa+rr;x++)
        {
            cnt[x]=max(cnt[x],2 * ((ll)sqrtl(rr*rr-(x-aa)*(x-aa)))+1);
        }
    }
    ll ans=0;
    for(auto[x,c]:cnt)ans+=c;
    cout<<ans<<"\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}