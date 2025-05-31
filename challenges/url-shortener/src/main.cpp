#include "url_shortener.h"
#include <iostream>

using namespace std;

int main()
{
    UrlShortener shortener;
    string choice, url;

    cout << "URL Shortener\n";
    cout << "Commands: 'shorten' or 'expand' or 'quit'\n\n";

    while (true)
    {
        cout << "> ";
        cin >> choice;

        if (choice == "quit" || choice == "q")
        {
            break;
        }
        else if (choice == "shorten" || choice == "s")
        {
            cout << "Enter URL to shorten: ";
            cin >> url;
            string shortCode = shortener.shortenUrl(url);
            cout << "Short URL: " << shortCode << "\n\n";
        }
        else if (choice == "expand" || choice == "e")
        {
            cout << "Enter short code: ";
            cin >> url;
            string longUrl = shortener.expandUrl(url);
            if (longUrl.empty())
            {
                cout << "Short code not found!\n\n";
            }
            else
            {
                cout << "Original URL: " << longUrl << "\n\n";
            }
        }
        else
        {
            cout << "Unknown command. Use 'shorten', 'expand', or 'quit'\n\n";
        }
    }

    return 0;
}