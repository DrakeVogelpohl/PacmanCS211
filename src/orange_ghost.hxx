//
// Created by Drake vogelpohl on 11/28/22.
//

//#ifndef PAC_MAN_ORANGE_GHOST_HXX
//#define PAC_MAN_ORANGE_GHOST_HXX
#pragma once
#include "player.hxx"
#include "dots.hxx"
#include "walls.hxx"
#include <ge211.hxx>
#include <cstdlib>

class OrangeGhost
{
public:
    // representing the position of the red ghost using ge211::Posn<int>
    using Position = ge211::Posn<int>;

    // representing the velocity of the red ghost using ge211::Dims<int>
    using Velocity = ge211::Dims<int>;

    // constructor with pos as the starting position of the red_ghost
    OrangeGhost(Position pos);

    // updates the velocity of the ghost given the player and the walls using
    // a tracking algorithm. Then updates the pos accordingly
    // The orange ghost will prioritize moving towards the down, then right,
    // then left, then up
    OrangeGhost velocity_next(Walls w, Position dest);


    // checks if the player hits the ghost and updates the ghost accordingly
    // and only return true if the player loses a life
    bool hits(Player player, int& score);

    //  get eaten_
    bool is_eaten() const
    { return eaten_; }

    // gets weak_
    bool is_weak() const
    { return weak_; }

    // sets weak_
    void weak(bool w)
    { weak_ = w; }

    // sets eaten_
    void eaten(bool e)
    { eaten_ = e; }

    // getting the radius
    int get_radius() const
    { return radius_; }

    // getting the pos of the player
    Position get_pos() const
    { return pos_; }

    // resetting the pos
    void reset_pos(Position pos)
    { pos_ = pos; }

private:
    // If the ghost is eaten
    bool eaten_;

    // If the ghost is able to be eaten
    bool weak_;

    // The radius of the player
    int radius_;

    // The position of the top left of the player.
    Position pos_;

    // The velocity of the player in pixels per tick.
    Velocity velocity_;

};


//#endif //PAC_MAN_ORANGE_GHOST_HXX
