#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    string s;
    cin >> s;

    int v = 0;
    int co = 0;
    int y = 0;
    int g = 0;
    int n = 0;

    for (char c : s) {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') v++;
        else if (c == 'Y') y++;
        else if (c == 'G') g++;
        else if (c  == 'N') n++;
        else co++;
    }

    int curr = min(v, co/2);
    int maxLength = 0;
    
    for (int ngUsed = 0; ngUsed <= min(n, g); ngUsed++) {
        int remN = n - ngUsed;
        int remG = g - ngUsed;

        for (int yVowel = 0; yVowel <= y; yVowel++) {
            int yConsonant = y - yVowel;

            int totalVowels = v + yVowel;
            int totalConsonants = co + yConsonant + ngUsed + remG + remN;

            int syllables = min(totalVowels, totalConsonants / 2);

            int length = 3 * syllables + min(2 * syllables, ngUsed);

            maxLength = max(maxLength, length);
        }

    }

    cout << maxLength << endl;




}   