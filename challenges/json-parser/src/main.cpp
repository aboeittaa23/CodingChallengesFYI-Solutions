#include <iostream>
#include "tokenizer.h"

using namespace std;

int main()
{
	Tokenizer tokenizer;
	tokenizer.loadJSONFile("test.json");

	Token token;
	while ((token = tokenizer.getNextToken()).type != END_OF_FILE)
	{
		cout << "Token Type: " << token.type
			 << ", Value: '" << token.value << "'" << endl;
	}

	return 0;
}