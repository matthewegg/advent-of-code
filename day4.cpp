#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/* Part 1
int main() {
    ifstream file;
    string line;
    int point_total = 0;
    file.open("input.txt");
    while (getline(file, line)) {
        vector<int> winning_nums;
        vector<int> player_nums;
        stringstream ss;
        ss.str(line.substr(line.find(':') + 1, line.find('|') - line.find(':') - 1));
        int num;
        while (ss >> num) {
            winning_nums.push_back(num);
        }
        ss.clear();
        ss.str(line.substr(line.find('|') + 1));
        while (ss >> num) {
            player_nums.push_back(num);
        }

        int points = 0;
        for (int player_num : player_nums) {
            if (find(winning_nums.begin(), winning_nums.end(), player_num) != winning_nums.end()) {
                if (points == 0) {
                    points++;
                }
                else {
                    points *= 2;
                }
            }
        }
        point_total += points;
    }
    cout << "point total: " << point_total;

    return 0;
}
*/

/*
    keep a counter for the number of lines, make an integer vector for that number of lines, and put 1s in every place, then add iterations for every line as you go through the rows and find matching nums
*/

int main() {
    ifstream file;
    string line;
    int line_count = 0;
    vector<vector<int>> winning_nums;
    vector<vector<int>> player_nums;
    file.open("input.txt");
    while (getline(file, line)) {
        winning_nums.push_back(vector<int>());
        player_nums.push_back(vector<int>());
        stringstream ss;
        ss.str(line.substr(line.find(':') + 1, line.find('|') - line.find(':') - 1));
        int num;
        while (ss >> num) {
            winning_nums[line_count].push_back(num);
        }
        ss.clear();
        ss.str(line.substr(line.find('|') + 1));
        while (ss >> num) {
            player_nums[line_count].push_back(num);
        }
        line_count++;
    }
    vector<int> card(line_count, 1);
    int sum = 0;
    for (int i = 0; i < line_count; i++) {
        int winning_num_count = 0;
        for (int player_num : player_nums[i]) {
            if (find(winning_nums[i].begin(), winning_nums[i].end(), player_num) != winning_nums[i].end()) {
                winning_num_count++;
            }
        }
        int holder = card[i];
        while (holder > 0) {
            for (int j = 1; j <= winning_num_count; j++) {
                card[i + j]++;
            }
            holder--;
        }
        sum += card[i];
    }

    cout << sum << endl;

/*
    for (int i = 0; i < line_count; i++) {
        int carrier = card[i];
        cout << "hello?" << endl;
        while (carrier > 0) {
            for (int j = 1; j <= card_winner_count[i]; j++) {
                card[i + j]++;
            }
        }
        sum += card[i];
    }

    cout << "sum of card counts: " << sum << endl;
*/
    return 0;
}