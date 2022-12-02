//
// Created by Drake vogelpohl on 11/25/22.
//

//#ifndef PAC_MAN_WALLS_HXX
//#define PAC_MAN_WALLS_HXX
#pragma once

#include "player.hxx"
#include "../.cs211/lib/ge211/include/ge211.hxx"

class Walls
{
public:
    // Representing each of the walls as ge211 rects
    using Wall = ge211::Rect<int>;
    // using Position as an alias
    using Position = ge211::Posn<int>;

    // constructor called once at the beginning of the game. Sets the vector
    // with all the dots in their correct starting position
    Walls();

    // returns true if a given position collides with a wall
    bool hits_wall(Player player);

    // returns true if a ghost position collides with a wall
    bool ghost_hits_wall(Position pos);

    // returns the vector of walls
    std::vector<Wall> get_walls() const
    { return walls; }


private:

    // All the dots in no particular order
    std::vector<Wall> walls;

    // the number of total dots at the start of the game is 201

};


//#endif //PAC_MAN_WALLS_HXX
