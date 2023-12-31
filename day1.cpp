// Solved!

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
    int sum = 0;
    int lineCount = 1;
    ifstream file;
    string line;
    map<string, char> numMap;
    numMap["one"] = '1';
    numMap["two"] = '2';
    numMap["three"] = '3';
    numMap["four"] = '4';
    numMap["five"] = '5';
    numMap["six"] = '6';
    numMap["seven"] = '7';
    numMap["eight"] = '8';
    numMap["nine"] = '9';
    file.open("input.txt");

    while (getline(file, line)) {
        string lineNum;
        for (int i = 0; i < line.length(); i++) {
            if (isdigit(line[i])) {
                lineNum += line[i];
            }
            else if (i < line.length() - 2) {
                for (int len = 3; len <= 5; len++) {
                    if (numMap.find(line.substr(i, len)) != numMap.end()) {
                        lineNum += numMap[line.substr(i, len)];
                        i += len - 2;
                        break;
                    }
                }
            }
        }
        sum += stoi(string(1, lineNum[0])) * 10 + stoi(string(1, lineNum[lineNum.length() - 1]));
        lineCount++;
    }

    cout << sum;

    return 0;
}