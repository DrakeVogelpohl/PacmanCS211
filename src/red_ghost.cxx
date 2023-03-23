//
// Created by Drake vogelpohl on 11/27/22.
//

#include "red_ghost.hxx"
#include "model.hxx"
#include "astar.hxx"

RedGhost::RedGhost(Position pos)
        : eaten_(false),
          weak_(false),
          radius_(grid_size/2),
          pos_(pos),
          velocity_({0,0})
{}

RedGhost
RedGhost::velocity_next(Walls w, Position dest)
{
    // updating the velocity

    // skip if it is eaten
    if(eaten_){
        RedGhost result(*this);
        return result;
    }

    // only update velocity if on an edge
    if(pos_.x % grid_size == 0 && pos_.y % grid_size == 0) {
        // getting the direction

        // if weak dest is its starting pos
        if(weak_){
            dest = Red_start;
        }

        AStar path = AStar(pos_, dest, w.wallMap);
        int dir = path.get_direction();

        // checking left
        if (dir == 1) {
            // if the player does not hit a wall and not going in that
            // direction update velocity and rand_
            if (!w.ghost_hits_wall({pos_.x - 2, pos_.y}) &&
                velocity_.width == 0) {
                velocity_.width = -1;
                velocity_.height = 0;
            }
        }

        // checking right
        if (dir == 2) {
            // if the player does not hit a wall and not going in that
            // direction update velocity and rand_
            if (!w.ghost_hits_wall({pos_.x + 2, pos_.y}) &&
                velocity_.width == 0) {
                velocity_.width = 1;
                velocity_.height = 0;
            }
        }

        // checking up
        if (dir == 3) {
            // if the player does not hit a wall and not going in that
            // direction update velocity and rand_
            if (!w.ghost_hits_wall({pos_.x, pos_.y - 2}) &&
                velocity_.height == 0) {
                velocity_.width = 0;
                velocity_.height = -1;
            }
        }

        // checking down
        if (dir == 4) {
            // if the player does not hit a wall and not going in that
            // direction update velocity and rand_
            if (!w.ghost_hits_wall({pos_.x, pos_.y + 2}) &&
                velocity_.height == 0) {
                velocity_.width = 0;
                velocity_.height = 1;
            }
        }

        // checking if the ghost would hit a wall or is eaten
        if(w.ghost_hits_wall({pos_.x + velocity_.width,
                              pos_.y + velocity_.height}) || eaten_){
            velocity_.width = 0;
            velocity_.height = 0;
        }
    }

    // updating the pos of the ghost
    RedGhost result(*this);
    result.pos_.x += result.velocity_.width;
    result.pos_.y += result.velocity_.height;
    return result;
}


bool RedGhost::hits(Player player, int& score)
{

    // checks for collision
    if(!(player.get_pos().x >= pos_.x + radius_ * 2
         || player.get_pos().x + player.get_radius() * 2 <= pos_.x
         || player.get_pos().y >= pos_.y + radius_ * 2
         || player.get_pos().y + player.get_radius() * 2 <= pos_.y)){

        // if already eaten do nothing
        if(eaten_){
            return false;
        }

            // if weak_ eat ghost
        else if(weak_){
            eaten_ = true;
            score += 10;
            weak_ = false;
        }

        else{
            return true;
        }
    }

    return false;
}