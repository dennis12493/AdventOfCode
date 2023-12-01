#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream ifs(R"(./2023/Day 01/calibrationValues.txt)");
    if (ifs.fail()) {
        cerr << "cannot find file" << endl;
        return 1;
    }

    string line;
    int sum = 0;
    while (std::getline(ifs, line))
    {
        bool firstBool = true;
        int first, last;
        for (char & i : line) {
            if(isdigit(i)){
                if (firstBool) {
                    first = i - '0';
                    firstBool = false;
                }
                last = i - '0';
            }
        }
        sum += first*10 + last;
    }
    cout << sum << endl;
    return 0;
}
