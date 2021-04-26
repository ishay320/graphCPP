#pragma once
#include <string>
#include <map>
#include <vector>

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
    std::multimap<int, edge> *edgeFrom;
    std::multimap<int, edge> *edgeTo;
    int currentID;

public:
    /**
    * @brief Construct a new graph object
    * 
    */
    graph();

    /**
     * @brief add a node to the graph
     * 
     * @return int of the id
     */
    int addNode();

    /**
     * @brief connect two nodes together
     * 
     * @param fromID 
     * @param toID 
     * @param length 
     * @return true if succeeded
     * @return false if not succeeded
     */
    bool connect(int fromID, int toID, double length);

    /**
     * @brief remove node from the graph
     * 
     * @param ID 
     * @return true if succeeded
     * @return false if not succeeded
     */
    bool removeNode(int ID);

    /**
     * @brief remove edge between two nodes
     * 
     * @param fromID 
     * @param toID 
     * @return true if succeeded
     * @return false if not succeeded
     */
    bool removeEdge(int fromID, int toID);

    /**
     * @brief Get the Node object
     * 
     * @param ID 
     * @return node 
     */
    node getNode(int ID) const;

    /**
     * @brief Get the Edge object
     * 
     * @param fromID 
     * @param toID 
     * @return edge 
     */
    edge getEdge(int fromID, int toID) const;
    std::vector<int> getNodesConnected(int id)const;
    double dfs();
    //bfs
    //diextra
    ~graph();
};

void testing();
