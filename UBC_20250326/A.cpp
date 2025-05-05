#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


int main() {
    int r; int c; int n; int p;

    cin >> r >> c >> n >> p;

    int arr[r][c];
    

    for (int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    set<int> vis;
    for (int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if (arr[i][j] <= p && arr[i][j] != 0){
                int step = p - arr[i][j];
                
                if (i > 0 && arr[i-1][j] != 0) {
                    if (arr[i-1][j] + step <= n) {
                        vis.insert(arr[i-1][j] + step);
                    }
                }

                if (j > 0 && arr[i][j-1] != 0) {
                    if (arr[i][j-1] + step <= n) {
                        vis.insert(arr[i][j-1] + step);
                    }
                }

                if (i < r-1 && arr[i+1][j] != 0) {
                    if (arr[i+1][j] + step <= n) {
                        vis.insert(arr[i+1][j] + step);
                    }
                }

                if (j < c - 1 && arr[i][j+1] != 0) {
                    if (arr[i][j+1] + step <= n) {
                        vis.insert(arr[i][j+1] + step);
                    }
                }
            }
        }
    }


    cout << vis.size() << "/" << n-1 << endl;



}