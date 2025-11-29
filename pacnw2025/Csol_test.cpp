#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

#define int long long

signed main() {  
    int n;
    cin >> n;
    vector<int> a(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Stack stores (score, upto) pairs where score is the f value
    // and upto is the rightmost start index L that has this score
    stack<pair<int, int>> st;
    
    // Map to track the most recent occurrence of each value
    map<int, int> last_pos;
    
    int total = 0;  // Total sum of f over all subarrays
    int running_sum = 0;  // Sum of f for all subarrays ending at current r
    
    for (int r = 1; r <= n; r++) {
        int val = a[r];
        
        // If this value appeared before, process the most recent occurrence
        if (last_pos.find(val) != last_pos.end()) {
            int p = last_pos[val];
            int dist = r - p;  // Distance between equal pair
            
            // 1) Trim blocks so that all remaining blocks satisfy upto <= p.
            //    If a block straddles p, shrink it and keep the left part.
            while (!st.empty() && st.top().second > p) {
                pair<int, int> top = st.top();
                st.pop();
                int prev_upto = st.empty() ? 0 : st.top().second;
                if (prev_upto >= p) {
                    // Entire block lies to the right of p → remove fully
                    int block_length = top.second - prev_upto;
                    running_sum -= top.first * block_length;
                    continue;
                } else {
                    // Block crosses p → remove only the right tail and keep left part
                    int tail = top.second - p;
                    running_sum -= top.first * tail;
                    // keep the left segment ending at p
                    top.second = p;
                    st.push(top);
                    break;
                }
            }
            
            // 2) Now all blocks have upto <= p. Ensure top score <= dist by popping
            //    blocks with larger score (they will be improved by dist).
            while (!st.empty() && st.top().first > dist) {
                pair<int, int> top = st.top();
                st.pop();
                
                int prev_upto = st.empty() ? 0 : st.top().second;
                int block_length = top.second - prev_upto;
                running_sum -= top.first * block_length;
            }
            
            // 3) Fill the range up to p appropriately.
            if (st.empty()) {
                // No blocks left: entire prefix 1..p gets value = dist.
                if (p > 0) {
                    running_sum += dist * p;
                    st.push({dist, p});
                }
            } else {
                if (st.top().first >= dist) {
                    // New score is <= current top score → resulting score for ≤ p is dist.
                    if (st.top().first == dist) {
                        int old_upto = st.top().second;
                        int delta = p - old_upto;
                        if (delta > 0) {
                            running_sum += dist * delta;
                            st.top().second = p;
                        }
                    } else { // st.top().first > dist (shouldn't happen due to while, but safe)
                        int prev_upto = st.top().second;
                        int block_length = p - prev_upto;
                        if (block_length > 0) {
                            running_sum += dist * block_length;
                            st.push({dist, p});
                        }
                    }
                } else {
                    // dist is worse (> top score): the tail (top.upto, p] should get value = dist.
                    int prev_upto = st.top().second;
                    int block_length = p - prev_upto;
                    if (block_length > 0) {
                        running_sum += dist * block_length;
                        st.push({dist, p});
                    }
                }
            }
        }
        
        // Add the running sum for all subarrays ending at r
        total += running_sum;
        
        // Update the most recent occurrence of this value
        last_pos[val] = r;
    }
    
    cout << total << endl;
    
    return 0;
}