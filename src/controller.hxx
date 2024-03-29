#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    Controller();
    void on_frame(double dt) override;
    void on_key(ge211::Key key) override;

protected:
    void on_mouse_up(ge211::Mouse_button, ge211::Posn<int>) override;

    void draw(ge211::Sprite_set& set) override;

    View::Dimensions initial_window_dimensions() const override;
    std::string initial_window_title() const override;

private:
    Model model_;
    View view_;
};
