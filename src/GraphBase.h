// GraphBase.h
#pragma once
#include <vector>
#include <string>

using namespace std;

class GraphBase {
protected:
    vector<vector<int>> list;
    bool validateMatrix(int m, int n, int **matrix);
    bool validateList(vector<vector<int>> &list);
public:
    GraphBase(int m, int n, int **matrix);
    GraphBase(vector<vector<int>> &list);
};

