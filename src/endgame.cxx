//
// Created by neelk on 11/27/2022.
//
#include "endgame.hxx"


Endgame::Endgame()
    : first(0),
      second(0),
      third(0)
{}

void Endgame::update_score(std::string file, int score)
{
    std::ifstream infile;
    infile.open(file);

    if (infile.is_open()) {
        std::string line;
        while (std::getline(infile, line)) {
            int num = std::stoi(line);
            arr.push_back(num);
        }
    }

    arr.push_back(score);
    sort();

    std::ofstream outfile;
    outfile.open(file);

    first = arr[0];
    second = arr[1];
    third = arr[2];

    for (int i = 0; i < arr.size(); i++) {
        outfile << arr[i] << "\n";
    }
    infile.close();
    outfile.close();
}

void Endgame::sort()
{
    int i;
    int j;
    int temp;

    for (i = 0; i < arr.size(); i++) {
        for (j = i+1; j < arr.size(); j++) {
            if (arr[j] > arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}