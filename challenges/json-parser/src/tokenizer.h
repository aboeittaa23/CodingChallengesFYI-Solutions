#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>

enum TokenType
{
    END_OF_FILE,
    INT,
    STRING,
    OBJECT_START, // {
    OBJECT_END,   // }
    COLON,        // :
    COMMA,        // ,
    OTHER
};

struct Token
{
    TokenType type;
    string value;
};

class Tokenizer
{
private:
    string json;
    int position;

public:
    Tokenizer(const string &input);

    Token getNextToken();
};

#endif