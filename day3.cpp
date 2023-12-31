#include <fstream>
#include <vector>
#include <iostream>
#include <tuple>
#include <map>
#include <set>

using namespace std;

int main() {
    vector<vector<char>> matrix;

    ifstream file;
    string line;
    file.open("input.txt");

    while (getline(file, line)) {
        vector<char> a_line;
        for (char c : line) {
            a_line.push_back(c);
        }
        matrix.push_back(a_line);
    }

    int r = matrix.size();
    int c = matrix[0].size();
    set<tuple<int, int>> coords;
    multimap<tuple<int, int>, int> known_gears;
    set<tuple<int, int>> iter_coords;
    int p1 = 0;
    int p2 = 0;

    for (int i = 0; i < r; i++) {
        int n = 0;
        bool has_part_num = false;
        for (int j = 0; j <= c; j++) {  // Notice the change here
            if (j < c && isdigit(matrix[i][j])) {
                n = n * 10 + (matrix[i][j] - '0');
                for (int rr = -1; rr <= 1; rr++) {
                    for (int cc = -1; cc <= 1; cc++) {
                        if (0 <= i + rr && i + rr < r && 0 <= j + cc && j + cc < c) {
                            char ch = matrix[i + rr][j + cc];
                            if (!isdigit(ch) && ch != '.') {
                                has_part_num = true;
                            }
                            if (ch == '*') {
                                coords.insert(make_tuple(i + rr, j + cc));
                            }
                        }
                    }
                }
            }
            else {
                if (n > 0 && has_part_num) {
                    p1 += n;
                }
                for (tuple<int, int> t : coords) {
                    known_gears.insert(make_pair(t, n));
                    iter_coords.insert(t);
                }
                n = 0;
                has_part_num = false;
                coords.clear(); 
            }
        }
    }
    for (tuple<int, int> t : iter_coords) {
        auto range = known_gears.equal_range(t);
        int count = distance(range.first, range.second);
        if (count == 2) {
            p2 += range.first->second * next(range.first)->second;
        }
    }

    //cout << p1 << endl;
    cout << p2 << endl;

    return 0;
}