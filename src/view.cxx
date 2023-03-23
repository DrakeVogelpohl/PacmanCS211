#include "view.hxx"

// Colors
static ge211::Color const dot_color {255, 255, 255};
static ge211::Color const big_dot_color {150, 150, 255};
static ge211::Color const cherry_color {255, 50, 50};
static ge211::Color const wall_color {0, 0, 255};
static ge211::Color const player_color {255, 255, 0};
static ge211::Color const red_color {255, 0, 0};
static ge211::Color const blue_color {20, 20, 215};
static ge211::Color const pink_color {255, 200, 200};
static ge211::Color const orange_color {255, 160, 0};
static ge211::Color const eaten_color {155, 155, 255};
static ge211::Color const easy_color {0, 255, 0};
static ge211::Color const med_color {255, 255, 0};
static ge211::Color const hard_color {255, 0, 0};


View::View(Model const& model)
        : dot_sprite(dot_radius, dot_color),
          big_dot_sprite(dot_radius*2, big_dot_color),
          cherry_sprite(5, cherry_color),
          wall_sprite({grid_size, grid_size}, wall_color),
          player_sprite(grid_size/2, player_color),
          ghost_sprite_weak(grid_size/2, eaten_color),
          red_ghost_sprite(grid_size/2, red_color),
          red_ghost_sprite_eaten(grid_size/2, red_color.fade_out(0.5)),
          blue_ghost_sprite(grid_size/2, blue_color),
          blue_ghost_sprite_eaten(grid_size/2, blue_color.fade_out(0.5)),
          pink_ghost_sprite(grid_size/2, pink_color),
          pink_ghost_sprite_eaten(grid_size/2, pink_color.fade_out(0.5)),
          orange_ghost_sprite(grid_size/2, orange_color),
          orange_ghost_sprite_eaten(grid_size/2, orange_color.fade_out(0.5)),
          easy_sprite({grid_size * 3, grid_size * 3}, easy_color),
          med_sprite({grid_size * 3, grid_size * 3}, med_color),
          hard_sprite({grid_size * 3, grid_size * 3}, hard_color),
          end_sprite({grid_size * 20, grid_size * 20}, blue_color),
          model_(model)
{}

void
View::draw(ge211::Sprite_set& set)
{
    // Starting screen
    if(model_.game_state == 0){
        set.add_sprite(easy_sprite, model_.get_easy().top_left());
        set.add_sprite(med_sprite, model_.get_med().top_left());
        set.add_sprite(hard_sprite, model_.get_hard().top_left());
    }

        // the game is currently playing
    else if(model_.game_state == 1) {
        // drawing the score
        ge211::Text_sprite::Builder score_builder(sans30_);
        score_builder << "Score: " << model_.score;
        score_sprite_.reconfigure(score_builder);
        set.add_sprite(score_sprite_, {0, grid_size * grid_height});

        // drawing the lives
        ge211::Text_sprite::Builder lives_builder(sans30_);
        lives_builder << "Lives: " << model_.model_get_player_lives();
        lives_sprite_.reconfigure(lives_builder);
        set.add_sprite(lives_sprite_, {grid_size * grid_width - 120,
                                       grid_size * grid_height});

        // drawing the walls
        for (Wall const w: model_.model_get_walls()) {
            set.add_sprite(wall_sprite, w.top_left(), 0);
        }

        // drawing the dots
        for (Dot const d: model_.model_get_dots()) {
            if (d.is_big()) {
                set.add_sprite(big_dot_sprite, d.top_left(), 1);
            } else {
                set.add_sprite(dot_sprite, d.top_left(), 1);
            }
        }

        // drawing the player
        set.add_sprite(player_sprite, model_.model_get_player_pos(), 2);

        // drawing the ghosts

        // red ghost
        if (model_.red_eaten()) {
            set.add_sprite(red_ghost_sprite_eaten,
                           model_.model_get_red_pos(),
                           2);
        } else if (model_.red_weak()) {
            set.add_sprite(ghost_sprite_weak, model_.model_get_red_pos(), 2);
        } else {
            set.add_sprite(red_ghost_sprite, model_.model_get_red_pos(), 2);
        }

        // blue ghost
        if (model_.blue_eaten()) {
            set.add_sprite(blue_ghost_sprite_eaten,
                           model_.model_get_blue_pos(),
                           2);
        } else if (model_.blue_weak()) {
            set.add_sprite(ghost_sprite_weak, model_.model_get_blue_pos(), 2);
        } else {
            set.add_sprite(blue_ghost_sprite, model_.model_get_blue_pos(), 2);
        }

        // pink ghost
        if(model_.difficulty >= 2) {
            if (model_.pink_eaten()) {
                set.add_sprite(pink_ghost_sprite_eaten,
                               model_.model_get_pink_pos(),2);
            } else if (model_.pink_weak()) {
                set.add_sprite(ghost_sprite_weak,
                               model_.model_get_pink_pos(),2);
            } else {
                set.add_sprite(pink_ghost_sprite,
                               model_.model_get_pink_pos(),2);
            }
        }

        // orange ghost
        if(model_.difficulty == 3) {
            if (model_.orange_eaten()) {
                set.add_sprite(orange_ghost_sprite_eaten,
                               model_.model_get_orange_pos(),2);
            } else if (model_.orange_weak()) {
                set.add_sprite(ghost_sprite_weak,
                               model_.model_get_orange_pos(),2);
            } else {
                set.add_sprite(orange_ghost_sprite,
                               model_.model_get_orange_pos(),2);
            }
        }

        // drawing the cherry
        if(model_.get_cherry()){
            set.add_sprite(cherry_sprite, model_.get_cherry_pos(), 1);
        }
    }

        // ending screen
    else if(model_.game_state >= 2){
        //set.add_sprite(end_sprite, model_.get_easy().top_left());

        ge211::Text_sprite::Builder leaderboard_builder(sans30_);
        leaderboard_builder << "Leaderboard:";
        leaderboard_sprite.reconfigure(leaderboard_builder);
        set.add_sprite(leaderboard_sprite, {grid_size * grid_width - 275,
                                            grid_size * grid_height - 300});

        ge211::Text_sprite::Builder score_builder(sans15_);
        score_builder << "Your Score: " << model_.score;
        score_sprite_.reconfigure(score_builder);
        set.add_sprite(score_sprite_, {grid_size * grid_width - 230,
                                       grid_size * grid_height - 250});

        ge211::Text_sprite::Builder first_builder(sans15_);
        first_builder << "First: " << model_.first_place;
        first_sprite.reconfigure(first_builder);
        set.add_sprite(first_sprite, {grid_size * grid_width - 230,
                                      grid_size * grid_height - 200});

        ge211::Text_sprite::Builder second_builder(sans15_);
        second_builder << "Second: " << model_.second_place;
        second_sprite.reconfigure(second_builder);
        set.add_sprite(second_sprite, {grid_size * grid_width - 230,
                                       grid_size * grid_height - 175});

        ge211::Text_sprite::Builder third_builder(sans15_);
        third_builder << "Third: " << model_.third_place;
        third_sprite.reconfigure(third_builder);
        set.add_sprite(third_sprite, {grid_size * grid_width - 230,
                                      grid_size * grid_height - 150});

    }
}

View::Dimensions
View::initial_window_dimensions() const
{
    return {grid_size * grid_width, grid_size * grid_height + grid_size*2};
}

std::string
View::initial_window_title() const
{
    return "Pac-Man";
}