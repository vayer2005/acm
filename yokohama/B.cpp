#include <bits/stdc++.h>
#define mp make_pair
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)

using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int64_t a; int64_t b;
    cin >> a >> b;

    
    if (a == b) {
        cout << a << endl;
        return 0;
    }


    int i = 63;
    int64_t ans = 0;
    /*
    cout << ((a >> 3)&1) << endl;
    cout << ((b >> 3)&1) << endl;
    */
    for (int i = 63; i >= 0; i--) {
        if (((a >> i)&1) == ((b >> i)&1)) {
            ans |= (((int64_t)((a >> i)&1)) << i);
        } else {
            for (int64_t j = i; j >= 0; j--) {
                if (getbit(a,j)) {
                    if (ans + bit(j) == a) {
                        ans += bit(j);
                    } else {
                        ans += bit(j+1);
                    }
                    break;
                }
            }
            break;
        }
    }

    cout << ans << endl;

    


    

}