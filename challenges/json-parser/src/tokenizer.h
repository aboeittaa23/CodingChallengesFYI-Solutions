#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>

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
    std::string value;
};

class Tokenizer
{
private:
    std::string json;

    size_t position;

    void reset();

public:
    Tokenizer();

    Token getNextToken();

    void loadJSONFile(const std::string &filename);
};

#endif