#include <bits/stdc++.h>
using namespace std;

// loser -> winner
unordered_map<string,string> parent;
unordered_map<string,int> depth;
unordered_set<string> allTeams;

int getDepth(const string &v){
    auto it = depth.find(v);
    if(it!=depth.end() && it->second!=-1) return it->second;
    string par = parent.count(v)? parent[v]: string();
    int d = par.empty()? 0 : getDepth(par)+1;
    depth[v] = d;
    return d;
}

auto getPar=[&](const string &x)->string{
    return parent.count(x)? parent[x]: string();
};
auto lca=[&](string u,string v){
    while(getDepth(u)>getDepth(v)) u=getPar(u);
    while(getDepth(v)>getDepth(u)) v=getPar(v);
    while(u!=v){ u=getPar(u); v=getPar(v);}
    return u;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;
    cin.ignore();
    string st;
    string s;

    
    for (int i = 0; i < pow(2,k)-1; i++) {
        getline(cin, st);
        string s;
        stringstream ss(st);
        vector<string> v;
        while (getline(ss, s, ' ')) {
            v.push_back(s);
        }

        if (v[1].find("(") != string::npos) {
            auto first = v[1].find("(");
            auto last = v[1].find(")");
            string v1score = v[1].substr(first+1,last-first);
            first = v[3].find("(");
            last = v[3].find(")");
            string v2score = v[3].substr(first+1, last - first);
            int score1 = stoi(v1score);
            int score2 = stoi(v2score);
            if (score1 > score2) {
                parent[v[4]] = v[0];
            } else {
                parent[v[0]] = v[4];
            }
        } else {
            int score1 = stoi(v[1]);
            int score2 = stoi(v[3]);
            if (score1 > score2) {
                parent[v[4]] = v[0];
            } else {
                parent[v[0]] = v[4];
            }
        }
        allTeams.insert(v[0]);
        allTeams.insert(v[4]);
    }

    string champion;
    for(const string &name: allTeams){
        if(!parent.count(name)){ champion=name; break; }
        depth[name]=-1;
    }
    depth[champion]=0;
    for(const string &name: allTeams) getDepth(name);

    while(n--){
        string A,B;cin>>A>>B;
        string anc=lca(A,B);
        cout<<k - depth[anc]<<"\n";
    }
    return 0;
}