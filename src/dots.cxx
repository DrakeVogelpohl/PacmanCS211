//
// Created by Drake vogelpohl on 11/25/22.
//

#include "dots.hxx"

#include "model.hxx"

Dots::Dots()
        : dot_space(grid_size/2 - dot_radius)
{
    // setting the layout for the dots
    int row = 0;
    //0 row is all walls
    row++;

    //1 Row
    dots.push_back(Dot({1*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({2*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({3*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({4*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({5*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({6*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({7*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({8*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({10*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({11*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({12*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({13*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({14*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({15*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({16*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({17*grid_size+dot_space,row*grid_size+dot_space}));
    row++;

    //2 Row
    dots.push_back(Dot({1*grid_size + dot_space - dot_radius,
                        row*grid_size + dot_space - dot_radius},
                       true)); // 1,2 is a big dot
    dots.push_back(Dot({4*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({8*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({10*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({14*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({17*grid_size + dot_space - dot_radius,
                        row*grid_size + dot_space - dot_radius},
                       true)); // 1,17  is a big dot
    row++;

    //3 Row: all dots
    for(int i = 1; i < grid_width-1; i++){
        dots.push_back(Dot({i*grid_size+dot_space,row*grid_size+dot_space}));
    }
    row++;

    //4 row
    dots.push_back(Dot({1*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({4*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({6*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({12*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({14*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({17*grid_size+dot_space,row*grid_size+dot_space}));
    row++;

    //5 Row
    dots.push_back(Dot({1*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({2*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({3*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({4*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({6*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({7*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({8*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({10*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({11*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({12*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({14*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({15*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({16*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({17*grid_size+dot_space,row*grid_size+dot_space}));
    row++;

    //6 Row
    dots.push_back(Dot({4*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({8*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({10*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({14*grid_size+dot_space,row*grid_size+dot_space}));
    row++;

    //7 Row
    dots.push_back(Dot({4*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({6*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({7*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({8*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({9*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({10*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({11*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({12*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({14*grid_size+dot_space,row*grid_size+dot_space}));
    row++;

    //8 Row
    dots.push_back(Dot({4*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({6*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({12*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({14*grid_size+dot_space,row*grid_size+dot_space}));
    row++;

    //9 Row
    dots.push_back(Dot({1*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({2*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({3*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({4*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({5*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({6*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({12*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({13*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({14*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({15*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({16*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({17*grid_size+dot_space,row*grid_size+dot_space}));
    row++;

    //10 Row
    dots.push_back(Dot({4*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({6*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({12*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({14*grid_size+dot_space,row*grid_size+dot_space}));
    row++;

    //11 row
    dots.push_back(Dot({4*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({6*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({7*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({8*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({9*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({10*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({11*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({12*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({14*grid_size+dot_space,row*grid_size+dot_space}));
    row++;

    //12 Row
    dots.push_back(Dot({4*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({6*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({12*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({14*grid_size+dot_space,row*grid_size+dot_space}));
    row++;

    //13 Row
    dots.push_back(Dot({1*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({2*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({3*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({4*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({5*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({6*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({7*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({8*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({10*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({11*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({12*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({13*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({14*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({15*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({16*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({17*grid_size+dot_space,row*grid_size+dot_space}));
    row++;

    //14 Row
    dots.push_back(Dot({1*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({4*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({8*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({10*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({14*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({17*grid_size+dot_space,row*grid_size+dot_space}));
    row++;

    //15 Row
    dots.push_back(Dot({1*grid_size + dot_space - dot_radius,
                        row*grid_size + dot_space - dot_radius},
                       true)); // 15,1 is a big dot
    dots.push_back(Dot({2*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({4*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({5*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({6*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({7*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({8*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({10*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({11*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({12*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({13*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({14*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({16*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({17*grid_size + dot_space - dot_radius,
                        row*grid_size + dot_space - dot_radius},
                       true)); // 15,17 is a big dot
    row++;

    //16 Row
    dots.push_back(Dot({2*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({4*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({6*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({12*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({14*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({16*grid_size+dot_space,row*grid_size+dot_space}));
    row++;

    //17 Row
    dots.push_back(Dot({1*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({2*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({3*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({4*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({6*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({7*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({8*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({10*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({11*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({12*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({14*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({15*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({16*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({17*grid_size+dot_space,row*grid_size+dot_space}));
    row++;

    //18 Row
    dots.push_back(Dot({1*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({8*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({10*grid_size+dot_space,row*grid_size+dot_space}));
    dots.push_back(Dot({17*grid_size+dot_space,row*grid_size+dot_space}));
    row++;

    //19 row is all dots
    for(int i = 1; i < grid_width-1; i++){
        dots.push_back(Dot({i*grid_size+dot_space,row*grid_size+dot_space}));
    }
    row++;

    //20 row is all walls


}

bool Dots::hits_dot(Player player, int& score)
{
    for(Dot& d : dots) {
        if (d.hits(player.get_pos())) {
            bool isBig = d.is_big();
            d = dots.back();
            dots.pop_back();

            // adding one to the score
            score += 1;

            return isBig;
        }
    }
    return false;
}

void
Dots::clear_dots()
{
    dots.clear();
    dots.push_back(Dot({8*grid_size+dot_space,15*grid_size+dot_space}));
}