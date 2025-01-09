#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <algorithm> 

bool dfs(std::vector<std::vector<char>>& allRows, const std::string& word, int i, int j, int index, int dx, int dy) {
    if (index == word.size()) {
        return true;
    }
    int m = allRows.size();
    int n = allRows[0].size();

    if (i < 0 || i >= m || j < 0 || j >= n || allRows[i][j] != word[index]) {
        return false;
    }

    // Move in the current direction
    return dfs(allRows, word, i + dx, j + dy, index + 1, dx, dy);
}

int countOccurrences(std::vector<std::vector<char>>& allRows, const std::string& word) {
    int count = 0;
    int m = allRows.size();
    int n = allRows[0].size();
    std::vector<std::pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (allRows[i][j] == word[0]) {
                for (auto& dir : directions) {
                    if (dfs(allRows, word, i, j, 0, dir.first, dir.second)) {
                        ++count;
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    std::string filename = "data.txt";
    std::ifstream file(filename);
    std::vector<std::vector<char> > allRows;
    std::string line;
    while(getline(file,line))
    {
        std::stringstream ss(line);
        char character;
        std::vector<char> row;

        while(ss >> character)
        {
            row.push_back(character);
        }
        allRows.push_back(row);
    }
    file.close();
    int count = countOccurrences(allRows,"XMAS");
    return 0;
}
