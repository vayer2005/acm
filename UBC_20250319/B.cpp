#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;



int main() {
    vector<vector<char>> nums = {
            {'G','G','G','g','G','G','G'},
            {'g','g','g','g','g','G','G'},
            {'g','G','G','G','G','G','g'},
            {'g','g','G','G','G','G','G'},
            {'G','g','g','G','g','G','G'},
            {'G','g','G','G','G','g','G'},
            {'G','G','G','G','G','g','G'},
            {'g','g','G','g','g','G','G'},
            {'G','G','G','G','G','G','G'},
            {'G','g','G','G','G','G','G'},

    };

    int n;
    cin >> n;
    for(int k = 0; k < n; k++) {
        string s; 
        cin >> s;
        bool cans[10] = {true, true, true, true, true, true, true, true, true, true};
        for(int j = 0; j < 10; j++) {
            vector<char> num = nums[j];
            //Can it be this num?

            for (int i = 0; i < 7; i++) {
                if ((num[i] == 'G' && s[i] == 'g') || (num[i] == 'g' && s[i] == 'G')) {
                    cans[j] = false;
                    break;
                }
            }

        }
        int numcans = 0;
        for (int i = 0; i < 10; i++) {
            if (cans[i]) {
                numcans+=1;
            }
        }
        if (numcans != 1) {
            cout << "*";
        } else {
            for(int i = 0; i < 10; i++) {
                if (cans[i]) {
                    cout << i;
                    break;
                }
            }
        }
    }
    cout << endl;
}




