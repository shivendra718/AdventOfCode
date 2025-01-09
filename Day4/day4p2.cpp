#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

// Function to check if the "X-MAS" pattern is found at position (i, j)

bool checkXMASPattern(std::vector<std::vector<char>>& allRows, int i, int j) {
    int m = allRows.size();
    int n = allRows[0].size();

    bool countFlagRight = false;
    bool countFlagLeft = false;

    // Ensure indices are within bounds for checking the pattern
    if (i - 1 >= 0 && i + 1 < m && j - 1 >= 0 && j + 1 < n) {
        if (allRows[i][j] == 'A' &&
            (allRows[i - 1][j - 1] == 'M' && allRows[i + 1][j + 1] == 'S' ||
            allRows[i - 1][j-1] == 'S' && allRows[i + 1][j+1] == 'M')) {
            countFlagRight = true;
        }
        if (allRows[i][j] == 'A' &&
            (allRows[i - 1][j + 1] == 'M' && allRows[i + 1][j - 1] == 'S' ||
            allRows[i - 1][j+1] == 'S' && allRows[i + 1][j-1] == 'M')) {
            countFlagLeft = true;
        }
    }
    return countFlagRight && countFlagLeft;
}

// Function to count occurrences of "X-MAS" pattern
int countXMAS(std::vector<std::vector<char>>& allRows) {
    int count = 0;
    int m = allRows.size();
    int n = allRows[0].size();

    // Iterate through the grid to find all occurrences of the "X-MAS" pattern
    for (int i = 1; i < m - 1; i++) { // Avoid the boundaries
        for (int j = 1; j < n - 1; j++) { // Avoid the boundaries
            if (checkXMASPattern(allRows, i, j)) {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    // Read the grid from the file
    std::string filename = "data.txt";
    std::ifstream file(filename);
    std::vector<std::vector<char>> allRows;
    std::string line;

    // Read each line from the file and convert it into a 2D character grid
    while (getline(file, line)) {
        std::stringstream ss(line);
        char character;
        std::vector<char> row;

        while (ss >> character) {
            row.push_back(character);
        }
        allRows.push_back(row);
    }
    file.close();

    // Count and print the number of "X-MAS" patterns
    int count = countXMAS(allRows);
    return 0;
}
