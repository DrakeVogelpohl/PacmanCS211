#include "controller.hxx"

Controller::Controller()
        : view_(model_)
{ }

void Controller::on_frame(double dt) {
    model_.on_frame(dt);
}

void
Controller::on_mouse_up(ge211::Mouse_button, ge211::Posn<int> pos)
{
    if(model_.game_state == 0){
        model_.starting_click(pos);
    }
}

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

void Controller::on_key(ge211::Key key) {
    if (key == ge211::Key::up()) {
        model_.up_key();
    }else if (key == ge211::Key::down()) {
        model_.down_key();
    }else if (key == ge211::Key::left()) {
        model_.left_key();
    }else if (key == ge211::Key::right()) {
        model_.right_key();
    }
}

View::Dimensions
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

std::string
Controller::initial_window_title() const
{
    return view_.initial_window_title();
}