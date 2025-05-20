#ifndef CCWC_H
#define CCWC_H

#include <iostream>

class CCWC
{
public:
    // Constructor
    CCWC();

    // Parse command line arguments
    bool parseArgs(int argc, char *argv[]);

    // Evaluate and output the results
    void evaluate();

private:
    std::string filename;

    size_t countBytes();
    size_t countLines();
    size_t countWords();
    size_t countChars();

    bool countBytesFlag;
    bool countLinesFlag;
    bool countWordsFlag;
    bool countCharsFlag;
};

#endif