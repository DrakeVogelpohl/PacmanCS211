#include "node.hxx"


Node::Node()
    : p(Position(FLT_MAX,FLT_MAX)),
      gCost(FLT_MAX),
      hCost(FLT_MAX),
      parent(-1,-1)
{}

Node::Node(Position pos, Position start, Position end)
    : p(pos),
      parent(-1,-1)
{
    gCost = abs(pos.x - start.x) + abs(pos.y - start.y);
    hCost = abs(pos.x - end.x) + abs(pos.y - end.y);
}

Node::Node(Position pos)
    : p(pos),
      gCost(FLT_MAX),
      hCost(FLT_MAX),
      parent(-1,-1)
{}

Node::Node(Position pos, float g, float h, Position par)
    : p(pos),
      gCost(g),
      hCost(h),
      parent(par)
{}

bool operator < (const Node& lhs, const Node& rhs)
{
    return (lhs.gCost + lhs.hCost) < (rhs.gCost + rhs.hCost);
}

bool operator == (const Node& lhs, const Node& rhs)
{
    return lhs.p.x == rhs.p.x && lhs.p.y == rhs.p.y;
}

bool operator != (const Node& lhs, const Node& rhs)
{
    return lhs.p.x != rhs.p.x || lhs.p.y != rhs.p.y;
}


