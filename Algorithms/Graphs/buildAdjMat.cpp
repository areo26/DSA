#include <iostream>
#include <vector>

std::vector<std::vector<int>> buildAdjMatUnDir(std::vector<std::pair<int, int>>& sets, int size) {
    std::vector<std::vector<int>> adjMat (size, std::vector<int>(size, 0));
    for(const auto& set : sets) {
        int u = set.first;
        int v = set.second;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }
    return adjMat;
}

std::vector<std::vector<int>> buildAdjMatDir(std::vector<std::pair<int, int>>& sets, int size) {
    std::vector<std::vector<int>> adjMat (size, std::vector<int>(size, 0));
    for(const auto& set : sets) {
        int u = set.first;
        int v = set.second;
        adjMat[u][v] = 1;
    }
    return adjMat;
}


int main() {
    std::vector<std::pair<int, int>> sets = {
        {0,1},{1,2},{2,3},{3,0}
    };
    // size = maxVertexVal + 1
    // {u,v} = {v,u}
    std::vector<std::vector<int>> adjMat = buildAdjMatUnDir(sets, 4);
    for(auto& vec : adjMat) {
        for(int i : vec) {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }

    
    std::cout << std::endl;
    
    // size = maxVertexVal + 1
    // {u,v} != {v,u}
    std::vector<std::vector<int>> adjMatDir = buildAdjMatDir(sets, 4);
    for(auto& vec : adjMatDir) {
        for(int i : vec) {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
    return 0;
}