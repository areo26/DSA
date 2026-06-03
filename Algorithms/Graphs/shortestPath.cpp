#include <iostream>
#include <vector>
#include <queue>

std::vector<int> shortestPath(std::vector<std::vector<int>>& adjMat, int startNode, int endNode) {
    int size = adjMat.size();
    std::vector<int> path;
    if(startNode+1 >= size || endNode + 1 >= size) return path;
    std::queue<int> q;
    std::vector<bool> visited (size, false);
    std::vector<int> tracker(size, -1);
    bool isFound = false;
    q.push(startNode);
    visited[startNode] = true;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(node == endNode) {
            isFound = true;
            break;
        }
        for(int i = 0; i < size; i++) {
            if(adjMat[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                tracker[i] = node;
                q.push(i);
            }
        }
    }

    if(!isFound) return path;
    int n = endNode;
    while(n != -1) {
        path.push_back(n);
        n = tracker[n];
    }
    std::reverse(path.begin(), path.end());
    return path;
}


int main() {
    std::vector<std::vector<int>> adjMat = {
        {0,1,0,0,0,1,0},
        {1,0,1,0,0,0,0},
        {0,1,0,1,0,1,1},
        {0,0,1,0,1,0,0},
        {0,0,0,1,0,0,1},
        {1,0,1,0,0,0,1},
        {0,0,1,0,1,1,0}
    };
    std::vector<int> path = shortestPath(adjMat, 0, 4);
    for(int i : path) {
        std::cout << i << " ";
    }
    return 0;
}