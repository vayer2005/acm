#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = int(1e9) + 7;

typedef vector<vector<int>> matrix;
void mul(matrix& ret, const matrix& a, const matrix& b) {
  ret.resize(a.size());
  for(int i = 0; i < ret.size(); i++) {
    ret[i].resize(b[0].size());
    for(int j = 0; j < ret[i].size(); j++) {
      for(int k = 0; k < b.size(); k++) {
        ret[i][j] += (a[i][k] * (int64_t)b[k][j]) % MOD;
        if(ret[i][j] >= MOD) ret[i][j] -= MOD;
      }
    }
  }
}
void pow(matrix& r, matrix b, int64_t e) {
  for(int i = 0; i < r.size(); i++) {
    fill(r[i].begin(), r[i].end(), 0);
    r[i][i] = 1;
  }
  while(e) {
    if(e%2) {
      matrix nr;
      mul(nr, r, b);
      r.swap(nr);
    }
    e /= 2;
    if(e) {
      matrix nb;
      mul(nb, b, b);
      b.swap(nb);
    }
  }
}

int main() {
  int64_t len;
  int residue;
  scanf("%lld %d", &len, &residue);
  if(len == 1) {
    if(residue < 10) printf("1\n");
    else printf("0\n");
    return 0;
  }
  if(len == 2){
    if(residue >= 10 && residue<100 && residue%11 != 0){
      printf("1\n");
    }
    else{
      printf("0\n");
    }
    return 0;
  }
  matrix iter(90);
  for(auto& x: iter) x.resize(90);
  for(int i = 0; i < 90; i++) {
    int mod = i / 10;
    int dig = i % 10;
    for(int j = 0; j < 10; j++) {
      if(dig != j) {
        int nmod = (mod + j);
        if(nmod >= 9) nmod -= 9;
        iter[i][(10 * nmod) + j]++;
      }
    }
  }
  pow(iter, iter, len - 2);
  int ret = 0;
  int ninemod = residue % 9;
  int mod25 = residue % 25;
  while(mod25 < 100) {
    if(mod25/10 != mod25%10) {
      int src = (10 * (mod25%9)) + (mod25/10);
      for(int dig = 1; dig <= 9; dig++) {
        int dst = (10 * ninemod) + dig;
        ret += iter[src][dst];
        if(ret >= MOD) ret -= MOD;
      }
    }
    mod25 += 25;
  }
  printf("%d\n", ret);
}
