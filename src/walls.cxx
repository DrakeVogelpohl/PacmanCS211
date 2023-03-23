//
// Created by Drake vogelpohl on 11/25/22.
//

#include "walls.hxx"

// included for the dims of the model
#include "model.hxx"

Walls::Walls()
{
    // setting the layout for the walls
    int row = 0;
    //0 row is all walls
    for(int i = 0; i < grid_width; i++){
        walls.push_back(Wall(i*grid_size, row*grid_size, grid_size, grid_size));
    }
    row++;

    //1 row
    walls.push_back(Wall(0*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(9*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(18*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //2 row
    walls.push_back(Wall(0*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(2*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(3*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(5*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(6*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(7*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(9*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(11*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(12*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(13*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(15*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(16*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(18*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //3 row
    walls.push_back(Wall(0*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(18*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //4 row
    walls.push_back(Wall(0*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(2*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(3*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(5*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(7*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(8*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(9*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(10*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(11*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(13*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(15*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(16*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(18*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //5 row
    walls.push_back(Wall(0*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(5*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(9*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(13*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(18*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //6 row
    walls.push_back(Wall(0*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(1*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(2*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(3*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(5*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(6*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(7*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(9*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(11*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(12*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(13*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(15*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(16*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(17*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(18*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //7 row
    walls.push_back(Wall(3*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(5*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(13*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(15*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //8 row
    walls.push_back(Wall(0*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(1*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(2*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(3*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(5*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(7*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(8*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(9*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(10*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(11*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(13*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(15*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(16*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(17*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(18*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //9 row
    walls.push_back(Wall(0*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(7*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(11*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(18*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //10 row
    walls.push_back(Wall(0*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(1*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(2*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(3*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(5*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(7*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(8*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(9*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(10*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(11*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(13*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(15*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(16*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(17*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(18*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //11 row
    walls.push_back(Wall(3*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(5*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(13*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(15*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //12 row
    walls.push_back(Wall(0*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(1*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(2*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(3*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(5*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(7*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(8*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(9*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(10*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(11*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(13*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(15*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(16*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(17*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(18*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //13 row
    walls.push_back(Wall(0*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(9*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(18*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //14 row
    walls.push_back(Wall(0*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(2*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(3*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(5*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(6*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(7*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(9*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(11*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(12*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(13*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(15*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(16*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(18*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //15 row
    walls.push_back(Wall(0*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(3*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(15*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(18*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //16 row
    walls.push_back(Wall(0*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(1*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(3*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(5*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(7*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(8*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(9*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(10*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(11*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(13*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(15*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(17*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(18*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //17 row
    walls.push_back(Wall(0*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(5*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(9*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(13*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(18*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //18 row
    walls.push_back(Wall(0*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(2*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(3*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(4*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(5*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(6*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(7*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(9*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(11*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(12*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(13*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(14*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(15*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(16*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(18*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //19 row
    walls.push_back(Wall(0*grid_size, row*grid_size, grid_size, grid_size));
    walls.push_back(Wall(18*grid_size, row*grid_size, grid_size, grid_size));
    row++;

    //20 row is all walls
    for(int i = 0; i < grid_width; i++){
        walls.push_back(Wall(i*grid_size, row*grid_size, grid_size, grid_size));
    }
    row++;

    // adding the wall positions to the map
    for(Wall w : walls){
        wallMap[w.top_left()] = true;
    }

}

bool Walls::hits_wall(Player player)
{
    for(Wall& w : walls) {
        if(!(player.get_pos().x >= w.top_left().x + w.width
             || player.get_pos().x + player.get_radius()*2 <= w.top_left().x
             || player.get_pos().y >= w.top_left().y + w.height
             || player.get_pos().y + player.get_radius()*2 <= w.top_left().y)){
            return true;
        }
    }
    return false;
}

bool Walls::ghost_hits_wall(Position pos)
{
    for(Wall& w : walls) {
        if(!(pos.x >= w.top_left().x + w.width
             || pos.x + grid_size <= w.top_left().x
             || pos.y >= w.top_left().y + w.height
             || pos.y + grid_size <= w.top_left().y)){
            return true;
        }
    }
    return false;
}