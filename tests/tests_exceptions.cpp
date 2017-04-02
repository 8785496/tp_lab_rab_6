// tests.cpp
#include <gtest/gtest.h>
#include <GraphBase.h>
#include <App.h>
#include <fstream>
#include <GraphException.h>
#include <ArgumentException.h>

TEST(Exception, ValidMatrix)
{
    string result = "0 1 \n1 0 \n";
    int **matrix = new int*[2] {new int[2] {0, 1}, new int[2] {1, 0}};

    ASSERT_THROW(GraphWrite graph(2, 3, matrix), GraphException);
}

TEST(Exception, InitFromMatrix)
{
    char *fname = (char*)"matrix.txt";
    string outText;
    ofstream ofs(fname);
    ofs << "0 2" << endl;
    ofs << "1 0" << endl;
    ofs.close();

    App app;
    int argc = 4;
    char *argv[argc] = {(char*)"", (char*)"--matrix", fname, (char*)"--print"};

    ASSERT_THROW(app.Init(&argc, argv), GraphException);
}

TEST(Exception, ValidList)
{
    string result = "0 1 1 \n1 0 1 \n1 1 0 \n";
    vector<vector<int>> list;
    vector<int> vertexes;

    vertexes.push_back(1);
    vertexes.push_back(2);
    list.push_back(vertexes);

    vertexes.clear();
    vertexes.push_back(0);
    vertexes.push_back(3); // Exc
    list.push_back(vertexes);

    vertexes.clear();
    vertexes.push_back(0);
    vertexes.push_back(1);
    list.push_back(vertexes);

    ASSERT_THROW(GraphWrite graph(list), GraphException);
}

TEST(Exception, InitFromList)
{
    char *fname = (char*)"list.txt";
    string outText;
    ofstream ofs(fname);
    ofs << "1 2" << endl;
    ofs << "0 3" << endl;
    ofs << "0 1" << endl;
    ofs.close();

    App app;
    int argc = 4;
    char *argv[argc] = {(char*)"", (char*)"--list", fname, (char*)"--print"};

    ASSERT_THROW(app.Init(&argc, argv), GraphException);
}

TEST(Exception, ArgumentMatrix)
{
    App app;
    int argc = 2;
    char *argv[argc] = {(char*)"", (char*)"--matrix"};
    ASSERT_THROW(app.Init(&argc, argv), ArgumentException);
}

TEST(Exception, ArgumentList)
{
    App app;
    int argc = 2;
    char *argv[argc] = {(char*)"", (char*)"--list"};
    ASSERT_THROW(app.Init(&argc, argv), ArgumentException);
}

TEST(Exception, ArgumentFind)
{
    App app;
    int argc = 2;
    char *argv[argc] = {(char*)"", (char*)"--find"};
    ASSERT_THROW(app.Init(&argc, argv), ArgumentException);
}

TEST(Exception, ArgumentDelete)
{
    App app;
    int argc = 2;
    char *argv[argc] = {(char*)"", (char*)"--delete"};
    ASSERT_THROW(app.Init(&argc, argv), ArgumentException);
}