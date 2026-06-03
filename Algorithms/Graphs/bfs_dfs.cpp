#include <iostream>
#include <queue>
#include <vector>
#include <stack>

std::vector<int> bfs(const std::vector<std::vector<int>>& adjMat, int startNode) {
    int size = adjMat.size();
    std::queue<int> q;
    std::vector<bool> visited (size, false);
    std::vector<int> traverse;
    if(startNode + 1 >= size) return traverse;
    q.push(startNode);
    visited[startNode] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        traverse.push_back(node);
        for(int i = 0; i < size; i++) {
            if(adjMat[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return traverse;
}

std::vector<int> dfs(const std::vector<std::vector<int>>& adjMat, int startNode) {
    int size = adjMat.size();
    std::stack<int> s;
    std::vector<bool> visited (size, false);
    std::vector<int> traverse;
    if(startNode + 1 >= size) return traverse;
    s.push(startNode);
    while(!s.empty()) {
        int node = s.top();
        s.pop();
        if(visited[node]) continue;
        visited[node] = true;
        traverse.push_back(node);
        for(int i = 0; i < size; i++) {
            if(adjMat[node][i] == 1 && !visited[i]) {
                s.push(i);
            }
        }
    }
    return traverse;
}

int main() {
    std::vector<std::vector<int>> adjMat = {
        {0,1,1,0,0,0},
        {1,0,0,1,0,0},
        {1,0,0,1,0,0},
        {0,1,1,0,1,1},
        {0,0,0,1,0,1},
        {0,0,0,1,1,0}
    };
    std::vector<int> dfs_t = dfs(adjMat, 0);
    for(int i : dfs_t) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::vector<int> bfs_t = bfs(adjMat, 0);
    for(int i : bfs_t) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}