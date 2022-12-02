//
// Created by Drake vogelpohl on 11/26/22.
//

#include "player.hxx"
#include "model.hxx"

Player::Player(Position pos)
    : lives_(3),
      radius_(grid_size/2),
      pos_(pos),
      velocity_({0,0})
{}

Player
Player::next(double dt) const
{
    Player result(*this);
    if(dt) {
        result.pos_.x += result.velocity_.width;
        result.pos_.y += result.velocity_.height;
    }
    return result;
}

Player
Player::temp(Velocity velocity) const
{
    Player result(*this);
    result.velocity_ = velocity;
    result.pos_.x += result.velocity_.width;
    result.pos_.y += result.velocity_.height;
    return result;
}