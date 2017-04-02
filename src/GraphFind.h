// GraphFind.h
#pragma once
#include "GraphWrite.h"

class GraphFind : public GraphWrite
{
public:
    GraphFind(int m, int n, int **matrix);
    GraphFind(vector<vector<int>> &list);
    int find(int, vector<int> &);
};
