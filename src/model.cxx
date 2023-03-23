#include "model.hxx"
#include <algorithm> // copy_n
#include <cerrno>    // errno
#include <cstring>   // strerror
#include <fstream>
#include <iostream>
#include <iterator>  // istream_iterator
#include <vector>    // vector instead of VLA

Model::Model()
        : score(0),
          game_state(0),
          difficulty(0),
          first_place(0),
          second_place(0),
          third_place(0),
          walls_(),
          dots_(),
          player_(Player_start),
          red_(Red_start),
          blue_(Blue_start),
          pink_(Pink_start),
          orange_(Orange_start),
          end_(),
          cherry_({9*grid_size+grid_size/2 - 5,
                   15*grid_size+grid_size/2 - 5}, 5),
          cherry_on_screen_(false),
          move_(0),
          weak_timer_red(0),
          weak_timer_blue(0),
          weak_timer_pink(0),
          weak_timer_orange(0),
          eaten_timer_red(0),
          eaten_timer_blue(0),
          eaten_timer_pink(0),
          eaten_timer_orange(0),
          easy(50, (grid_size * grid_height) / 2,
               grid_size * 3, grid_size * 3),
          med((grid_size * grid_width) / 2 - 25, (grid_size * grid_height)
                                                 / 2,
              grid_size * 3, grid_size * 3),
          hard((grid_size * grid_width) - grid_size * 3 - 50, (grid_size *
                                                               grid_height) / 2,grid_size * 3, grid_size * 3)
{}

void
Model::on_frame(double dt)
{
    // game is in the starting state
    if(game_state == 0){
    }

    // game is in the playing state
    else if(game_state == 1) {
        if (player_.get_lives() == 0 or dots_.won()) {
            game_state = 2;
            return;
        }

        Player specPlayer = player_.next(dt);

        // updating the cherry
        update_cherry(specPlayer);

        // updating the velocity and the pos of the ghosts
        red_ = red_.velocity_next(walls_, player_.get_board_pos());
        blue_ = blue_.velocity_next(walls_, player_.get_board_pos(),player_.get_vel());
        if(difficulty >= 2) {
            pink_ = pink_.velocity_next(walls_, red_.get_pos(), player_.get_board_pos());
        }
        if(difficulty == 3) {
            orange_ = orange_.velocity_next(walls_, player_.get_board_pos());
        }

        // checks for a collision with dots that hits_dots handles
        // and updates if the ghost is weak
        bool hits_big = dots_.hits_dot(specPlayer, score);
        red_.weak(hits_big || red_.is_weak());
        blue_.weak(hits_big || blue_.is_weak());

        // if there's at least 3 ghosts
        if(difficulty >= 2){
            pink_.weak(hits_big || pink_.is_weak());
        }
        if(difficulty == 3){
            orange_.weak(hits_big || orange_.is_weak());
        }

        // updates the counter on how long the ghosts have been weak via the
        // helper function
        update_weak_count();

        // updates the counter on how long the ghosts have been eaten via the
        // helper function
        update_eaten_count();

        // checking if hits the red ghost and the player should lose a life
        if (red_.hits(specPlayer, score)) {
            // take away a life
            player_.minus_life();
            // resting to orig locs
            player_.reset_pos(Player_start);
            player_.set_velocity({0, 0});
            red_.reset_pos(Red_start);
            blue_.reset_pos(Blue_start);
            if(difficulty >= 2){ // need to reset pink
                pink_.reset_pos(Pink_start);
            }
            if(difficulty == 3){ // need to reset orange
                orange_.reset_pos(Orange_start);
            }
            // setting cherry to false
            cherry_on_screen_ = false;
        }

        // checking if hits the blue ghost and the player should lose a life
        if (blue_.hits(specPlayer, score)) {
            // take away a life
            player_.minus_life();
            // resting to orig locs
            player_.reset_pos(Player_start);
            player_.set_velocity({0, 0});
            red_.reset_pos(Red_start);
            blue_.reset_pos(Blue_start);
            if(difficulty >= 2){ // need to reset pink
                pink_.reset_pos(Pink_start);
            }
            if(difficulty == 3){ // need to reset orange
                orange_.reset_pos(Orange_start);
            }
            // setting cherry to false
            cherry_on_screen_ = false;
        }

        // if at least 3 ghosts check for pink
        if(difficulty >= 2){
            // checking if hits the pink ghost and the player should lose a life
            if (pink_.hits(specPlayer, score)) {
                // take away a life
                player_.minus_life();
                // resting to orig locs
                player_.reset_pos(Player_start);
                player_.set_velocity({0, 0});
                red_.reset_pos(Red_start);
                blue_.reset_pos(Blue_start);
                pink_.reset_pos(Pink_start);
                if(difficulty == 3){ // need to reset pink
                    orange_.reset_pos(Orange_start);
                }
                // setting cherry to false
                cherry_on_screen_ = false;
            }
        }

        // if 4 ghosts check for orange
        if(difficulty == 3){
            // checking if hits the pink ghost and the player should lose a life
            if (orange_.hits(specPlayer, score)) {
                // take away a life
                player_.minus_life();
                // resting to orig locs
                player_.reset_pos(Player_start);
                player_.set_velocity({0, 0});
                red_.reset_pos(Red_start);
                blue_.reset_pos(Blue_start);
                pink_.reset_pos(Pink_start);
                orange_.reset_pos((Orange_start));
                // setting cherry to false
                cherry_on_screen_ = false;
            }
        }


        // sets the player's velocity to 0 if it would hit a wall
        if (walls_.hits_wall(specPlayer)) {
            player_.set_velocity({0, 0});
        } else {
            // Checking if the player is able to turn
            if (player_.get_pos().x % grid_size == 0 &&
                player_.get_pos().y % grid_size == 0) {

                // checking left
                if (move_ == 1) {
                    Player specTurn = player_.temp({-1, 0});
                    // if the player does not hit a wall update velocity
                    if (!walls_.hits_wall(specTurn)) {
                        player_.set_velocity({-1, 0});
                        move_ = 0;
                    }
                }

                    // checking right
                else if (move_ == 2) {
                    Player specTurn = player_.temp({1, 0});
                    // if the player does not hit a wall update velocity
                    if (!walls_.hits_wall(specTurn)) {
                        player_.set_velocity({1, 0});
                        move_ = 0;
                    }
                }

                    // checking up
                else if (move_ == 3) {
                    Player specTurn = player_.temp({0, -1});
                    // if the player does not hit a wall update velocity
                    if (!walls_.hits_wall(specTurn)) {
                        player_.set_velocity({0, -1});
                        move_ = 0;
                    }
                }

                    // checking down
                else if (move_ == 4) {
                    Player specTurn = player_.temp({0, 1});
                    // if the player does not hit a wall update velocity
                    if (!walls_.hits_wall(specTurn)) {
                        player_.set_velocity({0, 1});
                        move_ = 0;
                    }
                }
            }
        }

        player_ = player_.next(dt);
    }

    // game is in the ending state
    else if(game_state == 2){
        end_.update_score("../Resources/leaderboard.txt", score);
        first_place = end_.get_first();
        second_place = end_.get_second();
        third_place = end_.get_third();

        // only needs to run once so increment the game_state
        game_state++;
    }
}

void Model::starting_click(Position pos)
{
    // if the click is within the easy box
    if(pos.x >= easy.top_left().x &&
       pos.x <= easy.top_left().x + easy.dimensions().width &&
       pos.y >= easy.top_left().y  &&
       pos.y <= easy.top_left().y + easy.dimensions().height)
    {
        game_state = 1;
        difficulty = 1;
    }

    // if the click is in the medium box
    else if(pos.x >= med.top_left().x &&
            pos.x <= med.top_left().x + med.dimensions().width &&
            pos.y >= med.top_left().y  &&
            pos.y <= med.top_left().y + med.dimensions().height)
    {
        game_state = 1;
        difficulty = 2;
    }

    // if the click is in the hard box
    else if(pos.x >= hard.top_left().x &&
            pos.x <= hard.top_left().x + hard.dimensions().width &&
            pos.y >= hard.top_left().y  &&
            pos.y <= hard.top_left().y + hard.dimensions().height)
    {
        game_state = 1;
        difficulty = 3;
    }
}

void Model::update_weak_count()
{
    // red
    if(!red_.is_weak()){
        weak_timer_red = 0;
    }else{
        // finished time when ghosts can be eaten
        if(weak_timer_red == 600){
            red_.weak(false);
            weak_timer_red = 0;
        }

        weak_timer_red ++;
    }

    // blue
    if(!blue_.is_weak()){
        weak_timer_blue = 0;
    }else{
        // finished time when ghosts can be eaten
        if(weak_timer_blue == 600){
            blue_.weak(false);
            weak_timer_blue = 0;
        }

        weak_timer_blue ++;
    }

    //pink
    if(difficulty >= 2) {
        if (!pink_.is_weak()) {
            weak_timer_pink = 0;
        } else {
            // finished time when ghosts can be eaten
            if (weak_timer_pink == 600) {
                pink_.weak(false);
                weak_timer_pink = 0;
            }

            weak_timer_pink++;
        }
    }

    //orange
    if(difficulty == 3) {
        if (!orange_.is_weak()) {
            weak_timer_orange = 0;
        } else {
            // finished time when ghosts can be eaten
            if (weak_timer_orange == 600) {
                orange_.weak(false);
                weak_timer_orange = 0;
            }

            weak_timer_orange++;
        }
    }
}

void Model::update_eaten_count()
{
    // red
    if(!red_.is_eaten()){
        eaten_timer_red = 0;
    }else{
        // finished time when ghosts are eaten
        if(eaten_timer_red == 300){
            red_.eaten(false);
            eaten_timer_red = 0;
        }

        eaten_timer_red ++;
    }

    // blue
    if(!blue_.is_eaten()){
        eaten_timer_blue = 0;
    }else{
        // finished time when ghosts are eaten
        if(eaten_timer_blue == 300){
            blue_.eaten(false);
            eaten_timer_blue = 0;
        }

        eaten_timer_blue ++;
    }

    //pink
    if(difficulty >= 2) {
        if (!pink_.is_eaten()) {
            eaten_timer_pink = 0;
        } else {
            // finished time when ghosts are eaten
            if (eaten_timer_pink == 300) {
                pink_.eaten(false);
                eaten_timer_pink = 0;
            }

            eaten_timer_pink++;
        }
    }

    //orange
    if(difficulty == 3) {
        if (!orange_.is_eaten()) {
            eaten_timer_orange = 0;
        } else {
            // finished time when ghosts are eaten
            if (eaten_timer_orange == 300) {
                orange_.eaten(false);
                eaten_timer_orange = 0;
            }

            eaten_timer_orange++;
        }
    }
}

void Model::update_cherry(Player& specPlayer)
{
    // if not on screen have the potential to spawn one
    if(!cherry_on_screen_){
        int frequency;
        if(difficulty == 1){
            frequency = 4000;
        }else if(difficulty == 2){
            frequency = 3500;
        }else{
            frequency = 3000;
        }
        if(rand() % frequency == 0){
            cherry_on_screen_ = true;
        }
    }

        // else (ie cherry on screen) check if player hit the cherry
    else{
        if(cherry_.hits(specPlayer)){
            cherry_on_screen_ = false;
            score += 25;
        }
    }
}

void Model::set_ghosts(Position pos)
{
    red_.reset_pos(pos);
    blue_.reset_pos(pos);
    pink_.reset_pos(pos);
    orange_.reset_pos(pos);
}

void Model::set_orange_ghost(Position pos)
{
    red_.reset_pos(Red_start);
    blue_.reset_pos(Red_start);
    pink_.reset_pos(Red_start);
    orange_.reset_pos(pos);
}

void Model::set_player_pos(Model::Position pos)
{
    player_.reset_pos(pos);
}

void Model::set_player_vel(ge211::Dims<int> vel)
{
    player_.set_velocity(vel);
}

void Model::clear_dots_but_one()
{
    dots_.clear_dots();
}