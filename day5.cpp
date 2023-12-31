#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> parseSeeds(const string& line) {
    vector<int> seeds;
    istringstream iss(line);
    int seed;
    while (iss >> seed) {
        seeds.push_back(seed);
    }
    return seeds;
}

unordered_map<int, int> convertSeeds(const vector<vector<int>>& conversions, const vector<int>& seeds) {
    unordered_map<int, int> conversionMap;

    for (const auto& seed : seeds) {
        int converted = seed;

        for (const auto& conversion : conversions) {
            int destRange = conversion[0];
            int srcRange = conversion[1];
            int length = conversion[2];

            if (seed >= srcRange && seed < srcRange + length) {
                converted = destRange + (seed - srcRange);
                break;
            }
        }

        conversionMap[seed] = converted;
    }

    return conversionMap;
}

int findLowestLocation(const vector<int>& seeds, const vector<vector<int>>& conversions) {
    unordered_map<int, int> conversionMap = convertSeeds(conversions, seeds);
    return min_element(conversionMap.begin(), conversionMap.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    })->second;
}

int main() {
    ifstream inputFile("input.txt"); 

    if (!inputFile) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    string seedsLine;
    getline(inputFile, seedsLine);
    vector<int> seeds = parseSeeds(seedsLine);

    vector<vector<int>> conversions;
    string line;
    while (getline(inputFile, line) && !line.empty()) {
        istringstream iss(line);
        int destRange, srcRange, length;
        iss >> destRange >> srcRange >> length;
        conversions.push_back({ destRange, srcRange, length });
    }

    int result = findLowestLocation(seeds, conversions);

    cout << "The lowest location number is: " << result << endl;

    inputFile.close();

    return 0;
}
