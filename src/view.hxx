#pragma once

#include "model.hxx"

class View
{
public:
    // View dimensions will use `int` coordinates.
    using Dimensions = ge211::Dims<int>;
    // Representing each of the walls as ge211 rects
    using Wall = ge211::Rect<int>;

    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);

    Dimensions initial_window_dimensions() const;
    std::string initial_window_title() const;

    // Sprites
    ge211::Circle_sprite const dot_sprite;
    ge211::Circle_sprite const big_dot_sprite;
    ge211::Circle_sprite const cherry_sprite;
    ge211::Rectangle_sprite const wall_sprite;
    ge211::Circle_sprite const player_sprite;
    ge211::Circle_sprite const ghost_sprite_weak;
    ge211::Circle_sprite const red_ghost_sprite;
    ge211::Circle_sprite const red_ghost_sprite_eaten;
    ge211::Circle_sprite const blue_ghost_sprite;
    ge211::Circle_sprite const blue_ghost_sprite_eaten;
    ge211::Circle_sprite const pink_ghost_sprite;
    ge211::Circle_sprite const pink_ghost_sprite_eaten;
    ge211::Circle_sprite const orange_ghost_sprite;
    ge211::Circle_sprite const orange_ghost_sprite_eaten;

    // Starting screen sprites
    ge211::Rectangle_sprite const easy_sprite;
    ge211::Rectangle_sprite const med_sprite;
    ge211::Rectangle_sprite const hard_sprite;

    ge211::Rectangle_sprite const end_sprite;

private:
    Model const& model_;

    //Score and lives sprites
    ge211::Font sans30_{"sans.ttf", 30};
    ge211::Font sans15_{"sans.ttf", 15};
    ge211::Text_sprite score_sprite_;
    ge211::Text_sprite lives_sprite_;

    ge211::Text_sprite leaderboard_sprite;
    ge211::Text_sprite first_sprite;
    ge211::Text_sprite second_sprite;
    ge211::Text_sprite third_sprite;
};
