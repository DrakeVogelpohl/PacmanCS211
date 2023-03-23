#pragma once

#include "player.hxx"
#include "node.hxx"
#include <ge211.hxx>
#include <unordered_map>
#include "walls.hxx"

class AStar
{
public:
    // Board positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

    // constructor that finds the shortest path
    AStar(Position start, Position dest, std::unordered_map<Position, bool,
          ArrayHasher> wM);

    // get direction to travel
    int get_direction() const;

private:
    // All the nodes
    //std::vector<Node> nodes;

    // the shortest path
    std::vector<Node> path;

    // helper function to find the dist between two nodes
    static float getDist(Node n1, Position pos)
    { return abs(n1.p.x - pos.x) + abs(n1.p.y - pos.y); }

    // helper function to find and remove the node with the lowest fCost in
    // openSet
    Node removeLowestFCost(std::vector<Node>& os);

};