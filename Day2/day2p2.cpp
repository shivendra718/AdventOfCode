#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <algorithm> 

using namespace std;

int FindIfSafeOrNot(std::vector<std::vector<int> >& allRows)
{
    int count = 0;
    unordered_map<int,int> diffMap;

    for (auto& row : allRows)
    {
        if (row.size() < 2)
        {
            continue;
        }
        bool isIncreasing = true;
        bool isDecreasing = true;
        for (int j = 0; j < row.size()-1; j++)
        {
            int diff = row[j] - row[j+1];

            if (diff < -3 || diff > 3)
            {
                isIncreasing = false;
                isDecreasing = false;
                break;
            }
            if (diff > 0)
            {
                isDecreasing = false;
            }
            else if (diff < 0)
            {
                isIncreasing = false;
            }
            else if (diff == 0)
            {
                isIncreasing = false;
                isDecreasing = false;
            }
        }

        if (isIncreasing || isDecreasing)
        {
            count++;
            continue;
        }

        bool canBeMadeSafe = false;
        for (int i = 0; i < row.size(); i++)
        {
            std::vector<int> modifiedRow = row;
            modifiedRow.erase(modifiedRow.begin() + i);

            bool isModifiedIncreasing = true;
            bool isModifiedDecreasing = true;

            for (int j = 0; j < modifiedRow.size() - 1; j++)
            {
                int diff = modifiedRow[j] - modifiedRow[j + 1];

                if (diff < -3 || diff > 3)
                {
                    isModifiedIncreasing = false;
                    isModifiedDecreasing = false;
                    break;
                }
                if (diff > 0)
                {
                    isModifiedDecreasing = false;
                }
                else if (diff < 0)
                {
                    isModifiedIncreasing = false;
                }
                else if (diff == 0)
                {
                    isModifiedIncreasing = false;
                    isModifiedDecreasing = false;
                }
            }

            if (isModifiedIncreasing || isModifiedDecreasing)
            {
                canBeMadeSafe = true;
                break;
            }
        }

        if (canBeMadeSafe)
        {
            count++;
        }
    }  
    
    return count;
}

int main()
{
    string filename = "data.txt";
    ifstream file(filename);
    std::vector<std::vector<int> > allRows;
    string line;
    while(getline(file,line))
    {
        stringstream ss(line);
        int num;
        std::vector<int> row;

        while(ss >> num)
        {
            row.push_back(num);
        }
        allRows.push_back(row);
    }
    file.close();

    int output = FindIfSafeOrNot(allRows);

    return 0;
}