#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int arr[n];

    for (int i=0; i < n; i++) {
        cin >> arr[i];
    }

    int paints = 0;
    for(int i = 0; i < n; i++) {
        for (int j = i-1; j >= -1; j--) {
            if (j == -1) {
                paints += 1;
                break;
            }
            if (arr[j] < arr[i]) {
                paints += 1;
                break;
            }
            if (arr[j] == arr[i]) {
                break;
            }
        }
    }

    cout << paints << endl;



}