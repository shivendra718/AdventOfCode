#include <iostream>
#include <regex>
#include <string>
#include <fstream>

int main() {
    std::ifstream file("data.txt");
    std::string line;
    long long sum = 0;
    bool processing = true;  // At the beginning, processing is enabled

    // Combined regex pattern to match all relevant tokens
    std::regex pattern(R"(don't\(\)|do\(\)|mul\((\d+),(\d+)\))");

    while (getline(file, line)) {
        auto begin = std::sregex_iterator(line.begin(), line.end(), pattern);
        auto end = std::sregex_iterator();

        for (auto it = begin; it != end; ++it) {
            std::smatch match = *it;

            if (match.str() == "don't()") {
                processing = false;
            } else if (match.str() == "do()") {
                processing = true;
            } else if (processing && match.size() == 3) {  // A valid mul(...) match
                int num1 = std::stoi(match[1].str());
                int num2 = std::stoi(match[2].str());
                sum += num1 * num2;
            }
        }
    }

    std::cout <<sum;
    return 0;
}


