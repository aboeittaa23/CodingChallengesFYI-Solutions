#include <iostream>

using namespace std;

enum TokenType
{
    END_OF_FILE,
    INT,
    STRING,
    OBJECT_START, // {
    OBJECT_END,   // }
    COLON,        // :
    COMMA,        // ,
};

struct Token
{
    TokenType type;
    string value;
};

class Tokenizer
{
private:
    Token token;
    string json;
    int position;

public:
    Tokenizer(const string &input) : json(input), position(0) {}

    Token getNextToken()
    {
        if (position >= json.size())
        {
            token.type = END_OF_FILE;
            token.value = "";
            return token;
        }

        Token token;
        char c = json[position];

        if (c == '{')
        {
            token.type = OBJECT_START;
            token.value = c;
            position++;
        }
        else if (c == '}')
        {
            token.type = OBJECT_END;
            token.value = c;
            position++;
        }
        else if (c == ',')
        {
            token.type = COMMA;
            token.value = c;
            position++;
        }
        else if (c == ':')
        {
            token.type = COLON;
            token.value = c;
            position++;
        }
        else if (isdigit(c))
        {
            token.type = INT;
            token.value = "";
            while (position < json.length() && isdigit(json[position]))
            {
                token.value += json[position];
                position++;
            }
        }
        return token;
    }
};