// main.cpp
#include <iostream>
#include <App.h>
#include <GraphException.h>
#include <ArgumentException.h>

int main(int argc, char *argv[]) {
    App app;

    try {
        app.Init(&argc, argv);
    } catch (GraphException &graphException) {
        cout << graphException.what() << endl;
    } catch (ArgumentException &argumentException) {
        cout << argumentException.what() << endl;
    }

    return 0;
}
