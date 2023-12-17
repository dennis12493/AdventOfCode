#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;

bool isAdjacent(vector<string> &engineSchematic, int i, int j) {
    for (int x = i - 1; x <= i + 1; ++x) {
        for (int y = j - 1; y <= j + 1; ++y) {
            if (x >= 0 && x < engineSchematic.size() &&
                y >= 0 && y < engineSchematic[i].size() &&
                engineSchematic[x][y] != '.' && !isdigit(engineSchematic[x][y])) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ifstream ifs(R"(./2023/Day 03/schematic.txt)");
    if (ifs.fail()) {
        cerr << "cannot find file" << endl;
        return 1;
    }

    vector<string> engineSchematic;
    string line;
    while (getline(ifs, line)) {
        engineSchematic.push_back(line);
    }

    ifs.close();

    int sum = 0;
    for (int i = 0; i < engineSchematic.size(); ++i) {
        for (int j = 0; j < engineSchematic[i].size(); ++j) {
            int num = 0;
            bool adjacent = false;
            while (isdigit(engineSchematic[i][j])) {
                num *= 10;
                num += engineSchematic[i][j] - '0';
                if(isAdjacent(engineSchematic, i, j)) adjacent = true;
                j++;
            }
            if(num > 0 && adjacent) {
                sum += num;
            }
        }
    }

    // Output the sum of part numbers
    cout << "Sum of part numbers: " << sum << endl;

    return 0;
}
