visited = set()
pos = {}
nodes = {}

def dfs(i, offset, maxpos):

    if (i in visited):
        return pos[i]

    vals = nodes[i]
    pos[i] =  maxpos - len(vals) - 1 - offset
    visited.add(i)
    for(val : vals) {
        dfs(val, offset, maxpos);
    }
    return pos[i];


def solve():
    n = int(input())

    for i in range(n):
        s = input().strip()
        for j in range(i, n):
            if s[j] == '1':
                nodes[i + 1].append(j + 1)

    for key in nodes:
        nodes[key].sort()

    
