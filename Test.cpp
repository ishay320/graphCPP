#include "doctest/doctest.h"
#include "graph.hpp"

TEST_CASE("basic func")
{
    graph x;
    CHECK(x.getMC() == 0);
    CHECK(x.addNode() == 0);
    CHECK(x.addNode() == 1);
    CHECK(x.addNode() == 2);
    CHECK(x.removeNode(0) == true);
    CHECK(x.removeNode(0) == false);
    CHECK_THROWS(x.getNode(0));
    CHECK(x.connect(1, 2, 12) == true);
    CHECK(x.connect(1, 2, 13) == true);
    CHECK(x.connect(0, 2, 12) == false);
    CHECK(x.getEdge(1, 2).getLength() == 13);
    CHECK(x.getMC() == 6);
    CHECK(x.edgeExist(1, 2) == true);
    CHECK(x.removeEdge(1, 2) == true);
    CHECK_THROWS(x.getEdge(1, 2));
    CHECK(x.edgeExist(1, 2) == false);
    CHECK(x.connect(1, 2, 13) == true);
    CHECK(x.getEdge(1, 2).getLength() == 13);
    x.print();
}