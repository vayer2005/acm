
#include <iostream>
#include <vector>

bool collide(std::string a, std::string b) {
    for (int i = 0 ; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                return true;
            }
        }
    }
    return false;
}

bool isBicol(const int subset, const std::vector<std::vector<int>>& adjLists) {
    for (int i = 0; i < adjLists.size(); i++) {
        if (!(subset & (1 << i))) {
            continue;
        }
        for (int next: adjLists[i]) {
            if (!(subset & (1 << next))) {
                continue;
            }
            return false;
        }
    }
    return true;
}

int biggestBicol(const std::vector<std::vector<int>>& adjLists) {
    int maxBicol = 0;
    for (int i = 0; i < (1 << adjLists.size()); i++) {
        if (__builtin_popcount(i) > maxBicol && isBicol(i, adjLists)) {
            maxBicol = __builtin_popcount(i);
        }
    }
    return maxBicol;
}

int main() {
    int p, t;
    std::cin >> p >> t;
    std::vector<std::string> teams;

    // Filter
    for (int i = 0; i < t; i++) {
        std::string team;
        std::cin >> team;
        bool found = false;
        for (int i = 0 ; i < team.size(); i ++) {
            // Filter teams not in range
            if (team[i] - 'A' + 1 > p) {
                found = true;
                break;
            }
            // Filter if repeated character (e.g. TTT)
            for (int j = i + 1 ; j < team.size(); j++) {
                if (team[i] == team[j]) {
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            continue;
        }
        teams.push_back(team);
    }

    // Compute adjLists
    std::vector<std::vector<bool>> adjMatrix(teams.size(), std::vector<bool>(teams.size(), false));
    std::vector<std::vector<int>> adjLists(teams.size());
    for (int i = 0; i < teams.size(); i++) {
        for (int j = i + 1; j < teams.size(); j++) {
            if (!adjMatrix[i][j] && collide(teams[i], teams[j])) {
                adjMatrix[i][j] = true;
                adjLists[i].push_back(j);
                adjLists[j].push_back(i);
            }
        }
    }

    // Get biggest bicolorable tree
    int total = biggestBicol(adjLists);
    std::cout << total << std::endl;
}
