#include "tokenizer.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Tokenizer::Tokenizer()
    : json(""),
      position(0) {}

void Tokenizer::loadJSONFile(const string &filename)
{
    reset();

    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    json = buffer.str();
}

Token Tokenizer::getNextToken()
{
    if (position >= json.size())
    {
        return Token{END_OF_FILE, ""};
    }

    Token token;
    char c = json[position];

    if (c == '{')
    {
        token = {OBJECT_START, string(1, c)};
    }
    else if (c == '}')
    {
        token = {OBJECT_END, string(1, c)};
    }
    else if (c == ',')
    {
        token = {COMMA, string(1, c)};
    }
    else if (c == ':')
    {
        token = {COLON, string(1, c)};
    }
    else if (isdigit(c))
    {
        token.type = INT;
        while (position < json.length() && isdigit(json[position]))
        {
            token.value += json[position];
            position++;
        }
        return token;
    }
    else
    {
        token = {OTHER, string(1, c)};
    }
    position++;
    return token;
}

void Tokenizer::reset()
{
    json = "";
    position = 0;
}
