#ifndef CCWC_H
#define CCWC_H

#include <iostream>

class CCWC
{
public:
    CCWC();
    bool parseArgs(int argc, char *argv[]);

private:
    std::string filename;
    size_t countBytes();
};

#endif