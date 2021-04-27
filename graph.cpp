#include "graph.hpp"
#include <iostream>
#include <vector>

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
    edgeFrom = new std::multimap<int, edge>;
    edgeTo = new std::multimap<int, edge>;
    mc = 0;
    edgeCount = 0;
}
int graph::addNode()
{
    nodes->insert({currentID, node(currentID)});
    ++mc;
    return currentID++;
}
bool graph::connect(int fromID, int toID, double length)
{
    //checks if the connection node missing
    if (nodes->find(fromID) == nodes->end())
    {
        return false;
    }
    if (nodes->find(toID) == nodes->end())
    {
        return false;
    }
    //if the edge exist change the length
    auto ef = edgeFrom->find(fromID);
    auto et = edgeTo->find(toID);
    if (ef != edgeFrom->end() &&
        et != edgeTo->end())
    {
        for (; ef->second.getToID() != toID; ++ef)
            ;
        ef->second.setLength(length);
        for (; et->second.getFromID() != fromID; ++et)
            ;
        et->second.setLength(length);
        ++mc;
        return true;
    }
    //make new edge
    edge tmp{fromID, toID, length};
    edgeFrom->insert({fromID, tmp});
    edgeTo->insert({toID, tmp});
    ++mc;
    ++edgeCount;
    return true;
}
bool graph::removeNode(int ID)
{
    //checks if the node exist
    if (nodes->find(ID) == nodes->end())
    {
        return false;
    }
    auto list = getNodesConnected(ID);
    for (long unsigned int i = 0; i < list.capacity(); i++)
    {
        removeEdge(ID, list.at(i));
        removeEdge(list.at(i), ID);
    }
    nodes->erase(nodes->find(ID));
    ++mc;
    return true;
}
bool graph::removeEdge(int fromID, int toID)
{
    //checks if the node exist
    if (nodes->find(fromID) == nodes->end())
    {
        return false;
    }
    if (nodes->find(toID) == nodes->end())
    {
        return false;
    }
    //if the edge exist remove
    auto ef = edgeFrom->find(fromID);
    auto et = edgeTo->find(toID);
    if (ef != edgeFrom->end() &&
        et != edgeTo->end())
    {
        for (; ef->second.getToID() != toID; ++ef)
            ;

        edgeFrom->erase(ef);
        for (; et->second.getFromID() != fromID; ++et)
            ;
        edgeTo->erase(et);
        ++mc;
        --edgeCount;
        return true;
    }
    return false;
}
node graph::getNode(int ID) const
{
    auto tmp = nodes->find(ID);
    if (tmp == nodes->end())
    {
        throw "no such node";
    }

    return nodes->find(ID)->second;
}
bool graph::nodeExist(int id) const
{
    auto tmp = nodes->find(id);
    if (tmp == nodes->end())
    {
        return false;
    }

    return true;
}

edge graph::getEdge(int fromID, int toID) const
{
    auto ef = edgeFrom->find(fromID);
    auto et = edgeTo->find(toID);
    if (ef != edgeFrom->end() &&
        et != edgeTo->end())
    {
        for (; ef->second.getToID() != toID; ++ef)
            ;
        return ef->second;
    }
    throw "no such edge";
}
bool graph::edgeExist(int fromID, int toID) const
{
    auto ef = edgeFrom->find(fromID);
    auto et = edgeTo->find(toID);
    if (ef != edgeFrom->end() &&
        et != edgeTo->end())
    {
        return true;
    }
    return false;
}

double graph::dfs()
{
    return 1;
}
std::vector<int> graph::getNodesConnected(int id) const
{
    //checks if the node exist
    if (nodes->find(id) == nodes->end())
    {

        throw "node dosent exist";
    }
    std::vector<int> list;
    for (auto i = edgeFrom->find(id); i != edgeFrom->end(); ++i)
    {
        list.push_back(i->second.getToID());
    }
    return list;
}
uint graph::getMC() const
{
    return mc;
}
uint graph::getNodeCount() const
{
    return nodes->size();
}
uint graph::getEdgeCount() const
{
    return edgeCount;
}
void graph::print() const
{
    for (auto i = nodes->begin(); i != nodes->end(); ++i)
    {
        std::cout << " id: " << i->first << " data: " << i->second.getData();
    }
    std::cout << std::endl;
    for (auto i = edgeFrom->begin(); i != edgeFrom->end(); ++i)
    {
        std::cout << " from: " << i->first << " to: " << i->second.getToID() << " len: " << i->second.getLength();
    }
    std::cout << std::endl;
}

graph::~graph()
{
    delete nodes;
    delete edgeFrom;
    delete edgeTo;
}
