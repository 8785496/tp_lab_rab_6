// GraphDelete.cpp
#include "GraphDelete.h"

GraphDelete::GraphDelete(int m, int n, int **matrix) : GraphFind(m, n, matrix) {}

GraphDelete::GraphDelete(vector<vector<int>> &list) : GraphFind(list) {}

void GraphDelete::Del(int index) {
    list.erase(list.begin() + index);

    for (auto it = list.begin(); it != list.end() ; ++it) {
        for (auto it2 = (*it).begin(); it2 != (*it).end(); ) {
            if (*it2 == index) {
                (*it).erase(it2);
            } else if (*it2 > index) {
                *it2 = *it2 - 1;
                ++it2;
            } else {
                ++it2;
            }
        }
    }
}
