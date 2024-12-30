#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <sstream>
#include <fstream>
#include <unordered_map>

using namespace std;

int findTotalDistanceList(std::vector<int>& col1, std::vector<int>& col2)
{
    sort(col1.begin(), col1.end());
    sort(col2.begin(), col2.end());
    std::vector<int>result(col1.size());
    std::unordered_map<int,int>countMap;
    int similarityIndex = 0;
    int output = 0;

    if (col1.size() == col2.size())
    {
        for (int i = 0; i < col1.size(); i++)
        {
            result[i] = abs(col1[i] - col2[i]);
        }
    }

    for (int num:col2)
    {
        countMap[num]++;
    }

    for (int num:col1)
    {
        int count = countMap[num];
        similarityIndex += num*count;
    }

    for (int i = 0; i < result.size(); i++)
    {
        output += result[i];
    }
    return similarityIndex;
}

int main()
{
    string filename = "data.txt";
    std::vector<int> column1;
    std::vector<int> column2;
    std::ifstream file(filename);
    string line;
    while (getline(file,line))
    {
        std::istringstream lineStream(line);
        int num1, num2;
        if (lineStream >> num1 >> num2) { // Extract two integers from each line
            column1.push_back(num1);
            column2.push_back(num2);
        }
    }
    file.close();

    int result = findTotalDistanceList(column1,column2);


    
    return 0;
}
