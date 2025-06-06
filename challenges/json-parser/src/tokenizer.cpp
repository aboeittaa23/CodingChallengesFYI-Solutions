#include "tokenizer.h"
#include <iostream>

using namespace std;

Tokenizer::Tokenizer(const string &input)
    : json(input),
      position(0) {}

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
