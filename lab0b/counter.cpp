
#include "counter.h"

bool compare(std::pair <std::string, int> &a, std::pair <std::string, int> &b) {
    return a.second > b.second;
}

bool isLetter(char c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

bool isDigit(char c) {
    return ( '0' <= c && c <= '9');
}

void Counter::read(std::string &input) {
    std::ifstream fileIn(input);
    if (!fileIn) {
        throw std::invalid_argument("Input file not found!");
    }

    std::string str;
    std::string BuffStr;

    while (getline(fileIn, str)) {
        for (int i = 0; i < str.size(); i++) {
            char curSymbol = str[i];
            if (isLetter(curSymbol) || isDigit(curSymbol)) {
                BuffStr += curSymbol;
            } else if (!BuffStr.empty()) {
                wordCount[BuffStr]++;
                BuffStr = "";
                totalRead++;
            }
        }

        if (!BuffStr.empty()) {
            wordCount[BuffStr]++;
            BuffStr = "";
            totalRead++;
        }
    }

    fileIn.close();
}

void Counter::sortAndWrite(std::string &output) {
    std::vector < std::pair <std::string, int> > sortedByValue;

    std::map <std::string, int> :: iterator going;

    for (going = wordCount.begin(); going != wordCount.end(); going++) {
        std::pair <std::string, int> curPair {going -> first, going -> second};
        sortedByValue.push_back(curPair);
    }

    std::sort(sortedByValue.begin(), sortedByValue.end(), compare);

    std::ofstream fileOut(output);
    if (!fileOut) {
        throw std::invalid_argument("Output file not found!");
    }

    for (int i = 0; i < sortedByValue.size(); i++) {
        fileOut << sortedByValue[i].first << ", " << sortedByValue[i].second << ", ";
        double percentPerWord = 100.00 * sortedByValue[i].second / totalRead;
        fileOut << percentPerWord << std::endl;
    }

    fileOut.close();
}

