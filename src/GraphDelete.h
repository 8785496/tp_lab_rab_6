// GraphDelete.h
#pragma once
#include "GraphFind.h"

class GraphDelete : public GraphFind
{
public:
    GraphDelete(int m, int n, int **matrix);
    GraphDelete(vector<vector<int>> &list);
    void Del(int index);
};
