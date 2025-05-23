#include "ccwc.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

CCWC::CCWC() : countBytesFlag(false),
               countLinesFlag(false),
               countWordsFlag(false),
               countCharsFlag(false),
               readFromInput(false)
{
}

bool CCWC::parseArgs(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " [-c] [-l] [-w] [-m] [filename]" << endl;
        return false;
    }

    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];

        if (arg == "-c")
        {
            countBytesFlag = true;
        }
        else if (arg == "-l")
        {
            countLinesFlag = true;
        }
        else if (arg == "-w")
        {
            countWordsFlag = true;
        }
        else if (arg == "-m")
        {
            countCharsFlag = true;
        }
        else
        {
            filename = arg;
        }

        readFromInput = filename.empty();
    }

    if (!countBytesFlag && !countLinesFlag && !countWordsFlag && !countCharsFlag)
    {
        countBytesFlag = true;
        countLinesFlag = true;
        countWordsFlag = true;
    }

    return true;
}

void CCWC::evaluate()
{
    if (countLinesFlag)
    {
        cout << countLines() << " ";
    }
    if (countWordsFlag)
    {
        cout << countWords() << " ";
    }
    if (countBytesFlag)
    {
        cout << countBytes() << " ";
    }
    if (countCharsFlag)
    {
        cout << countChars() << " ";
    }
    if (!readFromInput)
    {
        cout << filename;
    }
    cout << endl;
}

size_t CCWC::countBytes()
{
    if (readFromInput)
    {
        return 0;
    }
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

    locale::global(std::locale(""));

    wifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return 0;
    }

    file.imbue(locale(""));

    size_t chars = 0;
    wchar_t c;
    while (file.get(c))
    {
        chars++;
    }

    return chars;
}

string CCWC::readInput()
{
    stringstream buffer;
    buffer << cin.rdbuf();
    return buffer.str();
}
