//
// Created by Drake vogelpohl on 11/25/22.
//

#pragma once

#include "player.hxx"
#include <ge211.hxx>
#include <unordered_map>

// hash struct so can use position as a key
struct ArrayHasher {
    std::size_t operator()(const ge211::Posn<int>& a) const {
        std::size_t h = 0;

        h ^= std::hash<int>{}(a.x)  + 0x9e3779b9 + (h << 6) + (h >> 2);
        h ^= std::hash<int>{}(a.y)  + 0x9e3779b9 + (h << 6) + (h >> 2);

        return h;
    }
};

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

    //A hash map with the keys being pos of the walls and true if the key is
    // in the map
    std::unordered_map<Position, bool, ArrayHasher> wallMap;

private:

    // All the dots in no particular order
    std::vector<Wall> walls;

    // the number of total dots at the start of the game is 201

};
