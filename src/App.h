// App.h
#pragma once
#include "GraphDelete.h"

class App
{
    GraphDelete *graph;
    void InitFromMatrix(char *);
    void InitFromList(char *);
    void InitFromStream();
    void Find(int);
public:
    void Init(int *argc, char **argv);
};
