#include "graph.hpp"
#include <iostream>

void testing()
{
    std::cout << "test\n";
}

node::node(int id)
{
    this->id = id;
}
node::node(int id, std::string data)
{
    this->id = id;
    this->data = data;
}
int node::getID()
{
    return id;
}
std::string node::getData()
{
    return data;
}
std::string node::setData(std::string data)
{
    std::string tmp = this->data;
    this->data = data;
    return tmp;
}

edge::edge(int fromID, int toID, double length)
{
    this->fromID = fromID;
    this->toID = toID;
    this->length = length;
}
int edge::getFromID() const
{
    return fromID;
}
int edge::getToID() const
{
    return toID;
}
double edge::getLength() const
{
    return length;
}
double edge::setLength(double len)
{
    double tmp = length;
    length = len;
    return tmp;
}

graph::graph()
{
    currentID = 0;
    nodes = new std::map<int, node>;
    edgeFrom = new std::map<int, edge>;
    edgeTo = new std::map<int, edge>;
}
int graph::addNode()
{
    nodes->insert({currentID, node(currentID)});
    return currentID++;
}
bool graph::connect(int fromID, int toID, double length)
{
    if (nodes->find(fromID) == nodes->end())
    {
        return false;
    }
    if (nodes->find(toID) == nodes->end())
    {
        return false;
    }
    edge tmp { fromID, toID, length };
    edgeFrom->insert({fromID,tmp});
    edgeTo->insert({toID,tmp});
}
bool graph::removeNode(int ID)
{
}
bool graph::removeEdge(int fromID, int toID)
{
}
node graph::getNode(int ID) const
{
}
edge graph::getEdge(int fromID, int toID) const
{
}
double graph::dfs()
{
}
graph::~graph()
{
    delete nodes;
    delete edgeFrom;
    delete edgeTo;
}
