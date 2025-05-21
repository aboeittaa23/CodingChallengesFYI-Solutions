#include "ccwc.h"
#include <iostream>
#include <fstream>

using namespace std;

CCWC::CCWC()
{
    countBytesFlag = false;
    countLinesFlag = false;
    countWordsFlag = false;
    countCharsFlag = false;
}

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
        countBytesFlag = true;
    }
    if (arg == "-l")
    {
        countLinesFlag = true;
    }
    if (arg == "-w")
    {
        countWordsFlag = true;
    }
    if (arg == "-m")
    {
        countCharsFlag = true;
    }

    return true;
}

void CCWC::evaluate()
{

    if (countBytesFlag)
    {
        size_t byteCount = countBytes();
        cout << byteCount << " " << filename << endl;
    }
    if (countLinesFlag)
    {
        size_t lineCount = countLines();
        cout << lineCount << " " << filename << endl;
    }
    if (countWordsFlag)
    {
        size_t wordCount = countWords();
        cout << wordCount << " " << filename << endl;
    }
    if (countCharsFlag)
    {
        size_t charCount = countChars();
        cout << charCount << " " << filename << endl;
    }
}

size_t CCWC::countBytes()
{
    ifstream file(filename, ios::binary | ios::ate);

    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
    }

    return file.tellg();
}

size_t CCWC::countLines()
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
    }

    size_t lineCount{0};
    string line;
    while (getline(file, line))
    {
        lineCount++;
    }

    return lineCount;
}

size_t CCWC::countWords()
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return 0;
    }

    size_t wordCount{0};
    string word;
    while (file >> word)
    {
        wordCount++;
    }

    return wordCount;
}

size_t CCWC::countChars()
{

    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return 0;
    }

    size_t chars = 0;
    char c;
    while (file.get(c))
    {
        chars++;
    }

    return chars;
}
