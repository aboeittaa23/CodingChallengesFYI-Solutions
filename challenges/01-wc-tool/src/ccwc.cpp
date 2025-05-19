#include "ccwc.h"
#include <iostream>
#include <fstream>

using namespace std;

CCWC::CCWC() {}

bool CCWC::parseArgs(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " [-c] [-l] [-w] [-m] [filename]" << endl;
        return false;
    }

    string arg = argv[1];
    filename = argv[2];

    if (arg == "-c")
    {
        size_t byteCount = countBytes();
        cout << byteCount << " " << filename << endl;
    }

    return true;
}

size_t CCWC::countBytes()
{
    ifstream file(filename, std::ios::binary | std::ios::ate);

    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
    }

    return file.tellg();
}
