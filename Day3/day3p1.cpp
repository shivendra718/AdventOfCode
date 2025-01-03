#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <algorithm> 
#include <regex>

using namespace std;

int main()
{
    string filename = "data.txt";
    ifstream file(filename);

    string line;
    int sum = 0;
    while(getline(file,line))
    {
        std::regex pattern(R"(mul\(([0-9]+),([0-9]+)\))");
        auto begin = std::sregex_iterator(line.begin(), line.end(), pattern);
        auto end = std::sregex_iterator();
        for (auto it = begin; it != end; ++it) 
        {
            std::smatch match = *it;
            string match1 = match.str();
            int num1 = std::stoi(match[1].str());
            int num2 = std::stoi(match[2].str());
            sum+= num1*num2;
        }
    }
    cout<<sum;
    return 0;
}