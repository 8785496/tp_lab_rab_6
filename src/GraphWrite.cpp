// GraphWrite.cpp
#include <sstream>
#include "GraphWrite.h"

GraphWrite::GraphWrite(int m, int n, int **matrix) : GraphBase(m, n, matrix) {}

GraphWrite::GraphWrite(vector<vector<int>> &list) : GraphBase(list) {}

string GraphWrite::ToString() {
    const int m = list.size();
    int *matrix[m];
    for (int i = 0; i < m; ++i)
        matrix[i] = new int[m];

    for (int i = 0; i < m; ++i) {
        for (int k = 0; k < m ; ++k) {
            matrix[i][k] = 0;
        }
        vector<int> &vertexes = list[i];
        for (int j = 0; j < vertexes.size(); ++j) {
            int vertex = vertexes[j];
            matrix[i][vertex] = 1;
        }
    }

    stringstream ss;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            ss << matrix[i][j] << ' ';
        }
        ss << endl;
    }

    for (int i = 0; i < m; ++i)
        delete[] matrix[i];

    return ss.str();
}
