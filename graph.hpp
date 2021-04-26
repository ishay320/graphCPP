#pragma once
#include <string>
#include <map>

class node
{
private:
    std::string data;
    int id;

public:
    node(int id);
    node(int id, std::string data);
    int getID();
    std::string getData();
    std::string setData(std::string data);
    ~node();
};

class edge
{
private:
    double length;
    int fromID;
    int toID;

public:
    edge(int fromID, int toID, double length);
    int getFromID() const;
    int getToID() const;
    double getLength() const;
    double setLength(double len);
    ~edge();
};

class graph
{
private:
    std::map<int, node> *nodes;
    std::map<int, edge> *edgeFrom;
    std::map<int, edge> *edgeTo;
    int currentID;

public:
    graph();
    int addNode();
    bool connect(int fromID, int toID, double length);
    bool removeNode(int ID);
    bool removeEdge(int fromID, int toID);
    node getNode(int ID) const;
    edge getEdge(int fromID, int toID) const;
    double dfs();
    //bfs
    //diextra
    ~graph();
};

void testing();
