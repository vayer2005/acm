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
    int amt;
    // Used for indicating ending of string
    bool isLeaf;

    TrieNode() {
      
        // initialize the wordEnd variable with false
        // initialize every index of childNode array with NULL
        isLeaf = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        amt = 0;
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
        // Move the curr pointer to the newly created/existing node
        curr = curr->children[c - 'a'];
        // Increment at the node representing this prefix
        curr->amt++;
    }

    // Mark the end of the word
    curr->isLeaf = true;
}

int search(TrieNode* root, string key) {

    TrieNode* curr = root;
    for (char c : key) {
        int idx = c - 'a';
        if (!curr->children[idx]) return 0;
        curr = curr->children[idx];
    }
    return curr->amt;
}


class AndTrieNode {
public:

    // sparse children: (edge index 0..675, child ptr) kept sorted
    vector<pair<int, AndTrieNode*>> children;
    int amt;

    // Used for indicating ending of string
    bool isLeaf;

    AndTrieNode() {
      
        // initialize the wordEnd variable with false
        // initialize every index of childNode array with NULL
        isLeaf = false;
        children.clear();
        amt = 0;
    }
};

  // Method to insert a key into the Trie
void insert(AndTrieNode *root, string key, string key2)
{

    // Initialize the curr pointer with the root node
    AndTrieNode *curr = root;
    int n = key.size();
    // Iterate across the length of the string
    for (int i = 0; i < n; i++)
    {
        int frst = key[i] - 'a';
        int sec = key2[i] - 'a';
        int idx = frst * 26 + sec;
        // binary search for child
        auto it = lower_bound(curr->children.begin(), curr->children.end(), idx, [](const auto p, int idx) {return p.first < idx;});
        if (it == curr->children.end() || it->first != idx) {
            int pos = (int)(it - curr->children.begin());
            curr->children.insert(it, {idx, new AndTrieNode()});
            it = curr->children.begin() + pos;
        }
        curr = it->second;
        curr->amt++;
    }

    // Mark the end of the word
    curr->isLeaf = true;
}

int search(AndTrieNode* root, string key, string key2) {

    AndTrieNode *curr = root;
    int n = key.size();
    for (int i = 0; i < n; i++)
    {
        int frst = key[i] - 'a';
        int sec = key2[i] - 'a';
        int idx = frst * 26 + sec;
        auto it = lower_bound(curr->children.begin(), curr->children.end(), idx, [](const auto p, int idx) {return p.first < idx;});
        if (it == curr->children.end() || it->first != idx) return 0;
        curr = it->second;
    }

    return curr->amt;
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
        string s2 = "";
        for (int j = s.size()-1; j >= 0; j--) {
            s2 += s[j];
        }
        insert(root, s);
        insert(androot, s, s2);
        insert(revroot, s2);
    }


    string o, suf, pref;

    while (q--) {
        cin >> o >> pref >> suf;
        string rsuf = suf;
        reverse(rsuf.begin(), rsuf.end());

        int pnum = search(root, pref);
        int snum = search(revroot, rsuf);
        int andnum = search(androot, pref, rsuf);
    
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