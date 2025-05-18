#include "ccwc.h"

CCWC::CCWC() {}

bool CCWC::parseArgs(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " [-c] [-l] [-w] [-m] [filename]" << std::endl;
        return false;
    }
    return true;
}