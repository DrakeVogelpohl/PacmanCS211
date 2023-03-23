//
// Created by Drake vogelpohl on 11/25/22.
//

//#ifndef PAC_MAN_DOTS_HXX
//#define PAC_MAN_DOTS_HXX

#pragma once

#include "dot.hxx"
#include "player.hxx"
#include <ge211.hxx>


class Dots
{
public:
    // constructor called once at the beginning of the game. Sets the vector
    // with all the dots in their correct starting position
    Dots();

    // returns true if a given position collides with a dot AND that dot is big
    bool hits_dot(Player player, int& score);

    // returns true if all the dots have been eaten
    bool won()
    { return dots.empty(); }

    // returns the vector of dots
    std::vector<Dot> get_dots() const
    { return dots; }

    void clear_dots();

private:
    // All the dots in no particular order
    std::vector<Dot> dots;

    // the number of total dots at the start of the game is 183

    // spacing for the dots, so they are in the center of each tile
    int dot_space;
};


//#endif //PAC_MAN_DOTS_HXX
