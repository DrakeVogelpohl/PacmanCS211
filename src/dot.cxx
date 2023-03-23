//
// Created by Drake vogelpohl on 11/25/22.
//

#include "dot.hxx"

Dot::Dot(Position p)
        : pos(p),
          big(false),
          radius(dot_radius)
{}

Dot::Dot(Position p, bool b)
        : pos(p),
          big(b),
          radius(dot_radius*2)
{}

Dot::Dot(Position p, int r)
        : pos(p),
          big(false),
          radius(r)
{}

bool Dot::hits(Player player) const
{
    return !(player.get_pos().x > pos.x + radius * 2
             || player.get_pos().x + player.get_radius() * 2 < pos.x
             || player.get_pos().y > pos.y + radius * 2
             || player.get_pos().y + player.get_radius() * 2 < pos.y);
}