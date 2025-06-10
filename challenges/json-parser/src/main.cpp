#include <iostream>
#include "tokenizer.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cerr << "Usage: " << argv[0] << " <json_file>" << endl;
		return 1;
	}

	string filename = argv[1];

	try
	{
		Tokenizer tokenizer;
		tokenizer.loadJSONFile(filename);

		cout << "Tokenizing: " << filename << endl;
		cout << "-------------------" << endl;

		Token token;
		while ((token = tokenizer.getNextToken()).type != END_OF_FILE)
		{
			if (token.type != OTHER)
			{
				cout << "Token Type: " << token.type
					 << ", Value: '" << token.value << "'" << endl;
			}
		}
	}
	catch (const exception &e)
	{
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
	return 0;
}