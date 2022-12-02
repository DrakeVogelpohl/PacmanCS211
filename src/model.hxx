#pragma once

#include "../.cs211/lib/ge211/include/ge211.hxx"
#include <cstdlib>
#include "dots.hxx"
#include "walls.hxx"
#include "player.hxx"
#include "red_ghost.hxx"
#include "blue_ghost.hxx"
#include "pink_ghost.hxx"
#include "orange_ghost.hxx"
#include "endgame.hxx"

// the size of each tile
static int const grid_size = 20;

// size of the grid width with either a wall or dot to start
static int const grid_width = 19;

// size of the grid height with either a wall or dot to start
static int const grid_height = 21;


class Model
{
public:
    // ALIAS'
    // Screen dimensions will use `int` coordinates.
    using Dimensions = ge211::Dims<int>;
    // Representing each of the walls as ge211 rects
    using Wall = ge211::Rect<int>;
    // using Position as an alias
    using Position = ge211::Posn<int>;

    // STARTING POS
    // Starting position for the player
    Position const Player_start = {9*grid_size, 15*grid_size};
    // Starting position for the red ghost
    Position const Red_start = {1*grid_size, 1*grid_size};
    // Starting position for the blue ghost
    Position const Blue_start = {17*grid_size, 1*grid_size};
    // Starting position for the pink ghost
    Position const Pink_start = {1*grid_size, 19*grid_size};
    // Starting position for the orange ghost
    Position const Orange_start = {17*grid_size, 19*grid_size};

    // variable that keeps the score and is passed whenever there is a collision
    int score;

    // The state that the game is in. 0 is start, 1 is in the game, 2 is end
    int game_state;

    // the difficulty of the game. i.e. how many ghosts there should be
    int difficulty;

    // access top scores
    int first_place;
    int second_place;
    int third_place;

    // Constructor
    Model();

    // On each frame the Player is updated and the ghosts
    void on_frame(double dt);

    void starting_click(Position pos2);

    // returns the vector of walls
    std::vector<Wall> model_get_walls() const
    { return walls_.get_walls(); }

    // returns the vector of dots
    std::vector<Dot> model_get_dots() const
    { return dots_.get_dots(); }

    // returns the Position of the player
    Position model_get_player_pos() const
    { return player_.get_pos(); }

    // getting the lives of the player
    int model_get_player_lives() const
    { return player_.get_lives(); }

    // RED GHOST GETTERS
    // returns the position of the red ghost
    Position model_get_red_pos() const
    { return red_.get_pos(); }
    // gets the eaten state of red
    bool red_eaten() const
    { return red_.is_eaten(); }
    // gets the weak state of red
    bool red_weak() const
    { return red_.is_weak(); }

    // Blue GHOST GETTERS
    // returns the position of the red ghost
    Position model_get_blue_pos() const
    { return blue_.get_pos(); }
    // gets the eaten state of red
    bool blue_eaten() const
    { return blue_.is_eaten(); }
    // gets the weak state of red
    bool blue_weak() const
    { return blue_.is_weak(); }

    // Pink GHOST GETTERS
    // returns the position of the red ghost
    Position model_get_pink_pos() const
    { return pink_.get_pos(); }
    // gets the eaten state of red
    bool pink_eaten() const
    { return pink_.is_eaten(); }
    // gets the weak state of red
    bool pink_weak() const
    { return pink_.is_weak(); }

    // Orange GHOST GETTERS
    // returns the position of the red ghost
    Position model_get_orange_pos() const
    { return orange_.get_pos(); }
    // gets the eaten state of red
    bool orange_eaten() const
    { return orange_.is_eaten(); }
    // gets the weak state of red
    bool orange_weak() const
    { return orange_.is_weak(); }

    // gets the easy rect
    Wall get_easy() const
    { return easy; }
    // gets the medium rect
    Wall get_med() const
    { return med; }
    // gets the hard rect
    Wall get_hard() const
    { return hard; }

    // gets the cherry_on_screen
    bool get_cherry() const
    { return cherry_on_screen_; }
    // gets the cherry pos
    Position get_cherry_pos() const
    { return cherry_.top_left(); }

    // sets the velocity of the model based on which arrow key is pressed
    void left_key()
    { move_ = 1; }

    void right_key()
    { move_ = 2; }

    void up_key()
    { move_ = 3; }

    void down_key()
    { move_ = 4; }

private:
    // the vector of walls
    Walls walls_;

    // vector of dots
    Dots dots_;

    // the player
    Player player_;

    // the ghosts
    RedGhost red_;
    BlueGhost blue_;
    PinkGhost pink_;
    OrangeGhost orange_;

    // the endgame class for keeping the score locally
    Endgame end_;

    // the cherry and the bool that is true if the cherry is on the screen.
    // The cherry will spawn around 3 times every full game.
    Dot cherry_;
    bool cherry_on_screen_;

    // Holds a value when the player wants to move in a direction. 0 when the
    // player doesn't want to move, 1 when left, 2 when
    // right, 3 when up, and 4 when down.
    int move_;

    // helper function that updates the weak timer if any of the ghosts are weak
    void update_weak_count();

    // helper function that updates the eaten timer if any of the ghosts are
    // dead
    void update_eaten_count();

    // helper function that updates a random number that has the
    // potential to spawn a cherry if there isn't one on screen. The harder
    // the difficulty the more often cherries spawn. Also checks if the
    // player collides with the cherry.
    void update_cherry(Player& specPlayer);

    // the weak timers for each ghost
    int weak_timer_red;
    int weak_timer_blue;
    int weak_timer_pink;
    int weak_timer_orange;

    // the eaten timer for each ghost
    int eaten_timer_red;
    int eaten_timer_blue;
    int eaten_timer_pink;
    int eaten_timer_orange;

    // The starting rects that you click to determine the difficulty
    Wall easy;
    Wall med;
    Wall hard;
};
