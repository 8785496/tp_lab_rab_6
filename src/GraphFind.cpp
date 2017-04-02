// GraphFind.cpp
#include "GraphFind.h"
#include <queue>
#include <algorithm>

using namespace std;

int GraphFind::find(int index, vector<int> &path) {
    const int M = list.size(); // количество вершин
    bool visited[M]; // массив посещенных вершин
    int parent[M]; // массив "предков" вершин
    for (int j = 0; j < M; ++j)
        visited[j] = false;
    path.clear();

    queue<int> q; // очередь
    q.push(0);
    visited[0] = true;
    parent[0] = -1;

    while(q.size() > 0) {
        int cur = q.front();
        q.pop();
        if(cur == index) {
            for (int v = index; v != -1; v = parent[v])
                path.push_back (v);
            reverse(path.begin(), path.end());
            return index;
        }

        vector<int> vertexes;
        vertexes = list[cur];
        for (auto it = vertexes.begin(); it != vertexes.end(); ++it) {
            int next = *it;
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                parent[next] = cur;
            }
        }
    }

    return -1;
}

GraphFind::GraphFind(int m, int n, int **matrix) : GraphWrite(m, n, matrix) {}

GraphFind::GraphFind(vector<vector<int>> &list) : GraphWrite(list) {}
