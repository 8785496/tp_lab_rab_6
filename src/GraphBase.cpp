// GraphBase.cpp
#include <vector>
#include "GraphBase.h"
#include "GraphException.h"

using namespace std;

GraphBase::GraphBase(int m, int n, int **matrix) {
    if (!validateMatrix(m, n, matrix)) {
        return;
    }

    for (int i = 0; i < m; ++i) {
        vector<int> vertexes;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                vertexes.push_back(j);
            }
        }
        list.push_back(vertexes);
    }
}

GraphBase::GraphBase(vector<vector<int>> &list) {
    if (!validateList(list))
        return;

    GraphBase::list = list;
}

bool GraphBase::validateMatrix(int m, int n, int **matrix) {
    if (m != n)
        throw GraphException();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] < 0)
                throw GraphException();

            if (matrix[i][j] > 1)
                throw GraphException();
        }
    }

    return true;
}

bool GraphBase::validateList(vector<vector<int>> &list) {
    int length = list.size();

    for (auto it = list.begin(); it != list.end(); ++it) {
        for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
            if (*it2 >= length)
                throw GraphException();

            if (*it2 < 0)
                throw GraphException();
        }
    }

    return true;
}
