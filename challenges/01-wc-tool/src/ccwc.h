#ifndef CCWC_H
#define CCWC_H

#include <iostream>

class CCWC
{
public:
    CCWC();

    bool parseArgs(int argc, char *argv[]);

    void evaluate();

private:
    std::string filename;
    std::string readInput();
    std::string inputContent;

    size_t countBytes();
    size_t countLines();
    size_t countWords();
    size_t countChars();

    bool countBytesFlag;
    bool countLinesFlag;
    bool countWordsFlag;
    bool countCharsFlag;
    bool readFromInput;
};

#endif