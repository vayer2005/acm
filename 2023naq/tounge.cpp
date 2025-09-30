#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define int long long
using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
const int mod = 1e9+7;
const int NUM = 1e6+5; 
const int N = 2e5+5;
const double EPS = 1e-9;
const int INF = 1e9 + 13;
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
 
 
vector<int> lp, sieve;
vector<int> pr;
vi pow2(2e5+1, 0);
vector<int> power;
vector<int> fact(2e5 + 5, 0);
vector<int> inv_fact(2e5 + 5, 0);


class TrieNode {
public:

    // pointer array for child nodes of each node
    TrieNode* children[26];

    // Used for indicating ending of string
    bool isLeaf;

    TrieNode() {
      
        // initialize the wordEnd variable with false
        // initialize every index of childNode array with NULL
        isLeaf = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

  // Method to insert a key into the Trie
void insert(TrieNode *root, string key)
{

    // Initialize the curr pointer with the root node
    TrieNode *curr = root;

    // Iterate across the length of the string
    for (char c : key)
    {

        // Check if the node exists for the
        // current character in the Trie
        if (curr->children[c - 'a'] == nullptr)
        {

            // If node for current character does
            // not exist then make a new node
            TrieNode *newNode = new TrieNode();

            // Keep the reference for the newly
            // created node
            curr->children[c - 'a'] = newNode;
        }

        // Move the curr pointer to the
        // newly created node
        curr = curr->children[c - 'a'];
    }

    // Mark the end of the word
    curr->isLeaf = true;
}

TrieNode* search(TrieNode* root, string key) {

    TrieNode* curr = root;
    for (char c : key) {
        if (curr == nullptr) return nullptr;
        if (curr->children[c-'a']) {
            curr = curr->children[c-'a'];
        }
    }
    return curr;
}


class AndTrieNode {
public:

    // pointer array for child nodes of each node
    AndTrieNode* children[676];

    // Used for indicating ending of string
    bool isLeaf;

    AndTrieNode() {
      
        // initialize the wordEnd variable with false
        // initialize every index of childNode array with NULL
        isLeaf = false;
        for (int i = 0; i < 676; i++) {
            children[i] = nullptr;
        }
    }
};

  // Method to insert a key into the Trie
void insert(AndTrieNode *root, string key)
{

    // Initialize the curr pointer with the root node
    AndTrieNode *curr = root;
    int n = key.size();
    // Iterate across the length of the string
    for (int i = 0; i < n; i++)
    {

        int frst = key[i] - 'a';
        int sec = key[n-i-1] - 'a';
        int idx = frst * 26 + sec;
        // Check if the node exists for the
        // current character in the Trie
        if (curr->children[idx] == nullptr)
        {

            // If node for current character does
            // not exist then make a new node
            AndTrieNode *newNode = new AndTrieNode();

            // Keep the reference for the newly
            // created node
            curr->children[idx] = newNode;
        }

        // Move the curr pointer to the
        // newly created node
        curr = curr->children[idx];
    }

    // Mark the end of the word
    curr->isLeaf = true;
}

AndTrieNode* search(AndTrieNode* root, string key) {

    AndTrieNode *curr = root;
    int n = key.size();
    // Iterate across the length of the string
    for (int i = 0; i < n; i++)
    {
        int frst = key[i] - 'a';
        int sec = key[n-i-1] - 'a';
        int idx = frst * 26 + sec;
        if (curr->children[idx]) {
            curr = curr->children[idx];
        }
    }

    return curr;
}

map<AndTrieNode*, int> andCnt;
map<TrieNode*, int> normCnt;
map<TrieNode*, int> revCnt;

int dfs(TrieNode* node) {
    int sz = 0;
    if (node->isLeaf) sz++;
    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            sz += dfs(node->children[i]);
        }
    }

    normCnt[node] = sz;
    return sz;
}

int dfs2(TrieNode* node) {
    int sz = 0;
    if (node->isLeaf) sz++;
    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            sz += dfs2(node->children[i]);
        }
    }

    revCnt[node] = sz;
    return sz;
}

int dfs3(AndTrieNode* node) {
    int sz = 0;
    if (node->isLeaf) sz++;
    for (int i = 0; i < 676; i++) {
        if (node->children[i]) {
            sz += dfs3(node->children[i]);
        }
    }

    andCnt[node] = sz;
    return sz;
}

void solve() {
    int n, q;
    cin >> n >> q;
    TrieNode* root = new TrieNode();
    TrieNode* revroot = new TrieNode();
    AndTrieNode* androot = new AndTrieNode();

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        insert(root, s);
        insert(androot, s);
        reverse(s.begin(), s.end());
        insert(revroot, s);
    }

    dfs(root);
    dfs2(revroot);
    dfs3(androot);

    string o, suf, pref;

    while (q--) {
        cin >> o >> suf >> pref;

        TrieNode* p1 = search(root, pref);
        TrieNode* p2 = search(revroot, suf);
        string r = pref + suf;
        AndTrieNode* a1 = search(androot, r);
        int pnum = 0;
        int snum = 0;
        int andnum = 0;
        if (p1 != nullptr) pnum = normCnt[p1];
        if (p2 != nullptr) snum = revCnt[p2];
        if (a1 != nullptr) andnum = andCnt[a1];

        if (o == "AND") {
            cout << andnum << endl;
        } else if (o == "OR") {
            cout << pnum + snum - andnum << endl;
        } else {
            cout << pnum + snum - 2*andnum << endl;
        }
    }

    

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}