#include "model.hxx"
#include <catch.hxx>

using namespace ge211;

TEST_CASE("example test (TODO: replace this)")
{
    CHECK(1 + 1 == 2);
}

TEST_CASE("Test a random game")
{
    Model m = Model();
    double const dt = 1;
    CHECK(m.game_state == 0);
    m.starting_click(m.get_hard().top_left()); // clicking the easy box
    CHECK(m.game_state == 1);
    CHECK(m.model_get_player_lives() == 3);
    CHECK(m.difficulty == 3);
    CHECK(m.score == 0);


    // randomly turning every 120 frames and assuming the player will eat the
    // entire map or get eaten given 100 million frames. This also tests random
    // keystrokes that a user might input.
    for(int i = 0; i < 100000000; i++){
        if(i % 120 == 0){
            int rand_turn = rand() % 4;
            if(rand_turn == 0){
                m.right_key();
            }else if(rand_turn == 1){
                m.left_key();
            }else if(rand_turn == 2){
                m.up_key();
            }else{
                m.down_key();
            }
            m.on_frame(dt);
        }else{
            m.on_frame(dt);
        }
    }

    CHECK(m.game_state >= 2);
    CHECK(m.score != 0);
}


TEST_CASE("Die to ghosts 3 times and end game and 2 ghosts")
{
    Model m = Model();
    double const dt = 1;
    CHECK(m.game_state == 0);
    m.starting_click(m.get_easy().top_left()); // clicking the easy box
    CHECK(m.game_state == 1);
    CHECK(m.model_get_player_lives() == 3);
    CHECK(m.difficulty == 1);

    m.set_ghosts({10*grid_size, 15*grid_size}); // one tile right of the player
    m.set_player_vel({20, 0});
    m.on_frame(dt);
    CHECK(m.model_get_player_lives() == 2);
    CHECK(m.model_get_player_pos() == m.Player_start);
    CHECK(m.model_get_red_pos() == m.Red_start);
    CHECK(m.model_get_blue_pos() == m.Blue_start);

    m.set_ghosts({7*grid_size, 15*grid_size}); // 1 tiles left
    m.set_player_vel({-20, 0});
    m.on_frame(dt);
    CHECK(m.model_get_player_lives() == 2);
    m.on_frame(dt);;
    CHECK(m.model_get_player_lives() == 1);


    m.set_ghosts({11*grid_size, 15*grid_size});
    m.on_frame(dt); // doesnt move
    m.on_frame(dt);
    CHECK(m.model_get_player_lives() == 1);
    m.set_player_vel({40, 0});
    m.on_frame(dt);
    CHECK(m.model_get_player_lives() == 0);
    m.on_frame(dt);
    CHECK(m.game_state == 2);
}

TEST_CASE("Check player cannot pass through walls and doesn't lose a life to "
          "orange ghost on med difficulty")
{
    Model m = Model();
    double const dt = 1;
    CHECK(m.game_state == 0);
    m.starting_click(m.get_med().top_left()); // clicking the med box
    CHECK(m.game_state == 1);
    CHECK(m.model_get_player_lives() == 3);
    CHECK(m.difficulty == 2);

    m.set_player_vel({20, 0});
    m.set_orange_ghost({10*grid_size, 15*grid_size}); // one tile right
    m.on_frame(dt);
    CHECK(m.model_get_player_lives() == 3); // didn't lose a life

    m.on_frame(dt); //11, 15
    m.on_frame(dt); //12, 15
    m.on_frame(dt); //13, 15
    m.on_frame(dt); //14, 15
    Posn<int> pos = {14*grid_size, 15*grid_size};
    CHECK(m.model_get_player_pos() == pos);
    m.on_frame(dt); //14, 15 --> doesn't move
    CHECK(m.model_get_player_pos() == pos);
    m.right_key(); // pushing the right key
    m.on_frame(dt); //14, 15 --> doesn't move
    CHECK(m.model_get_player_pos() == pos);

    // set player on a corner
    m.set_player_pos({10*grid_size, 13*grid_size});
    m.left_key();
    m.on_frame(dt);
    // check didn't move
    pos = {10*grid_size, 13*grid_size};
    CHECK(m.model_get_player_pos() == pos);
    m.up_key();
    m.on_frame(dt);
    // check didn't move
    CHECK(m.model_get_player_pos() == pos);

    m.right_key();
    m.on_frame(dt);
    // check did move
    pos = {10*grid_size+1, 13*grid_size};
    CHECK(m.model_get_player_pos() == pos);
}

TEST_CASE("Power pellet and eating ghosts functionality")
{
    Model m = Model();
    double const dt = 1;
    CHECK(m.game_state == 0);
    m.starting_click(m.get_easy().top_left()); // clicking the easy box
    CHECK(m.game_state == 1);
    CHECK(m.model_get_player_lives() == 3);
    CHECK(m.difficulty == 1);

    CHECK(m.score == 0);
    m.set_player_pos({17*grid_size, 15*grid_size}); //get power pellet
    m.on_frame(dt);

    m.set_player_vel({20, 0});
    m.set_player_pos({7*grid_size, 15*grid_size});
    CHECK(m.red_weak() == true);
    CHECK(m.blue_weak() == true);
    m.set_ghosts({8*grid_size, 15*grid_size});
    m.on_frame(dt);
    CHECK(m.score == 22); //10 per ghost eaten + 2 for dots along the path
    CHECK(m.red_eaten());
    CHECK(m.blue_eaten());

    // getting ghosts to the edge of their tile
    for(int i = 0; i < 10; i++){
        m.on_frame(dt);
    }

    Posn<int> red_pos = m.model_get_red_pos();
    Posn<int> blue_pos = m.model_get_blue_pos();
    m.on_frame(dt);
    m.on_frame(dt);
    m.on_frame(dt);
    CHECK(m.model_get_red_pos() == red_pos);
    CHECK(m.model_get_blue_pos() == blue_pos); //check they are immobile
}

TEST_CASE("Test cherry functionality and End game when dots are gone")
{
    Model m = Model();
    double const dt = 1;
    CHECK(m.game_state == 0);
    m.starting_click(m.get_easy().top_left()); // clicking the easy box
    CHECK(m.game_state == 1);
    CHECK(m.model_get_player_lives() == 3);
    CHECK(m.difficulty == 1);

    m.set_player_pos({6*grid_size, 15*grid_size});
    m.spawn_cherry();
    m.on_frame(dt);
    CHECK(m.score == 1);
    m.set_player_vel({20, 0});
    m.on_frame(dt); //7, 15
    m.on_frame(dt); //8, 15
    m.on_frame(dt); //9, 15
    CHECK(m.score == 28); //25 for cherries + 3 dots from movement to the right

    m.set_player_pos({9*grid_size, 15*grid_size});

    m.clear_dots_but_one(); //clears all dots except one to the left
    m.set_player_vel({-20, 0});
    m.on_frame(dt);
    CHECK(m.score == 29);
    m.on_frame(dt);
    CHECK(m.game_state == 2);

    // the leader board is dynamic so does not always return true depending
    // on how many games have been played. So check by looking at the
    // leaderbaord.txt
    /*m.on_frame(dt);
     * CHECK(m.first_place == 332);
     * CHECK(m.second_place == 100);
     * CHECK(m.third_place == 89);*/
}
