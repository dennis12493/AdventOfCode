#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Game {
    int id;
    int redCount;
    int greenCount;
    int blueCount;
};

// Funktion zum Parsen einer Zeile und Extrahieren der Spielinformationen
Game parseLine(const std::string &line) {

    Game game{
            0,
            0,
            0,
            0
    };

    istringstream iss(line);

    string numberString;
    string color;

    iss >> numberString;
    iss >> game.id;

    while (iss >> numberString) {
        if (isdigit(numberString[0])) {
            iss >> color;
            if(color[color.size() - 1] == ',' || color[color.size() - 1] == ';') color = color.substr(0, color.size() - 1);
            int number = stoi(numberString);
            if (color == "red") {
                if (game.redCount == 0 || game.redCount < number) {
                    game.redCount = number;
                }
            } else if (color == "green") {
                if (game.greenCount == 0 || game.greenCount < number) {
                    game.greenCount = number;
                }
            } else if (color == "blue") {
                if (game.blueCount == 0 || game.blueCount < number) {
                    game.blueCount = number;
                }
            }
        }
    }
    return game;
}

int main() {
    ifstream ifs(R"(./2023/Day 02/games.txt)");
    if (ifs.fail()) {
        cerr << "cannot find file" << endl;
        return 1;
    }

    vector<Game> games;

    const int redCubes = 12;
    const int greenCubes = 13;
    const int blueCubes = 14;

    int sum = 0;
    int powerSum = 0;
    string line;
    while (getline(ifs, line)) {
        auto game = parseLine(line);
        games.push_back(game);
        if (game.redCount <= redCubes && game.greenCount <= greenCubes && game.blueCount <= blueCubes) {
            sum += game.id;
        }
        powerSum += game.redCount * game.greenCount * game.blueCount;
    }

    ifs.close();

    cout << "Sum: " << sum << endl;
    cout << "PowerSum: " << powerSum << endl;

    return 0;
}
