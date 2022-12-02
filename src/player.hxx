//
// Created by Drake vogelpohl on 11/26/22.
//
//#ifndef PAC_MAN_PLAYER_HXX
//#define PAC_MAN_PLAYER_HXX
#pragma once
#include "../.cs211/lib/ge211/include/ge211.hxx"

class Player
{
public:
    // representing the position of the player using ge211::Posn<int>
    using Position = ge211::Posn<int>;

    // representing the velocity of the player using ge211::Dims<int>
    using Velocity = ge211::Dims<int>;

    // constructor with pos as the starting position of the player
    Player(Position pos);

    // updating the pos given the velocity
    Player next(double dt) const;

    // creating a temp player with a new velocity and updating the position
    // based on that new velocity
    Player temp(Velocity velocity) const;

    // returns the pos of the player
    Position get_pos() const
    { return pos_; }

    // getting the lives
    int get_lives() const
    { return lives_; }

    // getting the radius
    int get_radius() const
    { return radius_; }

    // setting the velocity
    void set_velocity(Velocity vel)
    { velocity_ = vel; }

    // taking away a live
    void minus_life()
    { lives_ -= 1; }

    // resetting the pos
    void reset_pos(Position pos)
    { pos_ = pos; }

private:
    // The lives the player has left
    int lives_;

    // The radius of the player
    int radius_;

    // The position of the top left of the player.
    Position pos_;

    // The velocity of the player in pixels per tick.
    Velocity velocity_;

};


//#endif //PAC_MAN_PLAYER_HXX
