
#pragma once

#include "player.hxx"
#include <ge211.hxx>

// the size of each dot
static int const dot_radius = 2;

class Dot
{
public:
    // Board positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

    // constructor with just a position assumes not big
    Dot(Position p);

    // constructor
    Dot(Position p, bool b);

    // constructor with a given radius
    Dot(Position p, int r);

    // returns true if the dot is big
    bool is_big() const
    { return big; }

    // returns true if a given position intersects with the dot
    bool hits(Player player) const;

    // returns the top left
    Position top_left() const
    { return pos; }

private:
    Position pos;

    // if the dot makes the ghosts able to be eaten
    bool big;

    // the radius defined by the global variable
    int radius;

};
