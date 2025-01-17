#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<char>> arr;
int snake;
vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
set<int> visited;


int getDist(char x, int len) {
    int curr;
    if (x != '.' && x != 'A' && x != '0') {
        curr = x - '0';
        if (curr >= 49) {
            curr = curr - 39;
        }
        return len - curr;
    }
    return 0;
}

bool dfs(int r, int c, int step) {
    if (r >= arr.size() || r < 0 || c >= arr[0].size() || c < 0) {
        return false;
    }
    if (arr[r][c] == 'A') {
        return true;
    }
    int num = arr[0].size() * r + c;
    if (visited.find(num) != visited.end()) {
        return false;
    }
    else {
        if (getDist(arr[r][c], snake) > step) {
            visited.insert(num);
            return false;
        } else {
            bool toRet = false;
            visited.insert(num);
            for (int i=0; i < 4; i++) {
                if (dfs(r + dir[i][0], c + dir[i][1], step+1)) {
                    toRet = true;
                }
            }
            return toRet;
        } 
    }
    return false;
}

int main() {
    int r; int c;
    cin >> r >> c;
    
    int pos[2];
    string line;
    int len = 0;
    int curr;
    for (int i = 0; i < r; i++) {
        cin >> line;
        vector<char> h;
        for (int j = 0; j < line.size(); j++) {
            h.push_back(line[j]);
            if (line[j] == '0') {
                pos[0] = i;
                pos[1] = j;
            }
            if (line[j] != '.' && line[j] != 'A') {
                curr = line[j] - '0';
                if (curr >= 49) {
                    curr = curr - 39;
                }
                len = max(len, curr);
            }  
        }
        snake = len;
        arr.push_back(h);
    }
    if (dfs(pos[0],pos[1],0)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

}