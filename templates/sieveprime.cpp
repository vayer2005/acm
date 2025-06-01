#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 6e6;
 
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  vector<int> p, ip(N, 1);
  for (int i = 2; i < N; ++i) {
    if (!ip[i]) continue;
    p.push_back(i);
    for (int j = i; j < N; j += i) {
      ip[j] = 0;
    }
  }
}