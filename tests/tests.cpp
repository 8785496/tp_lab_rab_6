// tests.cpp
#include <gtest/gtest.h>
#include <GraphBase.h>
#include <App.h>
#include <fstream>

TEST(Graph, CreateFromMatrix)
{
    string result = "0 1 \n1 0 \n";
    int **matrix = new int*[2] {new int[2] {0, 1}, new int[2] {1, 0}};
    GraphWrite graph(2, 2, matrix);

    ASSERT_EQ(result, graph.ToString());
}

TEST(Graph, CreateFromList)
{
    string result = "0 1 1 \n1 0 1 \n1 1 0 \n";
    vector<vector<int>> list;
    vector<int> vertexes;

    vertexes.push_back(1);
    vertexes.push_back(2);
    list.push_back(vertexes);

    vertexes.clear();
    vertexes.push_back(0);
    vertexes.push_back(2);
    list.push_back(vertexes);

    vertexes.clear();
    vertexes.push_back(0);
    vertexes.push_back(1);
    list.push_back(vertexes);

    GraphWrite graph(list);

    ASSERT_EQ(result, graph.ToString());
}

TEST(App, InitFromMatrix)
{
    char *fname = (char*)"matrix.txt";
    string outText;
    ofstream ofs(fname);
    ofs << "0 1" << endl;
    ofs << "1 0" << endl;
    ofs.close();

    testing::internal::CaptureStdout();

    App app;
    int argc = 4;
    char *argv[argc] = {(char*)"", (char*)"--matrix", fname, (char*)"--print"};
    app.Init(&argc, argv);

    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("0 1 \n1 0 \n", output);
}

TEST(App, InitFromList)
{
    char *fname = (char*)"list.txt";
    string outText;
    ofstream ofs(fname);
    ofs << "1 2" << endl;
    ofs << "0 2" << endl;
    ofs << "0 1" << endl;
    ofs.close();

    testing::internal::CaptureStdout();

    App app;
    int argc = 4;
    char *argv[argc] = {(char*)"", (char*)"--list", fname, (char*)"--print"};
    app.Init(&argc, argv);

    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("0 1 1 \n1 0 1 \n1 1 0 \n", output);
}

TEST(Graph, Find)
{
    const int M = 4;
    int **matrix = new int*[M] {
            new int[M] {0, 0, 1, 0},
            new int[M] {0, 0, 0, 0},
            new int[M] {0, 0, 0, 1},
            new int[M] {0, 1, 0, 0}
    };
    GraphFind graph(M, M, matrix);

    const int INDEX = 1;

    vector<int> pathT;
    pathT.push_back(0);
    pathT.push_back(2);
    pathT.push_back(3);
    pathT.push_back(1);

    vector<int> path;
    int result = graph.find(INDEX, path);
    ASSERT_EQ(result, INDEX);
    ASSERT_EQ(path, pathT);
}

TEST(Graph, Delete)
{
    const int M = 4;
    int **matrix = new int*[M] {
            new int[M] {0, 1, 1, 1},
            new int[M] {1, 0, 1, 1},
            new int[M] {0, 1, 0, 1},
            new int[M] {1, 1, 0, 0}
    };
    GraphDelete graph(M, M, matrix);

    const int INDEX = 1;

    string before = "0 1 1 1 \n1 0 1 1 \n0 1 0 1 \n1 1 0 0 \n";
    string after = "0 1 1 \n0 0 1 \n1 0 0 \n";

    string resultBefore = graph.ToString();

    ASSERT_EQ(resultBefore, before);

    graph.Del(INDEX);
    string resultAfter = graph.ToString();

    ASSERT_EQ(resultAfter, after);
}

TEST(App, Find)
{
    char *fname = (char*)"matrix.txt";
    string outText;
    ofstream ofs(fname);
    ofs << "0 0 1 0" << endl;
    ofs << "0 0 0 0" << endl;
    ofs << "0 0 0 1" << endl;
    ofs << "0 1 0 0" << endl;
    ofs.close();

    testing::internal::CaptureStdout();

    App app;
    int argc = 5;
    char *argv[argc] = {(char*)"", (char*)"--matrix", fname, (char*)"--find", (char*)"1"};
    app.Init(&argc, argv);

    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("1 path: 0 2 3 1 ", output);
}

TEST(App, Delete)
{
    char *fname = (char*)"matrix.txt";
    string outText;
    ofstream ofs(fname);
    ofs << "0 1 1 1" << endl;
    ofs << "1 0 1 1" << endl;
    ofs << "0 1 0 1" << endl;
    ofs << "1 1 0 0" << endl;
    ofs.close();

    testing::internal::CaptureStdout();

    App app;
    int argc = 6;
    char *argv[argc] = {(char*)"", (char*)"--matrix", fname, (char*)"--delete", (char*)"1", (char*)"--print"};
    app.Init(&argc, argv);

    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("0 1 1 \n0 0 1 \n1 0 0 \n", output);
}
