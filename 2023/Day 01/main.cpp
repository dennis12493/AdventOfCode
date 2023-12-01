#include <iostream>
#include <fstream>
#include <map>

using namespace std;

const map<string,int> digitMap = {{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9} };

int digitsAndWords(string& line){
    int first, last = 0;
    int firstPos = line.size();
    int lastPos = -1;
    for (const auto& digit : digitMap) {
        size_t pos = line.find(digit.first);
        while (pos != string::npos) {
            string replacement = digit.first + to_string(digit.second) + digit.first;
            line.replace(pos, digit.first.length(), replacement);
            pos = line.find(digit.first, pos + replacement.length());
        }
    }

    for (int i = 0; i < line.size(); i++) {
        const char &c = line[i];
        if(isdigit(c)){
            if(i < firstPos){
                firstPos = i;
                first = c - '0';
            }
            if(i > lastPos){
                lastPos = i;
                last = c - '0';
            }
        }
    }
    cout << first << " : " << last << endl;
    cout << line << endl;
    return first*10 + last;
}


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
        sum += digitsAndWords(line);
    }
    cout << sum << endl;
    return 0;
}
