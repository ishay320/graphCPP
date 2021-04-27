#include "graph.hpp"
#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    testing();
    graph x;
    cout << x.addNode() << endl;
    cout << x.addNode() << endl;
    cout << x.addNode() << endl;
    cout << x.addNode() << endl;
    cout << endl;
    cout << x.removeNode(7) << endl;
    cout << x.connect(0, 1, 12) << endl;
    try
    {
        cout << x.getNode(7).getID() << endl;
    }
    catch (const char* e)
    {
        std::cerr << e << '\n';
    }

    cout << x.nodeExist(8) << endl;

    return 0;
}
