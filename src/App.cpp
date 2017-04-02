// App.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include "App.h"

using namespace std;

void App::Init(int *argc, char **argv) {
    for (int i = 0; i < *argc; ++i) {
        if (string(argv[i]) == "--matrix") {
            if (i + 1 < *argc)
                InitFromMatrix(argv[i + 1]);
            else
                ;//TODO Exception
        }

        if (string(argv[i]) == "--list") {
            if (i + 1 < *argc)
                InitFromList(argv[i + 1]);
            else
                ;//TODO Exception
        }

        if (string(argv[i]) == "--stream") {
            InitFromStream();
        }

        if (string(argv[i]) == "--find") {
            if (i + 1 < *argc)
                Find(atoi(argv[i + 1]));
            else
                ;//TODO Exception
        }

        if (string(argv[i]) == "--delete") {
            if (i + 1 < *argc)
                graph->Del(atoi(argv[i + 1]));
            else
                ;//TODO Exception
        }

        if (string(argv[i]) == "--print") {
            cout << graph->ToString();
        }
    }

}

void App::InitFromMatrix(char *fname) {
    int m = 0; // count rows
    ifstream ifs(fname);
    string line;
    while (getline(ifs, line))
        m++;
    int *matrix[m];
    for (int k = 0; k < m; ++k)
        matrix[k] = new int[m];

    int i = 0;
    ifs.clear();
    ifs.seekg(0);
    while (getline(ifs, line)) {
        istringstream iss(line);
        for (int j = 0; j < m; ++j)
            iss >> matrix[i][j];
        i++;
    }

    graph = new GraphDelete(m, m, matrix);
}

void App::InitFromList(char *fname) {
    ifstream ifs(fname);
    string line;

    vector<vector<int>> list;

    while (getline(ifs, line)) {
        vector<int> vertexes;

        istringstream iss(line);

        while (!iss.eof()) {
            int a;
            iss >> a;
            vertexes.push_back(a);
        }

        list.push_back(vertexes);
    }

    graph = new GraphDelete(list);
}

void App::InitFromStream() {
    string line;

    vector<vector<int>> list;

    while (getline(cin, line)) {
        vector<int> vertexes;

        istringstream iss(line);

        while (!iss.eof()) {
            int a;
            iss >> a;
            vertexes.push_back(a);
        }

        list.push_back(vertexes);
    }

    graph = new GraphDelete(list);
}

void App::Find(int index) {
    vector<int> path;
    int result = graph->find(index, path);
    if (result > -1) {
        cout << result << " path: ";
        for(auto it = path.begin(); it != path.end(); ++it)
            cout << *it << " ";
    } else {
        cout << -1;
    }
}

