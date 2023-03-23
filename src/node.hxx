#pragma once

#include "player.hxx"
#include <ge211.hxx>

class Node
{
public:
    // Board positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

    // position
    Position p;

    // path cost
    float gCost;
    // heuristic cost
    float hCost;

    // parent
    //Node* parent;
    Position parent;


    // constructors
    Node();
    Node(Position pos, Position start, Position end);
    Node(Position pos);
    Node(Position pos, float g, float h, Position par);

    // getting the fCost
    float fCost()
    {   return gCost + hCost; }

};

// defining what makes a node less than another by comparing their costs
bool operator < (const Node& lhs, const Node& rhs);

// defining what makes nodes equal
bool operator == (const Node& lhs, const Node& rhs);

// defining what makes nodes not equal
bool operator != (const Node& lhs, const Node& rhs);