// Solved...? The last iteration for some reason doesn't work for power sums, so I gave up and hand calculated it for Game 100. idk.

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> splitString(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string item;

    while (getline(ss, item, delimiter)) {
        result.push_back(item);
    }

    return result;
}

vector<string> processLine(string str, int gameNum) {
    int startChar = to_string(gameNum).length() + 2;
    int endChar = str.length() - 1;

    string newStr = str.substr(startChar, endChar);
    string finalStr;

    for (char ch : newStr) {
        if (ch != ';' && ch != ',') {
            finalStr += ch;
        }
    }

    return splitString(finalStr, ' ');
}

int main() {
    ifstream file;
    string line;
    int gameID = 1;
    int sumOfID = 0;
    int redMax = 0;
    int greenMax = 0;
    int blueMax = 0;
    int powerSum = 0;
    file.open("input.txt");

    while (getline(file, line)) {
        // Initialize max color values outside the loop
        redMax = 0;
        greenMax = 0;
        blueMax = 0;

        vector<string> procLine = processLine(line, gameID);
        bool state = true;

        for (int i = 0; i < procLine.size() - 1; i += 2) {
            if ((procLine[i + 1] == "red" && stoi(procLine[i]) > 12) || (procLine[i + 1] == "green" && stoi(procLine[i]) > 13) || (procLine[i + 1] == "blue" && stoi(procLine[i]) > 14)) {
                state = false;
            }

            if (procLine[i + 1] == "red" && stoi(procLine[i]) > redMax) {
                redMax = stoi(procLine[i]);
            }
            else if (procLine[i + 1] == "green" && stoi(procLine[i]) > greenMax) {
                greenMax = stoi(procLine[i]);
            }
            else if (procLine[i + 1] == "blue" && stoi(procLine[i]) > blueMax) {
                blueMax = stoi(procLine[i]);
            }
        }

        powerSum += redMax * greenMax * blueMax;
        cout << "Max red: " << redMax << endl << "Max green: " << greenMax << endl << "Max blue: " << blueMax << endl;
        cout << "Power Sum for Game " << gameID << ": " << redMax * greenMax * blueMax << endl;

        if (state == true) {
            sumOfID += gameID;
            cout << "Corresponding Line: " << line << endl;
        }

        gameID++;
    }

    cout << "Sum of IDs: " << sumOfID << endl;
    cout << "Sum of Powers: " << powerSum << endl;

    return 0;
}
