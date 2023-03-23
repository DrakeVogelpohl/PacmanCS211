//
// Created by neelk on 11/27/2022.
//

// #ifndef PAC_MAN_ENDGAME_HXX
// #define PAC_MAN_ENDGAME_HXX
#pragma once
#include <ge211.hxx>
#include <iostream>
#include <fstream>
#include <vector>
#include "endgame.hxx"
#include <algorithm>

class Endgame
{
public:
    Endgame();

    void update_score(std::string file, int score);

    // gets the top score
    int get_first() const
    { return first; }
    // gets the second score
    int get_second() const
    { return second; }
    // gets the third score
    int get_third() const
    { return third; }


private:
    int first;
    int second;
    int third;
    std::vector<int> arr;
    void sort();
};


// #endif //PAC_MAN_ENDGAME_HXX
