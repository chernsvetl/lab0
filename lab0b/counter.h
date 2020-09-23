#pragma once

#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

class Counter
{
    std::map <std::string, int> wordCount;
    int totalRead = 0;

public:
    void read(std::string &input);

    void sortAndWrite(std::string &output);
};

