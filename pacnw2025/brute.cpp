#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
long long brute(const vector<int>& a){
    int n=a.size()-1; long long ans=0;
    for(int L=1; L<=n; ++L){
        for(int R=L; R<=n; ++R){
            int best=1e9;
            unordered_map<int,int> last;
            for(int i=L;i<=R;++i){
                auto it=last.find(a[i]);
                if(it!=last.end()) best=min(best, i - it->second);
                last[a[i]]=i;
            }
            if(best==1e9) best=0;
            ans+=best;
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int T; if(!(cin>>T)) return 0; while(T--){int n;cin>>n; vector<int>a(n+1); for(int i=1;i<=n;++i)cin>>a[i]; cout<<brute(a)<<"\n";} }
